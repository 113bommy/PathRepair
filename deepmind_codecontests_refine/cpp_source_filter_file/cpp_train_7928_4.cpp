#include <bits/stdc++.h>
using namespace std;
int tab[30][100009];
int tac[30];
string second, s1;
int main() {
  ios_base::sync_with_stdio(false);
  int n, m, a, b, c, d;
  cin >> n >> second;
  for (int i = 0; i < second.size(); i++) tab[second[i] - 'a'][i + 1]++;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= 28; j++) tab[j][i] += tab[j][i - 1];
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> s1;
    for (int j = 0; j <= 28; j++) tac[j] = 0;
    for (int j = 0; j < s1.size(); j++) tac[s1[j] - 'a']++;
    a = 1;
    b = n;
    while (a < b) {
      c = (a + b) / 2;
      d = 0;
      for (int j = 0; j <= 28; j++) {
        if (tab[j][c] < tac[j]) {
          d = 1;
          break;
        }
      }
      if (d == 0)
        b = c;
      else
        a = c + 1;
    }
    cout << b << "\n";
  }
  return 0;
}
