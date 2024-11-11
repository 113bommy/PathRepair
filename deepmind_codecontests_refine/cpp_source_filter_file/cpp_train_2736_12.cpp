#include <bits/stdc++.h>
using namespace std;
template <typename TYPE>
void readint(TYPE& x) {
  x = 0;
  int f = 1;
  char c;
  for (c = getchar(); !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  x *= f;
}
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
template <typename... T>
void read(T&... args) {
  ((cin >> args), ...);
}
template <typename... T>
void write(T... args) {
  ((cout << args << ' '), ...);
  cout << '\n';
}
const long long MOD = 1e9 + 7, MAX = 105;
const char nl = '\n';
const long long INF = 2e9;
int n, m;
char a[MAX][MAX];
void solve() {
  read(n, m);
  vector<pair<pair<pair<int, int>, pair<int, int>>, pair<int, int>>> v;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) read(a[i][j]);
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < m - 1; j++) {
      if (a[i][j] == '1') {
        v.push_back({{{i, j}, {i, j + 1}}, {i + 1, j}});
        a[i][j] = '0';
        a[i + 1][j] = '0' + (a[i + 1][j] + 1) % 2;
        a[i][j + 1] = '0' + (a[i][j + 1] + 1) % 2;
      }
    }
  for (int i = 0; i < m - 1; i++)
    if (a[n - 1][i] == '1') {
      v.push_back({{{n - 1, i}, {n - 2, i}}, {n - 2, i + 1}});
      v.push_back({{{n - 1, i + 1}, {n - 2, i}}, {n - 2, i + 1}});
      a[n - 1][i] = '0';
      a[n - 1][i] = '0' + (a[n - 1][i] + 1) % 2;
    }
  for (int i = 0; i < n - 1; i++)
    if (a[i][m - 1] == '1') {
      v.push_back({{{i, m - 1}, {i, m - 2}}, {i + 1, m - 2}});
      v.push_back({{{i + 1, m - 1}, {i, m - 2}}, {i + 1, m - 2}});
      a[i][m - i] = '0';
      a[i + 1][m - 1] = '0' + (a[i + 1][m - 1] + 1) % 2;
    }
  if (a[n - 1][m - 1] == '0') {
    write(v.size());
    for (auto it : v)
      cout << it.first.first.first + 1 << ' ' << it.first.first.second + 1
           << ' ' << it.first.second.first + 1 << ' '
           << it.first.second.second + 1 << ' ' << it.second.first + 1 << ' '
           << it.second.second + 1 << '\n';
  } else {
    v.push_back({{{n - 1, m - 1}, {n - 1, m - 2}}, {n - 2, m - 1}});
    v.push_back({{{n - 1, m - 1}, {n - 1, m - 2}}, {n - 2, m - 2}});
    v.push_back({{{n - 1, m - 1}, {n - 2, m - 1}}, {n - 2, m - 2}});
    write(v.size());
    for (auto it : v)
      cout << it.first.first.first + 1 << ' ' << it.first.first.second + 1
           << ' ' << it.first.second.first + 1 << ' '
           << it.first.second.second + 1 << ' ' << it.second.first + 1 << ' '
           << it.second.second + 1 << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int __;
  cin >> __;
  while (__--) {
    solve();
  }
  return 0;
}
