#include <bits/stdc++.h>
using namespace std;
char s[1000010], fs[1000010], rs[1000010];
int cd[10], f[10];
int main() {
  int i, j, d[4] = {1, 6, 8, 9}, k;
  cin >> s;
  k = strlen(s);
  for (int kk = 0; kk <= 6; kk++)
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        if (i == j) continue;
        for (int g = 0; g < 4; g++) {
          if (g == i || g == j) continue;
          for (int o = 0; o < 4; o++) {
            if (o == i || o == j || o == g) continue;
            int x = kk * 10000 + d[i] * 1000 + d[j] * 100 + d[g] * 10 + d[o];
            int ss = d[i] * 1000 + d[j] * 100 + d[g] * 10 + d[o];
            if (x % 7 == 0) cd[kk] = ss;
          }
        }
      }
    }
  int td = 0;
  for (i = 0; i < 4; i++) f[d[i]] = 1;
  int ss = 4, g = 0;
  for (i = 0; i < k; i++) {
    if (f[s[i] - '0']) {
      f[s[i] - '0']--;
      ss--;
      continue;
    }
    fs[g++] = s[i];
  }
  fs[g] = '\0';
  for (i = 0; i < g; i++) {
    int x = td * 10 + fs[i] - '0';
    td = x % 7;
  }
  if (ss != 0)
    cout << "0\n";
  else {
    for (i = 0; i < g; i++)
      if (fs[i] == '0')
        rs[i] = fs[i];
      else
        break;
    rs[i] = '\0';
    for (j = i; j < g; j++) cout << fs[i];
    cout << cd[td] << rs << endl;
  }
  return 0;
}
