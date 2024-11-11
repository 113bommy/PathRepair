#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  int kolko[10] = {};
  cin >> a >> b;
  if (b.size() > a.size()) {
    sort(a.begin(), a.end());
    for (int i = a.size() - 1; i >= 0; i--) cout << a[i];
    return 0;
  }
  for (int i = 0; i < a.size(); i++) kolko[a[i] - '0']++;
  string sol = "";
  for (int uzeo = 0; uzeo < a.size(); uzeo++) {
    for (int i = 9; i >= 0; i--) {
      if (kolko[i] == 0) continue;
      string pom = "";
      int pomKolko[10];
      pom += char('0' + i);
      for (int j = 0; j < 10; j++) pomKolko[j] = kolko[j];
      pomKolko[i]--;
      for (int j = 0; j < 10; j++)
        while (pomKolko[j]) {
          pom += char('0' + j);
          pomKolko[j]--;
        }
      pom = sol + pom;
      if (pom < b) {
        sol += char('0' + i);
        kolko[i]--;
        break;
      }
    }
  }
  cout << sol;
  return 0;
}
