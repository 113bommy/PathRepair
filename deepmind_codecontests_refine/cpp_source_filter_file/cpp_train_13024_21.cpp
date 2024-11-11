#include <bits/stdc++.h>
using namespace std;
int main() {
  double n, s;
  double ans;
  cin >> n >> s;
  ans = ceil(s / n);
  cout << setprecision(9) << ans;
  return 0;
}
