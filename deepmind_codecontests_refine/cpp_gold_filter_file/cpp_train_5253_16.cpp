#include <bits/stdc++.h>
using namespace std;
struct edge {
  int u, v;
  long long w;
};
long long INF = LLONG_MAX / 3;
long long MOD = 1000000007;
long long _MOD = 1000000009;
double EPS = 1e-10;
vector<vector<long long> > matmul(vector<vector<long long> >& a,
                                  vector<vector<long long> >& b) {
  int n = a.size();
  vector<vector<long long> > c(n, vector<long long>(n, -INF));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++) c[i][j] = max(c[i][j], a[i][k] + b[k][j]);
  return c;
}
vector<vector<long long> > matpow(vector<vector<long long> >& a, long long m) {
  int n = a.size();
  vector<vector<long long> > b(n, vector<long long>(n, -INF));
  for (int i = 0; i < n; i++) b[i][i] = 0;
  for (; m; m >>= 1) {
    if (m & 1) b = matmul(b, a);
    a = matmul(a, a);
  }
  return b;
}
vector<string> w[10][4][4];
int main() {
  long long M;
  cin >> M;
  string s;
  cin >> s;
  int N = s.size();
  for (int d = 0; d < 10; d++)
    for (int l = 0; l + d + 2 <= N; l++) {
      string t = s.substr(l, d + 2);
      w[d][t.front() - 'A'][t.back() - 'A'].push_back(t);
    }
  vector<vector<int> > b(4, vector<int>(4));
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      for (int& d = b[i][j];; d++) {
        vector<string>& v = w[d][i][j];
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        if (v.size() < (1 << (d * 2))) break;
      }
  vector<vector<long long> > a(40, vector<long long>(40, -INF));
  for (int i = 0; i < 36; i++) a[i][i + 4] = 0;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      for (int d = b[i][j]; d < 10; d++) a[36 + j][(9 - d) * 4 + i] = 1;
  a = matpow(a, M - 1);
  long long ma = 0;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) ma = max(ma, a[36 + i][36 + j]);
  cout << ma + 1 << endl;
}
