#include <bits/stdc++.h>
using namespace std;
const int MAXN = 8e5 + 10, MAXM = 1e7 + 10;
const int INF = INT_MAX, SINF = 0x3f3f3f3f;
const long long llINF = LLONG_MAX;
const int MOD = 1e9 + 7, mod = 998244353;
const int inv2 = 5e8 + 4;
long long n, m, pos[MAXN], dir[MAXN], st[MAXN], ans[MAXN];
long long t;
char s[2];
int main() {
  scanf("%lld%lld%lld", &n, &m, &t);
  for (int i = 0; i < n; i++) {
    scanf("%lld%s", &pos[i], s);
    pos[i]--;
    st[i] = i;
    if (s[0] == 'L')
      dir[i] = -1;
    else
      dir[i] = 1;
  }
  sort(st, st + n, [&](long long a, long long b) { return pos[a] < pos[b]; });
  int offset = 0;
  for (int i = 0; i < n; i++) {
    if (dir[i] == 1)
      (offset -= ((pos[i] + t) / m)) %= n;
    else
      (offset -= ((pos[i] - t - m + 1) / m)) %= n;
    (offset += n) %= n;
    (pos[i] += dir[i] * t % m + m) %= m;
  }
  rotate(st, st + offset, st + n);
  sort(pos, pos + n);
  for (int i = 0; i < n; i++) ans[st[i]] = pos[i] + 1;
  for (int i = 0; i < n; i++) printf("%lld ", ans[i]);
  return 0;
}
