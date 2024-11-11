#include <bits/stdc++.h>
using namespace std;
int ans, k;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    k = max(k, a);
    ans += a;
  }
  cout << ans - k + 1;
  return 0;
}
