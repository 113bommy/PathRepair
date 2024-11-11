#include <bits/stdc++.h>
const double eps = 1e-7, PI = 3.1415926;
const int N = 1e6;
using namespace std;
long long n, m, k, a[100100], r[100100], l[100100], q, sum, mx = -1, mn = 1e9;
string c[50009];
string s;
vector<int> vec[27];
map<char, long long> M;
int main() {
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) {
    long long g = s[i] - 97;
    vec[g].push_back(i);
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < m; i++) {
    mx = -1;
    M['a'] = 0;
    M['b'] = 0;
    M['c'] = 0;
    M['d'] = 0;
    M['e'] = 0;
    M['f'] = 0;
    M['g'] = 0;
    M['h'] = 0;
    M['i'] = 0;
    M['j'] = 0;
    M['k'] = 0;
    M['l'] = 0;
    M['m'] = 0;
    M['n'] = 0;
    M['o'] = 0;
    M['p'] = 0;
    M['q'] = 0;
    M['r'] = 0;
    M['s'] = 0;
    M['t'] = 0;
    M['u'] = 0;
    M['v'] = 0;
    M['w'] = 0;
    M['x'] = 0;
    M['y'] = 0;
    M['z'] = 0;
    for (int j = 0; j < c[i].size(); j++) {
      M[c[i][j]]++;
      long long h = vec[c[i][j] - 97][M[c[i][j] - 1]];
      mx = max(mx, h);
    }
    cout << mx + 1 << endl;
  }
}
