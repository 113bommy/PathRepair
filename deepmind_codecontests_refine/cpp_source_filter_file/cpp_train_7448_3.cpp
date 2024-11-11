#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int test;
  test = 1;
  while (test--) {
    int n, m;
    cin >> m >> n;
    ;
    char pres;
    cin >> pres;
    int count = 0;
    bool arr[26];
    for (int i = 0; i < 26; i++) {
      arr[i] = 0;
    }
    arr[pres - 'A'] = 1;
    string str[m];
    for (int i = 0; i < m; i++) {
      cin >> str[i];
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (str[i][j] == '.') {
          continue;
        }
        if (i + 1 < m) {
          if (str[i + 1][j] == pres && arr[str[i][j] - 'A'] == 0) {
            count++;
            arr[str[i][j] - 'A'] = 1;
            continue;
          }
        }
        if (i - 1 > 0) {
          if (str[i - 1][j] == pres && arr[str[i][j] - 'A'] == 0) {
            count++;
            arr[str[i][j] - 'A'] = 1;
            continue;
          }
        }
        if (j - 1 > 0) {
          if (str[i][j - 1] == pres && arr[str[i][j] - 'A'] == 0) {
            count++;
            arr[str[i][j] - 'A'] = 1;
            continue;
          }
        }
        if (j + 1 < n) {
          if (str[i][j + 1] == pres && arr[str[i][j] - 'A'] == 0) {
            count++;
            arr[str[i][j] - 'A'] = 1;
            continue;
          }
        }
      }
    }
    cout << count << endl;
  }
}
