#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char v[101][101];
  vector<int> a1, a2;
  int c1 = 0, c2 = 0;
  string in;
  for (int i = 0; i < n; i++) {
    cin >> in;
    for (int j = 0; j < m; j++) {
      v[i][j] = in[j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      c1 = 0;
      c2 = 0;
      a1.clear();
      a2.clear();
      for (int a = 0; a < m; a++) {
        if (v[i][a] == '#') {
          a1.push_back(a);
        }
        if (v[j][a] == '#') {
          a2.push_back(a);
        }
      }
      sort(a1.begin(), a1.end());
      sort(a2.begin(), a2.end());
      if (a1 == a2) {
        continue;
      }
      for (int c = 0; c < a1.size(); c++) {
        for (int d = 0; d < a2.size(); d++) {
          if (a1[c] == a2[d]) {
            cout << "No";
            return 0;
          }
        }
      }
    }
  }
  cout << "Yes";
  return 0;
}
