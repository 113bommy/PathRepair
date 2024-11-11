#include <bits/stdc++.h>
using namespace std;
ifstream fi("input.txt");
int n;
int minn, maxx;
int main() {
  cin >> n;
  int m = n;
  int ans1 = 0, ans2 = 0;
  while (1) {
    n -= 5;
    if (n <= 0) break;
    ans1 += min(2, n);
    n -= 2;
  }
  while (1) {
    ans2 += min(m, 2);
    m -= 2;
    if (m <= 0) break;
    m -= 5;
    if (m <= 0) break;
  }
  cout << ans1 << " " << ans2;
  return 0;
}
