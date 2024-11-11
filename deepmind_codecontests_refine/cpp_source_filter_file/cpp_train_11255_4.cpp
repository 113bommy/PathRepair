#include <bits/stdc++.h>
using namespace std;
int n, p[1003], w = 1;
vector<int> v;
char c[1003][1003];
bool bo[1003];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      c[i][j] = '.';
    }
  }
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    if (p[i] != i) {
      w = 0;
    }
  }
  if (w) {
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << '.';
      }
      cout << endl;
    }
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    if (bo[i]) continue;
    c[n][i] = '/';
    v.push_back(i);
    int dg = i;
    while (!bo[dg]) {
      bo[dg] = 1;
      dg = p[dg];
    }
  }
  int dg = (int)v[(int)v.size() - 1];
  for (int i = (int)v.size() - 1; i > 0; --i) {
    p[v[i]] = p[v[i - 1]];
  }
  p[v[0]] = 0;
  v.clear();
  while (dg) {
    v.push_back(dg);
    dg = p[dg];
  }
  cout << n - 1 << endl;
  reverse(v.begin(), v.end());
  for (int i = 1; i < v.size(); ++i) {
    c[0][0] = '/';
    if (v[i - 1] < v[i]) {
      c[0][0] = '\\';
    }
    c[n - i][v[i]] = c[0][0];
    c[n - i][v[i - 1]] = c[0][0];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << c[i][j];
    }
    cout << endl;
  }
  return 0;
}
