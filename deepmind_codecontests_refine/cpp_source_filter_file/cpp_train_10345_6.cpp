#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:20000000")
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> a;
  string s;
  for (int i = (0); (i) < (n); (i)++) {
    cin >> s;
    a.push_back("#" + s + "#");
  }
  int x = 1;
  int r = 0;
  bool g = true;
  for (int i = 0; i < n - 1; i++) {
    if (a[i + 1][x] == '.') {
      r++;
      continue;
    }
    int left = x, right = x;
    int wall = 0;
    bool down = false;
    while (!down) {
      if (g) {
        if (a[i + 1][right] == '.') {
          r += right - x + 1;
          x = right;
          break;
        }
        for (int j = right + 1;; j++) {
          if (a[i][j] == '+') {
            wall = 0;
            right = j;
            r += j - x;
            x = j - 1;
            g = false;
            break;
          } else if (a[i][j] == '#') {
            wall++;
            right = j - 1;
            r += j - x;
            x = j - 1;
            g = false;
            break;
          } else if (a[i + 1][j] == '.') {
            r += j - x + 1;
            x = j;
            down = true;
            break;
          }
        }
      } else {
        if (a[i + 1][left] == '.') {
          r += x - left + 1;
          x = left;
          break;
        }
        for (int j = left - 1;; j--) {
          if (a[i][j] == '+') {
            wall = 0;
            left = j;
            r += x - j;
            x = j + 1;
            g = true;
            break;
          } else if (a[i][j] == '#') {
            wall++;
            left = j + 1;
            r += x - j;
            x = j + 1;
            g = true;
            break;
          } else if (a[i + 1][j] == '.') {
            r += x - j + 1;
            x = j;
            down = true;
            break;
          }
        }
      }
      if (wall == 2) {
        cout << "Never";
        return 0;
      }
    }
  }
  cout << r;
  return 0;
}
