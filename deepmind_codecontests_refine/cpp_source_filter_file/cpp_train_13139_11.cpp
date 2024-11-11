#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, q;
  cin >> n >> q;
  vector<vector<bool> > mat(3, vector<bool>(n + 1, false));
  long long front = 0, cross = 0, x, y;
  for (long long i = 0; i < q; ++i) {
    cin >> x >> y;
    if (mat[x][y] == false) {
      mat[x][y] = true;
      if (y == 1) {
        if (mat[1][y + 1] == true) ++cross;
      } else if (y == n) {
        if (mat[2][y - 1] == true) ++cross;
      } else {
        if (x == 1) {
          if (mat[2][y] == true) {
            ++front;
          }
          if (mat[2][y + 1] == true) {
            ++cross;
          }
          if (mat[2][y - 1] == true) {
            ++cross;
          }
        } else {
          if (mat[1][y] == true) {
            ++front;
          }
          if (mat[1][y + 1] == true) {
            ++cross;
          }
          if (mat[1][y - 1] == true) {
            ++cross;
          }
        }
      }
    } else {
      mat[x][y] = false;
      if (y == 1) {
        if (mat[1][y + 1] == true) --cross;
      } else if (y == n) {
        if (mat[2][y - 1] == true) --cross;
      } else {
        if (x == 1) {
          if (mat[2][y] == true) {
            --front;
          }
          if (mat[2][y + 1] == true) {
            --cross;
          }
          if (mat[2][y - 1] == true) {
            --cross;
          }
        } else {
          if (mat[1][y] == true) {
            --front;
          }
          if (mat[1][y + 1] == true) {
            --cross;
          }
          if (mat[1][y - 1] == true) {
            -cross;
          }
        }
      }
    }
    if (cross == 0 && front == 0)
      cout << "Yes";
    else
      cout << "No";
    cout << "\n";
  }
  return 0;
}
