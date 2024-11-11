#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000,100000000")
using namespace std;
const long long inf = 1e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-10;
const double PI = 2 * acos(0.0);
const double E = 2.71828;
vector<vector<long long> > g;
map<string, long long> M;
map<long long, string> m;
long long n = 1;
bool gg[10002][10002];
char p[10002][10002];
int main(void) {
  long long q;
  cin >> q;
  g.resize(2 * q + 2);
  string s, s1;
  while (q--) {
    cin >> s;
    if (M.find(s) == M.end()) M[s] = n++, m[n - 1] = s;
    cin >> s1;
    if (M.find(s1) == M.end()) M[s1] = n++, m[n - 1] = s1;
    g[M[s]].push_back(M[s1]);
    g[M[s1]].push_back(M[s]);
    gg[M[s]][M[s1]] = gg[M[s1]][M[s]] = 1;
  }
  vector<long long> ans;
  cout << M.size() << endl;
  for (long long(i) = 0; (i) < (long long)(n); (i)++) {
    if (!i) continue;
    for (long long(j) = 0; (j) < (long long)(g[i].size()); (j)++)
      for (long long(jj) = 0; (jj) < (long long)(g[i].size()); (jj)++) {
        if (j != jj && !gg[g[i][j]][g[i][jj]]) p[g[i][j]][g[i][jj]]++;
        p[g[i][jj]][g[i][j]]++;
      }
  }
  for (long long(i) = 0; (i) < (long long)(n); (i)++) {
    if (i == 0) continue;
    cout << m[i] << " ";
    long long Max = -1, Num = 0;
    for (long long(j) = 0; (j) < (long long)(n); (j)++) {
      if (j == 0 || j == i) continue;
      if (!gg[i][j]) Max = max(Max, (long long)p[i][j]);
    }
    for (long long(j) = 0; (j) < (long long)(n); (j)++) {
      if (j == 0 || j == i) continue;
      if (p[i][j] == Max && !gg[i][j]) Num++;
    }
    cout << Num << endl;
  }
  return 0;
}
