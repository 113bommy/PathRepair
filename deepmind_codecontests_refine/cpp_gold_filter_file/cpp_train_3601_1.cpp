#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
int gi() {
  int w = 0;
  bool q = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') q = 0, c = getchar();
  while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
  return q ? w : -w;
}
long long ins[N], del[N];
pair<int, int> p[N];
int main() {
  int m = gi(), n = gi(), i, l, r;
  long long x, L = 0, R = 0, pre = 0, ans = 0, all = 0, d = 0;
  map<long long, long long> sum, cnt;
  srand(31);
  for (i = 1; i <= m; i++) {
    l = p[i].first = gi(), r = p[i].second = gi();
    x = (((long long)rand() << 15 | rand()) << 15 | rand()) << 15 | rand();
    R ^= x;
    del[l] ^= x;
    ins[r + 1] ^= x;
    all ^= x;
  }
  sum[0] = 0;
  cnt[0] = 1;
  for (i = 1; i <= n; i++) {
    d ^= ins[i] ^ del[i];
    pre ^= d;
    R ^= del[i];
    ans += i * cnt[all ^ R ^ pre] - sum[all ^ R ^ pre];
    L ^= ins[i + 1];
    cnt[pre ^ L]++, sum[pre ^ L] += i;
  }
  sort(p + 1, p + 1 + m);
  p[++m] = make_pair(n + 1, n + 1);
  for (i = 1, r = 0; i <= m; r = max(r, p[i++].second))
    if (p[i].first > r)
      for (x = r + 1; x < p[i].first; x++) ans -= (x - r) * (p[i].first - x);
  cout << ans << endl;
  return 0;
}
