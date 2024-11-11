#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > mas(110);
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    for (int j = 0; j < m; j++) {
      int a;
      cin >> a;
      mas[i].push_back(a);
    }
  }
  for (int i = 0; i < n; i++) {
    bool g = 0;
    bool used[110];
    for (int j = 0; j < 12; j++) used[j] = 0;
    for (int j = 0; j < (int)mas[i].size(); j++) {
      used[mas[i][j]] = 1;
    }
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      bool res = 1;
      for (int k = 0; k < (int)mas[j].size(); k++) {
        if (used[mas[j][k]] == 0) res = 0;
      }
      if (res) {
        cout << "NO" << endl;
        g = 1;
        break;
      }
    }
    if (!g) cout << "YES" << endl;
  }
  return 0;
}
