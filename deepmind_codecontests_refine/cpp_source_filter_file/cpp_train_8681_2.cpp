#include <bits/stdc++.h>
using namespace std;
char t[100][100];
int main(int argc, char* argv[]) {
  unsigned int n;
  cin >> n;
  for (unsigned int i = 0; i < n; ++i)
    for (unsigned int j = 0; j < n; ++j) cin >> t[i][j];
  unsigned int r = 0;
  for (unsigned int i = 0; i < n; ++i) {
    for (unsigned int j = 0; j < n; ++j) {
      if (t[i][j] == '.') {
        ++r;
        break;
      }
    }
  }
  if (r < n) {
    unsigned int c = 0;
    for (unsigned int i = 0; i < n; ++i) {
      for (unsigned int j = 0; j < n; ++j) {
        if (t[i][j] == '.') {
          ++c;
          break;
        }
      }
    }
    if (c < n)
      cout << -1 << endl;
    else {
      for (unsigned int i = 0; i < n; ++i) {
        for (unsigned int j = 0; j < n; ++j) {
          if (t[j][i] == '.') {
            cout << j + 1 << ' ' << i + 1 << endl;
            break;
          }
        }
      }
    }
  } else {
    for (unsigned int i = 0; i < n; ++i) {
      for (unsigned int j = 0; j < n; ++j) {
        if (t[i][j] == '.') {
          cout << i + 1 << ' ' << j + 1 << endl;
          break;
        }
      }
    }
  }
  return 0;
}
