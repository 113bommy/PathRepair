#include <bits/stdc++.h>
using namespace std;
const long long mod = (long long)(1e9 + 7);
long long modpow(long long a, long long b) {
  if (!b) return 1;
  a %= mod;
  return modpow(a * a % mod, b / 2) * (b & 1 ? a : 1) % mod;
}
const int N = 1e5, H = 20;
int n;
int t[2 * N], d[2 * N];
void build(int arr[]) {
  memset(t, 0, sizeof(t));
  memset(d, 0, sizeof(d));
  for (int i = 1; i <= n; i++) t[n + i] = arr[i - 1];
  for (int i = n - 1; i > 0; i--) t[i] = t[i << 1] + t[i << 1 | 1];
}
void rebuild(int p) {
  while (p > 1) p >>= 1, t[p] = max(t[p << 1], t[p << 1 | 1]) + d[p];
}
void apply(int p, int value) {
  t[p] += value;
  if (p < n) d[p] += value;
}
void push(int p) {
  for (int s = H; s > 0; s--) {
    int i = p >> s;
    if (d[i]) {
      apply(i << 1, d[i]);
      apply(i << 1 | 1, d[i]);
      d[i] = 0;
    }
  }
}
void modify(int l, int r, int value) {
  if (l >= r) return;
  int l0 = (l += n), r0 = (r += n);
  for (; l < r; l >>= 1, r >>= 1) {
    if (l & 1) apply(l++, value);
    if (r & 1) apply(--r, value);
  }
  rebuild(l0);
  rebuild(r0 - 1);
}
int query(int l, int r) {
  l += n;
  r += n;
  push(l);
  push(r - 1);
  int ans = 0;
  for (; l < r; l >>= 1, r >>= 1) {
    if (l & 1) ans = max(ans, t[l++]);
    if (r & 1) ans = max(ans, t[--r]);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int k;
  scanf("%d", &n);
  scanf("%d", &k);
  int dp[k][n];
  int arr[n];
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  int last[n];
  map<int, int> lastnumber;
  for (int i = 0; i < n; i++) {
    if (lastnumber.count(arr[i]))
      last[i] = lastnumber[arr[i]];
    else
      last[i] = -1;
    lastnumber[arr[i]] = i;
  }
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) dp[0][i] = dp[0][i - 1] + (last[i] == -1);
  for (int x = 1; x <= k - 1; x++) {
    build(dp[x - 1]);
    for (int i = 0; i < n; i++) {
      modify(last[i] + 1, i + 1, 1);
      dp[x][i] = query(0, i);
    }
  }
  cout << dp[k - 1][n - 1] << endl;
  return 0;
}
