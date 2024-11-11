#include <bits/stdc++.h>
using namespace std;
int used[5001][26][26];
int main() {
  string s;
  int n;
  double total = 0, ok = 0;
  int i, j, k;
  cin >> s;
  n = int(s.length());
  for (i = 1; i <= n; i++)
    for (j = 0; j < n; j++) used[i][s[j] - 'a'][s[(j + i) % n] - 'a']++;
  for (i = 0; i < 26; i++) {
    int t = 0, o = 0;
    for (j = 1; j <= n; j++) {
      int tt = 0, oo = 0;
      for (k = 0; k < 26; k++) {
        tt += used[j][i][k];
        if (used[j][i][k] == 1) oo++;
      }
      if (oo >= o) t = tt, o = oo;
    }
    total += t, ok += o;
  }
  cout << fixed;
  cout.precision(15);
  cout << ok / total << endl;
  return 0;
}
