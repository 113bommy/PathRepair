#include <bits/stdc++.h>
using namespace std;
#pragma GCC("Ofast")
const int mm = 105, mod = 1e9 + 7;
int f[mm][25 * mm];
string s;
void nhap() {
  for (int i = 0; i < 26; i++) f[1][i] = 1;
  for (int i = 1; i < 100; i++)
    for (int j = 0; j <= 2500; j++)
      if (f[i][j])
        for (int k = 0; k < 26; k++)
          f[i + 1][j + k] = (f[i + 1][j + k] + f[i][j]) % mod;
}
void xuli() {
  int t;
  scanf("%d\n", &t);
  while (t--) {
    getline(cin, s);
    int to = 0;
    for (int i = 0; i < s.size(); i++) to += s[i] - 'a';
    printf("%d\n", (f[s.size()][to] - 1 + mod) % mod);
  }
}
int main() {
  nhap();
  xuli();
}
