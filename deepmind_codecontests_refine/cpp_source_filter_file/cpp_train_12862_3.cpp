#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s[1001];
  bool piu = false;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> s[i];
  for (int i = 1; i <= n && !piu; i++) {
    if ((s[i][0] == 'O') && (s[i][1] == 'O')) {
      s[i][0] = '+';
      s[i][1] = '+';
      piu = true;
    }
    if ((s[i][3] == 'O') && (s[i][4] == 'O')) {
      s[i][3] = '+';
      s[i][4] = '+';
      piu = true;
    }
  }
  if (!piu)
    cout << "NO\n";
  else {
    cout << "YES\n";
    for (int i = 1; i <= n; i++) cout << s[i] << endl;
  }
  return 0;
}
