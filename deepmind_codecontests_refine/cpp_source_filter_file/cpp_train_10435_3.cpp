#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int N = 2e5 + 10;
int n, m, a[26], pos[26];
char s[N], t[N];
bitset<N> ch[26], ans;
int main() {
  for (int i = 0; i < 26; ++i) scanf("%d", a + i), pos[a[i] - 1] = i;
  scanf("%s%s", s, t);
  n = strlen(s), m = strlen(t);
  for (int i = 0; i < m; ++i) {
    t[i] -= 'a';
    ch[t[i]].set(i);
    ch[pos[t[i]]].set(i);
  }
  ans.set();
  for (int i = 0; i < n; ++i) ans &= ch[s[i] - 'a'] >> i;
  for (int i = 0; i < m - n + 1; ++i) putchar(ans[i]);
  puts("");
}
