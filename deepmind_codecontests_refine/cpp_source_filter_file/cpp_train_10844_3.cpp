#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  for (int w = 0; w < a; w++) {
    string m, n;
    cin >> m >> n;
    int ms[m.size()][2];
    ms[0][0] = m[0];
    ms[0][1] = 1;
    int ns[n.size()][2];
    ns[0][0] = n[0];
    ns[0][1] = 1;
    int jm = 0;
    int jn = 0;
    for (int i = 1; i < m.size(); i++) {
      if (m[i] == m[i - 1]) {
        ms[jm][1]++;
      } else {
        jm++;
        ms[jm][0] = m[i];
        ms[jm][1] = 1;
      }
    }
    for (int i = 1; i < n.size(); i++) {
      if (n[i] == n[i - 1]) {
        ns[jn][1]++;
      } else {
        jn++;
        ns[jn][0] = n[i];
        ns[jn][1] = 1;
      }
    }
    if (jm == jn) {
      int L = 1;
      for (int i = 0; i < (jn + 1); i++) {
        if ((ms[i][0] != ns[i][0]) or (ms[i][1] > ns[i][1])) {
          cout << "NO1" << endl;
          L = 0;
          break;
        }
      }
      if (L == 1) {
        cout << "YES" << endl;
      }
    } else {
      cout << "NO1" << endl;
    }
  }
  return 0;
}
