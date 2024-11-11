#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 9000000000000000000;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, m;
  cin >> n >> m;
  int c = 0;
  while (1) {
    if (n > m) break;
    n += n * 3;
    m += m * 2;
    c++;
  }
  cout << c << '\n';
  return 0;
}
