#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[1005][1005];
char formed_string[1005];
bool is_Valid() {
  for (int i = 2; i <= n; i++) {
    int c = 0;
    for (int j = 1; j <= m; j++) {
      if (formed_string[j] != a[i][j]) {
        c++;
      }
    }
    if (c > 1) {
      return false;
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
      }
    }
    for (int i = 1; i <= m; i++) {
      formed_string[i] = a[1][i];
    }
    int flag = 0;
    for (int i = 1; i <= m; i++) {
      for (char c = 'a'; c <= 'z'; c++) {
        formed_string[i] = c;
        if (is_Valid()) {
          for (int j = 1; j <= m; j++) {
            cout << formed_string[j];
          }
          cout << "\n";
          flag = 1;
          break;
        }
      }
      formed_string[i] = a[1][i];
      if (flag == 1) break;
    }
    if (flag == 0)
      cout << "-1"
           << "\n";
  }
}
