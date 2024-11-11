#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, i, j;
    bool ashishf = true;
    bool vivekf = false;
    cin >> n >> m;
    int a[n][m];
    set<int> sr;
    set<int> sc;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        cin >> a[i][j];
        if (a[i][j] == 1) {
          sr.insert(i);
          sc.insert(j);
        }
      }
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (sr.find(i) == sr.end() && sc.find(j) == sc.end()) {
          if (vivekf == false && ashishf == true) {
            vivekf = true;
            ashishf = false;
          } else if (ashishf == false && vivekf == true) {
            vivekf = false;
            ashishf = true;
          }
          sr.insert(i);
          sc.insert(j);
        }
      }
    }
    if (vivekf == true && ashishf == false) {
      cout << "Ashish" << endl;
    } else
      cout << "Vivek" << endl;
  }
}
