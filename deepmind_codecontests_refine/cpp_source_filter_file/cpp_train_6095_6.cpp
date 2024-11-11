#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<vector<int> > v(n + 2, vector<int>(n + 2, 0));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      char t;
      cin >> t;
      v[i][j] = t - '0';
    }
  bool is_correct = true;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (v[i][j] == 3 ||
          !(v[i][j] == 1 &&
                (v[i - 1][j] == 2 && v[i][j + 1] == 2 && v[i - 1][j + 1] == 4 ||
                 v[i - 1][j] == 2 && v[i][j - 1] == 2 && v[i - 1][j - 1] == 4 ||
                 v[i + 1][j] == 2 && v[i][j + 1] == 2 && v[i + 1][j + 1] == 4 ||
                 v[i + 1][j] == 2 && v[i][j - 1] == 2 &&
                     v[i + 1][j - 1] == 4) ||
            v[i][j] == 2 && ((v[i][j - 1] == 1 || v[i][j - 1] == 2) &&
                                 (v[i][j + 1] == 1 || v[i][j + 1] == 2) &&
                                 ((v[i + 1][j] == 4) != (v[i - 1][j] == 4)) ||
                             (v[i + 1][j] == 1 || v[i + 1][j] == 2) &&
                                 (v[i - 1][j] == 1 || v[i + 1][j] == 2) &&
                                 ((v[i][j + 1] == 4) != (v[i][j - 1] == 4))) ||
            v[i][j] == 4 && v[i][j + 1] != 0 && v[i][j - 1] != 0 &&
                v[i - 1][j + 1] != 0 && v[i + 1][j + 1] != 0 &&
                v[i - 1][j - 1] != 0 && v[i - 1][j + 1] != 0 &&
                v[i + 1][j] != 0 && v[i - 1][j] != 0 ||
            v[i][j] == 0)) {
        is_correct = false;
      }
  cout << (is_correct ? "Yes" : "No") << endl;
}
