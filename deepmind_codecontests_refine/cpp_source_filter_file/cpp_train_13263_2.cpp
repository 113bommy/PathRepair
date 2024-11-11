#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  cout.tie(0);
  int n = 0, massimo = 0;
  string s;
  bool p[1001], trattino = false;
  for (int i = 0; i < 1001; i++) p[i] = false;
  cin >> s;
  for (int i = 0; i < s.length(); i++)
    if (s[i] != ',')
      n = 10 * n + (s[i] - '0');
    else {
      p[n] = true;
      massimo = max(massimo, n);
      n = 0;
    }
  p[n] = true;
  massimo = max(massimo, n);
  for (int i = 1; i < 1001; i++) {
    if ((p[i - 1] == false) && (p[i] == true))
      cout << i;
    else if ((p[i - 1] == true) && (p[i] == true))
      trattino = true;
    else if ((p[i - 1] == true) && (p[i] == false)) {
      if (trattino == true) {
        trattino = false;
        cout << "-" << i - 1;
      }
      if (i - 1 < massimo) cout << ",";
    }
  }
  return 0;
}
