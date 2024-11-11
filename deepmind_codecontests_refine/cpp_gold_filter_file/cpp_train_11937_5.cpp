#include <bits/stdc++.h>
using namespace std;
const size_t SIZE = 101;
char a[4][SIZE][SIZE];
int main() {
  cin.tie();
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int k = 0; k < 4; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> a[k][i][j];
      }
    }
  }
  int ans = 100001, buf;
  for (int f_b = 0; f_b < 4; ++f_b) {
    for (int s_b = 0; s_b < 4; ++s_b) {
      if (f_b >= s_b) {
        continue;
      }
      buf = 0;
      for (int k = 0; k < 4; ++k) {
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
            if (k == f_b || k == s_b) {
              if (a[k][i][j] == ((i + j) % 2 == 0 ? '0' : '1')) {
                ++buf;
              }
            } else {
              if (a[k][i][j] == ((i + j) % 2 == 0 ? '1' : '0')) {
                ++buf;
              }
            }
          }
        }
      }
      if (buf < ans) {
        ans = buf;
      }
    }
  }
  cout << ans;
  return 0;
}
