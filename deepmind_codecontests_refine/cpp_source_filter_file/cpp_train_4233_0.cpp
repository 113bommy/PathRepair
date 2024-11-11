#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9 + 7;
const int N = 100010;
const int M = N << 1;
pair<int, int> a[N], b[N];
int loc[M], pre[2][M];
int dif = 0;
long long f[M], inv[2][M];
long long ksm(long long a, int b) {
  long long ans = 1;
  for (; b > 0; b >>= 1, a = a * a % oo)
    if (b & 1) ans = ans * a % oo;
  return ans;
}
int work(pair<int, int> *s, int tot) {
  int l, r;
  for (int i = 1; i <= tot; ++i) {
    scanf("%d%d", &l, &r);
    s[i] = {l - 1, r};
  }
  sort(s + 1, s + tot + 1);
  int cnt = 0;
  s[0] = {-1, -1};
  for (int i = 1; i <= tot; ++i) {
    if (s[i].first == s[i - 1].first) continue;
    while (cnt && s[i].second <= s[cnt].second) --cnt;
    s[++cnt] = s[i];
    loc[++dif] = s[i].first;
    loc[++dif] = s[i].second;
  }
  return cnt;
}
int find(int x) {
  int l = 0, r = dif;
  while (l != r) {
    int mid = (l + r) >> 1;
    if (loc[mid] >= x)
      r = mid;
    else
      l = mid + 1;
  }
  return l;
}
void locate(pair<int, int> *s, int tot, int x) {
  memset(pre[x], -1, sizeof(pre[x][0]) * (dif + 5));
  for (int i = 1; i <= tot; ++i) pre[x][find(s[i].second)] = find(s[i].first);
}
int main() {
  int k, m, n, len = 0;
  scanf("%d%d%d", &k, &n, &m);
  n = work(a, n);
  m = work(b, m);
  sort(loc + 1, loc + dif + 1);
  loc[++dif] = k;
  for (int i = 1; i <= dif; ++i)
    if (loc[i] != loc[i - 1]) loc[++len] = loc[i];
  dif = len;
  locate(a, n, 0);
  locate(b, m, 1);
  f[0] = 1;
  for (int i = 1; i <= dif; ++i) {
    f[i] = f[i - 1] * ksm(2, loc[i] - loc[i - 1]);
    for (int x = 0; x < 2; ++x) {
      inv[x][i] = inv[x][i - 1];
      if (pre[x][i] != -1) {
        int last = pre[x][i];
        inv[x][i] = (inv[x][last] + f[last]) % oo;
        f[i] -= inv[x][i] - inv[x][i - 1];
      }
    }
    f[i] %= oo;
  }
  printf("%lld\n", (f[dif] + oo) % oo);
  return 0;
}
