#include <bits/stdc++.h>
using namespace std;
int m, n, res;
int main() {
  cin >> m >> n;
  int hoz = n / 2;
  int left_hoz = n % 2;
  hoz = hoz * m;
  left_hoz = left_hoz * m;
  int ver = left_hoz / m;
  res += hoz + ver;
  cout << res << '\n';
  return 0;
}
