#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, v;
  cin >> n >> v;
  int ans = 0;
  ans += min(n - 1, v);
  for (int i = 2; i <= n - v; i++) {
    ans += i;
  }
  cout << ans;
  return 0;
}
