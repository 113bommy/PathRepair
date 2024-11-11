#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, j, k, ans, t;
  cin >> n;
  string a, b;
  cin >> a >> b;
  for (int i = 0; i < n; i++) {
    j = a[i] - '0';
    k = b[i] - '0';
    t = min(abs(j - k), 10 - abs(j - k));
    ans += t;
  }
  cout << ans;
  return 0;
}
