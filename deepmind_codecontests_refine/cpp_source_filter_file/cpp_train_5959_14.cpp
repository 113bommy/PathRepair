#include <bits/stdc++.h>
#pragma optimization_level 3
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long N = 2e+5 + 7;
const long long MAXN = 1e+9;
const long long mod = 1e+9 + 7;
const long long INF = 0x7f7f7f7f7f7f7f7f;
const int INFi = 0x7f7f7f7f;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y >> x >> y;
  }
  string s;
  for (int i = 0; i < n - 1; i++) s += "U";
  for (int i = 0; i < m - 1; i++) s += "L";
  for (int i = 0; i < m; i++) {
    if (i & 1)
      for (int i = 0; i < n - 1; i++) s += "L";
    else
      for (int i = 0; i < n - 1; i++) s += "R";
    s += "D";
  }
  cout << s.size() << "\n";
  cout << s << "\n";
}
