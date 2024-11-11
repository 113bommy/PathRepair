#include <bits/stdc++.h>
using namespace std;
const int N = 1 + 3e3, MOD = 998244353;
char s[N], spell[2 * N];
int v[N], nS;
int progress(int* v, int nS, char* spell, char c, int n) {
  for (int i = 0; spell[i]; i++) {
    if (c != spell[i + n] && spell[i + n]) {
      v[i] = 0;
    }
    if (c == spell[i]) {
      v[i] = (v[i] + v[i + 1]) % MOD;
    }
  }
  v[nS] = (v[nS] << 1) % MOD;
  if (0) {
    for (int i = 0; i <= nS; i++) {
      printf("%d ", v[i]);
    }
    puts("");
  }
  return !spell[n + 1] ? v[0] : 0;
}
int main() {
  scanf("%s%s", s, spell);
  int nS = strlen(spell);
  for (int i = 0; i <= nS; i++) {
    v[i] = 1;
  }
  long long ans = 0;
  for (int i = 0; s[i]; i++) {
    ans += progress(v, nS, spell, s[i], i);
  }
  printf("%d\n", ans % MOD);
  return 0;
}
