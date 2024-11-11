#include <bits/stdc++.h>
using namespace std;
pair<long long int, long long int> pr;
map<long long int, long long int> mpp;
set<long long int> ts;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int n, row = 0, column = 0;
  char a[102][102];
  cin >> n;
  long long int i, j;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (a[i][j] == '.') {
        row++;
        break;
      }
    }
  }
  if (row == n) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (a[i][j] == '.') {
          cout << i + 1 << " " << j + 1 << endl;
          break;
        }
      }
    }
    return 0;
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (a[j][i] == '.') {
        column++;
        break;
      }
    }
  }
  if (column == n) {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (a[j][i] == '.') {
          cout << i + 1 << " " << j + 1 << endl;
          break;
        }
      }
    }
    return 0;
  }
  cout << "-1\n";
  return 0;
}
