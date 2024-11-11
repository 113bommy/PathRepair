#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  double n, m;
  char ch;
  cin >> n >> ch >> m;
  if (n == 12) n = 0;
  double ans1, ans2;
  ans2 = 6 * m;
  ans1 = n * 30 + 0.5 * m;
  cout << ans1 << " " << ans2 << endl;
}
