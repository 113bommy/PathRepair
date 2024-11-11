#include <bits/stdc++.h>
using namespace std;
int n, h, a, ans;
int main() {
  cin >> n >> h;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    if (a > h) ans++;
    ans++;
  }
  cout << ans << "\n";
}
