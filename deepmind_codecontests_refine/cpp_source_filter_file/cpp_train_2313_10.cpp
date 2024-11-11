#include <bits/stdc++.h>
using namespace std;
const int MN = 6e5 + 5, M = 1 << 30;
const long long mod = 1e18;
map<int, int> cnt;
int N, w[MN], fail[MN], anc[MN], st[MN], top;
long long res;
char s[MN];
struct BigInt {
  long long a, b;
  inline void operator+=(const long long &x) {
    if ((b += x) >= mod) b -= mod, ++a;
  }
  inline void output() {
    if (a)
      printf("%lld%018lld\n", a, b);
    else
      printf("%lld\n", b);
  }
  inline int val(int P) { return (a * (mod % P) + b) % P; }
} ans;
int main() {
  scanf("%d", &N);
  for (int i = 1, j = 0; i <= N; ++i) {
    scanf("%s%d", s + i, &w[i]);
    s[i] = (s[i] - 'a' + ans.val(26)) % 26 + 'a';
    w[i] ^= ans.val(M) & (M - 1);
    anc[i - 1] = s[fail[i - 1] + 1] == s[i] ? anc[fail[i - 1]] : fail[i - 1];
    while (j && s[j + 1] != s[i]) j = fail[j];
    if (i > 1 && s[j + 1] == s[i]) ++j;
    fail[i] = j;
    for (int now = i - 1, val; now;)
      if (s[now + 1] == s[i])
        now = anc[now];
      else
        val = w[*lower_bound(st + 1, st + top + 1, i - now)],
        (--cnt[val] == 0) ? cnt.erase(val) : 0, res -= val, now = fail[now];
    while (top && w[st[top]] > w[i]) --top;
    st[++top] = i;
    if (s[i] == s[1]) ++cnt[w[i]], res += w[i];
    for (auto it = cnt.upper_bound(w[i]), nxt = it; it != cnt.end();
         ++it, cnt.erase(nxt), nxt = it)
      cnt[w[i]] += it->second, res -= it->second * (it->first - w[i]);
    ans += res;
    ans.output();
  }
  return 0;
}
