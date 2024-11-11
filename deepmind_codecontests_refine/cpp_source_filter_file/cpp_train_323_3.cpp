#include <bits/stdc++.h>
using namespace std;
long long n, p, vr[20][20], cr[100005][20];
char str[100005];
bool visit[(1 << 17)][17][17], inv[100005];
long long dp[(1 << 17)], occ[200005], tr[400555];
void build(long long, long long, long long),
    ss(long long, long long, long long);
long long query(long long, long long, long long, long long, long long),
    func(long long);
int main() {
  scanf("%lld %lld", &n, &p);
  scanf(" %s", str);
  for (int i = 0; i < n; i++) occ[1 << (str[i] - 'a')]++;
  for (int i = 0; i < p; i++) {
    for (int j = 0; j < p; j++) scanf("%lld", &vr[i][j]);
  }
  build(0, 0, n - 1);
  for (int i = 0; i < p; i++) {
    long long pos = -1;
    for (int j = n - 1; j >= 0; j--) {
      if (pos != -1 && vr[str[j] - 'a'][str[pos] - 'a'] == 0) {
        long long x = query(0, 0, n - 1, j + 1, pos - 1);
        if ((x & (1 << (str[j] - 'a'))) == 0) {
          ss(query(0, 0, n - 1, j + 1, pos - 1), min(str[j], str[pos]) - 'a',
             max(str[j], str[pos]) - 'a');
        }
      }
      if (str[j] == 'a' + i) pos = j;
    }
  }
  memset(dp, -1, sizeof(dp));
  cout << n - func(0);
}
void ss(long long mask, long long a, long long b) {
  if (visit[mask][a][b]) return;
  visit[mask][a][b] = 1;
  inv[mask] = 1;
  long long unset = ((1 << p) - 1) ^ mask;
  for (; unset; unset -= (unset & (-unset))) {
    long long bit = (unset & -unset);
    if (bit != (1 << a) && bit != (1 << b)) {
      ss(mask | bit, a, b);
    }
  }
}
long long func(long long mask) {
  if (dp[mask] != -1) return dp[mask];
  if (inv[mask]) return -1000000;
  long long max_ = 0;
  long long unset = ((1 << p) - 1) ^ mask;
  for (; unset; unset -= (unset & -unset)) {
    long long bit = (unset & -unset);
    max_ = max(max_, func(mask | bit) + occ[bit]);
  }
  return dp[mask] = max_;
}
long long query(long long idx, long long l, long long r, long long low,
                long long high) {
  if (low <= l && r <= high) return tr[idx];
  if (r < low || high < l) return 0;
  long long mid = (l + r) / 2;
  return query(2 * idx + 1, l, mid, low, high) |
         query(2 * idx + 2, mid + 1, r, low, high);
}
void build(long long idx, long long l, long long r) {
  if (l == r) {
    tr[idx] = (1 << (str[l] - 'a'));
    return;
  }
  long long mid = (l + r) / 2;
  build(2 * idx + 1, l, mid);
  build(2 * idx + 2, mid += 1, r);
  tr[idx] = (tr[2 * idx + 1] | tr[2 * idx + 2]);
}
