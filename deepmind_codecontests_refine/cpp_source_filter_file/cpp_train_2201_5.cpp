#include <bits/stdc++.h>
using namespace std;
const long long maxn = 300000;
const long long inf = 1e18;
long long n, h1, m1, h2, jo, jo1, m2;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(0);
  scanf("%lld:%lld", &h1, &m1);
  scanf("%lld:%lld", &h2, &m2);
  jo = h1 * 60 + m1;
  jo1 = h2 * 60 + m2;
  jo = (jo1 - jo) / 2 + jo;
  if (jo / 60 > 10)
    cout << jo / 60;
  else
    cout << 0 << jo / 60;
  cout << ":";
  if (jo % 60 > 10)
    cout << jo % 60;
  else
    cout << 0 << jo % 60;
}
