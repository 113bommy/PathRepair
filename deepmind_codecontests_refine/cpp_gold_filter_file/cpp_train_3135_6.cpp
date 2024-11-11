#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(10);
  long long n;
  cin >> n;
  long long m;
  cin >> m;
  long long ar = n * m;
  if (n > m) swap(n, m);
  long long re = 0;
  if (n == 1) {
    m %= 6;
    if (m > 3) m = 6 - m;
    re = m;
  } else if (n == 2) {
    if (m == 2)
      re = 4;
    else if (m == 3)
      re = 2;
    else if (m == 7)
      re = 2;
    else
      re = 0;
  } else if ((m * n) & 1) {
    re = 1;
  } else
    re = 0;
  cout << (ar - re);
}
