#include <bits/stdc++.h>
using namespace std;
const int Mod = 1000003;
const int MaxLen = 2000 + 5;
char s[MaxLen];
int cnt, v[MaxLen], f[MaxLen][MaxLen], p[MaxLen][MaxLen], sum[MaxLen];
int main() {
  gets(s + 1);
  s[0] = '#';
  memset(sum, 0, sizeof(sum));
  cnt = 1;
  memset(v, 0, sizeof(v));
  for (int i = 1; s[i]; ++i) {
    if ((s[i] == '*' || s[i] == '/') && !isdigit(s[i - 1])) {
      puts("0");
      return 0;
    }
    if (isdigit(s[i]) && !isdigit(s[i - 1])) {
      if (cnt) sum[cnt] = sum[cnt - 1] + v[cnt];
      cnt++;
    }
    if (!isdigit(s[i])) v[cnt]++;
  }
  if (!isdigit(s[strlen(s) - 1])) {
    puts("0");
    return 0;
  }
  memset(f, 0, sizeof(f));
  memset(p, 0, sizeof(p));
  f[0][0] = p[0][0] = 1;
  for (int i = 1; i < cnt; ++i)
    for (int j = sum[i]; j >= 0; --j) {
      f[i][j] = (f[i][j] + p[i - 1][max(j - v[i], 0)]) % Mod;
      p[i][j] = (p[i][j + 1] + f[i][j]) % Mod;
    }
  cout << f[cnt - 1][0] << endl;
  return 0;
}
