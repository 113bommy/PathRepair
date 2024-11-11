#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  return b ? gcd(b, a % b) : a;
}
template <typename T>
T lcm(T a, T b) {
  return a * b / gcd(a, b);
}
void printDouble(double x, int n) {
  cout << fixed << setprecision(n);
  cout << x << endl;
}
const int MAXN = 5e6 + 5;
const int mod = 1e9 + 7;
long long product() { return 1; }
long long sum() { return 0; }
template <typename T, typename... Args>
T product(T a, Args... args) {
  return (a * product(args...)) % mod;
}
template <typename T, typename... Args>
T sum(T a, Args... args) {
  return (a + sum(args...)) % mod;
}
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  string s;
  vector<vector<bool> > a(n + 1, vector<bool>(n + 1, 0));
  vector<int> col(n + 1, 0), row(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> s;
    for (int j = 0; j <= n - 1; j++)
      if (s[j] == 'E') {
        a[i][j + 1] = 1;
        col[j + 1]++, row[i]++;
      }
  }
  int cntRow = 0, cntCol = 0;
  for (int i = 1; i <= n; i++) {
    if (col[i] == n) cntCol++;
    if (row[i] == n) cntRow++;
  }
  if (cntCol & cntRow) {
    cout << -1;
    return 0;
  }
  if (!cntRow) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (a[i][j] == 0) {
          cout << i << " " << j << endl;
          break;
        }
  } else
    for (int j = 1; j <= n; j++)
      for (int i = 1; i <= n; i++)
        if (a[i][j] == 0) {
          cout << i << " " << j << endl;
          break;
        }
}
