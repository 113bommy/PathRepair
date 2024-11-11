#include <bits/stdc++.h>
using namespace std;
int n, m, res;
string s[15];
int c[15], x[15];
void Solve(int i, int ifmatch) {
  if (i == n) {
    if (ifmatch != c[1]) return;
    string t;
    for (int j = 0; j <= n - 1; j++) {
      t += (char)x[j] + 48;
    }
    int Ok = 1;
    for (int j = 2; j <= m; j++) {
      int CC = 0;
      for (int l = 0; l <= n - 1; l++) {
        if (s[j][l] == t[l]) CC++;
      }
      if (CC == c[j]) Ok++;
    }
    if (Ok == m) res++;
    return;
  }
  x[i] = (int)(s[1][i] - 48) ^ 1;
  Solve(i + 1, ifmatch);
  if (ifmatch < c[1]) {
    x[i] = (int)s[1][i] - 48;
    Solve(i + 1, ifmatch + 1);
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> s[i] >> c[i];
  }
  Solve(0, 0);
  cout << res;
}
