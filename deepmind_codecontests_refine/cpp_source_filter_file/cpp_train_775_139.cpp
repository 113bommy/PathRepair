#include <bits/stdc++.h>
using namespace std;
int main() {
  int n1, n2, k1, k2;
  cin >> n1 >> n2 >> k1 >> k2;
  string ans = (n1 < n2) ? "Second" : "First";
  cout << ans << '\n';
  return 0;
}
