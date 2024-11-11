#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
const double pi = acos(-1);
const double EPS = 1e-5;
void iter(vector<cd> &a, bool invert) {
  int n = a.size();
  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * pi / len * (invert ? -1 : 1);
    cd wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      cd w(1);
      for (int j = 0; j < len / 2; j++) {
        cd u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }
  if (invert)
    for (cd &x : a) x /= n;
}
void iter2d(vector<vector<cd>> &a, bool invert) {
  for (auto &it : a) iter(it, invert);
  for (int j = 0; j < a[0].size(); j++) {
    vector<cd> col(a.size());
    for (int i = 0; i < a.size(); i++) col[i] = a[i][j];
    iter(col, invert);
    for (int i = 0; i < a.size(); i++) a[i][j] = col[i];
  }
}
vector<vector<int>> mult(vector<vector<cd>> &a, vector<vector<cd>> &b) {
  int nr = 1;
  while (nr < a.size() + b.size()) nr <<= 1;
  a.resize(nr);
  b.resize(nr);
  int nc = 1;
  while (nc < a[0].size() + b[0].size()) nc <<= 1;
  for (auto &it : a) it.resize(nc, 0);
  for (auto &it : b) it.resize(nc, 0);
  iter2d(a, 0);
  iter2d(b, 0);
  for (int i = 0; i < nr; i++)
    for (int j = 0; j < nc; j++) a[i][j] *= b[i][j];
  iter2d(a, 1);
  vector<vector<int>> ret(nr, vector<int>(nc));
  for (int i = 0; i < nr; i++)
    for (int j = 0; j < nc; j++) ret[i][j] = (int)(a[i][j].real() + EPS);
  return ret;
}
const int N = 401;
int n, m, r, c;
string str[N];
string pat[N];
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> str[i];
  cin >> r >> c;
  for (int i = 0; i < r; i++) cin >> pat[i];
  vector<vector<cd>> a(n + r, vector<cd>(m + c)), b(r, vector<cd>(c, 0));
  for (int i = 0; i < n + r; i++)
    for (int j = 0; j < m + c; j++) {
      int cur = str[i % n][j % m] - 'a';
      double ang = 2 * pi * cur / 26;
      a[i][j] = cd(cos(ang), sin(ang));
    }
  int cnt = 0;
  for (int i = 0; i < r; i++)
    for (int j = 0; j < c; j++) {
      if (pat[i][j] == '?') continue;
      cnt++;
      int cur = pat[i][j] - 'a';
      double ang = 2 * pi * cur / 26;
      b[r - 1 - i][c - 1 - j] = cd(cos(ang), -sin(ang));
    }
  vector<vector<int>> ret;
  ret = mult(a, b);
  for (int i = r - 1; i < n + r - 1; i++) {
    for (int j = c - 1; j < m + c - 1; j++) cout << (ret[i][j] == cnt);
    cout << "\n";
  }
  return 0;
}
