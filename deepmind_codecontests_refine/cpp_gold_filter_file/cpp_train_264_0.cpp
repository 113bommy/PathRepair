#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1000000007;
const int N = 200000 + 7;
char arr[10][10];
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 2; i < 6; i++) {
    string t;
    cin >> t;
    for (int j = 0; j < 4; j++) {
      arr[i][j + 2] = t[j];
    }
  }
  for (int i = 2; i < 6; i++) {
    for (int j = 2; j < 6; j++) {
      if (arr[i][j] != '.') continue;
      bool f = false;
      if (arr[i - 1][j - 1] == 'x' && arr[i + 1][j + 1] == 'x')
        f = true;
      else if (arr[i][j - 1] == 'x' && arr[i][j + 1] == 'x')
        f = true;
      else if (arr[i + 1][j - 1] == 'x' && arr[i - 1][j + 1] == 'x')
        f = true;
      else if (arr[i - 1][j] == 'x' && arr[i + 1][j] == 'x')
        f = true;
      else if (arr[i - 1][j - 1] == 'x' && arr[i - 2][j - 2] == 'x')
        f = true;
      else if (arr[i][j - 1] == 'x' && arr[i][j - 2] == 'x')
        f = true;
      else if (arr[i + 1][j - 1] == 'x' && arr[i + 2][j - 2] == 'x')
        f = true;
      else if (arr[i + 1][j] == 'x' && arr[i + 2][j] == 'x')
        f = true;
      else if (arr[i + 1][j + 1] == 'x' && arr[i + 2][j + 2] == 'x')
        f = true;
      else if (arr[i][j + 1] == 'x' && arr[i][j + 2] == 'x')
        f = true;
      else if (arr[i - 1][j + 1] == 'x' && arr[i - 2][j + 2] == 'x')
        f = true;
      else if (arr[i - 1][j] == 'x' && arr[i - 2][j] == 'x')
        f = true;
      if (f) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
  return 0;
}
