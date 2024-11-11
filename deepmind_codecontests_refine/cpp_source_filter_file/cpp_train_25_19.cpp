#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<char> > mat;
    for (int i = 0; i < n; i++) {
      vector<char> v(n);
      for (int j = 0; j < n; j++) cin >> v[j];
      mat.push_back(v);
    }
    bool c1 = (mat[0][2] == mat[2][0] and mat[2][0] == mat[1][1]);
    bool c2 = mat[0][1] == mat[1][0];
    if (c2) {
      if (c1) {
        if (mat[0][1] == mat[1][1])
          cout << 2 << "\n" << 1 << " " << 2 << "\n" << 2 << " " << 1 << "\n";
        else
          cout << 0 << "\n";
      } else {
        cout << ((mat[2][0] == mat[1][0]) + (mat[1][1] == mat[1][0]) +
                 (mat[0][2] == mat[1][0]))
             << "\n";
        if (mat[0][2] == mat[1][0]) cout << 1 << " " << 3 << "\n";
        if (mat[1][1] == mat[1][0]) cout << 2 << " " << 2 << "\n";
        if (mat[2][0] == mat[1][0]) cout << 3 << " " << 1 << "\n";
      }
    } else {
      if (c1) {
        cout << 1 << "\n";
        (mat[1][0] == mat[1][1]) ? (cout << 2 << " " << 1 << "\n")
                                 : (cout << 1 << " " << 2 << "\n");
      } else {
        cout << 2 << "\n";
        (mat[2][0] == mat[1][1])
            ? (cout << 1 << " " << 3 << "\n")
            : ((mat[0][2] == mat[2][0]) ? (cout << 2 << " " << 2 << "\n")
                                        : (cout << 3 << " " << 1 << "\n"));
        (mat[2][0] == mat[1][1])
            ? (mat[0][2] = mat[2][0])
            : ((mat[0][2] == mat[2][0]) ? (mat[1][1] = mat[2][0])
                                        : (mat[2][0] = mat[1][1]));
        (mat[1][0] != mat[1][1]) ? (cout << 2 << " " << 1 << "\n")
                                 : (cout << 1 << " " << 2 << "\n");
      }
    }
  }
  return 0;
}
