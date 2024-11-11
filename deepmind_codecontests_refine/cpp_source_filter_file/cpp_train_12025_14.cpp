#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int m = 1000;
  int ans = 0;
  while (n--) {
    int a, p;
    cin >> a >> p;
    m = min(m, p);
    ans += a * p;
  }
  cout << ans << endl;
  return 0;
}
