#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(12);
  cout << fixed;
  string a, b;
  cin >> a >> b;
  int la = a.size();
  int lb = b.size();
  vector<int> psum(la + 1, 0);
  for (int i = 0; i < la; ++i) psum[i + 1] = psum[i] + (a[i] - '0');
  int res = 0;
  for (int i = 0; i < lb; ++i) {
    int lef, rig;
    lef = max(0, la - lb + i);
    rig = min(i, la - 1);
    int sub = psum[rig + 1] - psum[lef];
    int m = rig - lef + 1;
    if (b[i] == '0')
      res += sub;
    else
      res += m - sub;
  }
  cout << res << '\n';
  return 0;
}
