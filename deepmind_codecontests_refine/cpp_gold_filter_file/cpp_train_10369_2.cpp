#include <bits/stdc++.h>
using namespace std;
const long long MAX = 2e18;
long long x, y, l, r, res;
vector<long long> St;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> x >> y >> l >> r;
  St.push_back(l - 1);
  St.push_back(r + 1);
  long long numx = 1;
  long long numy;
  while (true) {
    numy = 1;
    while (true) {
      if (l <= numx + numy && numx + numy <= r) St.push_back(numx + numy);
      if (numy > r / y) break;
      numy *= y;
    }
    if (numx > r / x) break;
    numx *= x;
  }
  sort(St.begin(), St.end());
  res = 0;
  for (int i = 1; i < St.size(); i++) {
    res = max(res, St[i] - St[i - 1] - 1);
  }
  cout << res;
  return 0;
}
