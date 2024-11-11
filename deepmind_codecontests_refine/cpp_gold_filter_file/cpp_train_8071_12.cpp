#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f, maxn = 100000 + 5, mod = 1000000000 + 7;
using namespace std;
map<char, int> m;
char s[maxn];
int a[70];
int main() {
  memset(a, 0, sizeof(a));
  for (int i = 0; i <= 63; i++) {
    for (int j = 0; j <= 63; j++) {
      a[i & j]++;
    }
  }
  for (int i = 1; i <= 63; i++) {
    if (i < 10) {
      m['0' + i] = i;
    } else if (i >= 10 && i <= 35) {
      m[i - 10 + 'A'] = i;
    } else if (i >= 36 && i <= 61) {
      m[i - 36 + 'a'] = i;
    } else if (i == 62) {
      m['-'] = i;
    } else
      m['_'] = i;
  }
  while (cin >> s) {
    long long ans = 1;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
      ans = ans * a[m[s[i]]] % mod;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
