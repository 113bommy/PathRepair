#include <bits/stdc++.h>
using namespace std;
const long long r = 1e9;
struct node {
  int a, b, c, d;
};
int n, m;
int t;
int k, l;
int a[105][105];
int b[105][105];
int c[105][105];
string s;
int main() {
  cin >> m >> n;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];
  cin >> k >> l;
  for (int i = m - 1; i >= k - 1; i--) {
    for (int j = n - 1; j >= l - 1; j--) {
      t = 0;
      for (int p = i; p > i - k; p--) {
        for (int q = j; q > j - l; q--) {
          if (a[p][q] == 0) t++;
        }
      }
      b[i][j] = t;
    }
  }
  for (int i = m - 1; i >= l - 1; i--) {
    for (int j = n - 1; j >= k - 1; j--) {
      t = 0;
      for (int p = i; p > i - l; p--) {
        for (int q = j; q > j - k; q--) {
          if (a[p][q] == 0) t++;
        }
      }
      c[i][j] = t;
    }
  }
  int ans = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (ans < b[i][j]) ans = b[i][j];
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (ans < c[i][j]) ans = c[i][j];
  ans = k * l - ans;
  cout << ans;
}
