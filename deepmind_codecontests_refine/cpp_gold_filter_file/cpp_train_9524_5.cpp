#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long linf = 1e18;
const int inf = 1e9;
const int N = 305 + 5;
char arr[N][N], ans[N][N];
int k, n, m;
vector<pair<int, int> > v;
bool ctr(int x, int y) {
  for (__typeof(v.begin()) it = v.begin(); it != v.end(); it++)
    if ((it->first + x >= 1 && it->first + x <= n && it->second + y >= 1 &&
         it->second + y <= n && arr[it->first + x][it->second + y] == '.')) {
      return false;
    }
  return true;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      scanf(" %c", &arr[i][j]);
      if (arr[i][j] == 'o') v.push_back(make_pair(i, j));
    }
  for (int i = 1; i <= 2 * n - 1; i++)
    for (int j = 1; j <= 2 * n - 1; j++) {
      ans[i][j] = '.';
      if (ctr(i - n, j - n) && !(i == n && j == n)) {
        ans[i][j] = 'x';
      }
    }
  ans[n][n] = 'o';
  for (int i = 1; i <= n * 2 - 1; i++)
    for (int j = 1; j <= n * 2 - 1; j++)
      if (ans[i][j] == 'x') {
        int t = 0;
        for (__typeof(v.begin()) it = v.begin(); it != v.end(); it++)
          if ((it->first + i - n >= 1 && it->first + i - n <= n) &&
              (it->second + j - n >= 1 && it->second + j - n <= n)) {
            arr[it->first + i - n][it->second + j - n] = '*';
            t = 1;
          }
        if (!t) ans[i][j] = '.';
      }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (arr[i][j] == 'x') {
        cout << "NO" << '\n';
        return 0;
      }
  cout << "YES" << '\n';
  for (int i = 1; i <= n * 2 - 1; i++) {
    for (int j = 1; j <= n * 2 - 1; j++) cout << ans[i][j];
    cout << '\n';
  }
  return 0;
}
