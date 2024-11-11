#include <bits/stdc++.h>
using namespace std;
int main() {
  int f[200];
  char s[20];
  f['R'] = 0, f['O'] = 1, f['Y'] = 2, f['G'] = 3, f['B'] = 4, f['V'] = 5;
  int v[10] = {0}, t = 0, ma = 1;
  gets(s);
  for (int i = 0; i < 6; i++) v[f[s[i]]] += 1;
  for (int i = 0; i < 6; i++) {
    t += (v[i] > 0);
    ma = ma > v[i] ? ma : v[i];
  }
  if (t == 1) puts("1");
  if (t == 2) {
    if (ma == 5)
      puts("1");
    else
      puts("2");
  }
  if (t == 3) {
    if (ma == 4)
      puts("2");
    else if (ma == 3)
      puts("3");
    else
      puts("5");
  }
  if (t == 4) {
    if (ma == 3)
      puts("5");
    else if (ma == 2)
      puts("8");
  }
  if (t == 5) puts("15");
  if (t == 6) puts("30");
  return 0;
}
