#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    for (int j = i + i; j <= n; j += i) ans += j / i;
  }
  cout << ans * 4;
  return 0;
}
