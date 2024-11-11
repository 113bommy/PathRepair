#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, ans1, ans2;
  cin >> a >> b;
  ans1 = max(a, b);
  ans2 = abs(a - b) / 2;
  cout << ans1 << " " << ans2 << endl;
  return 0;
}
