#include <bits/stdc++.h>
using namespace std;
int n, x;
int main() {
  cin.tie(NULL);
  ios::sync_with_stdio(0);
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    ans += i * x;
  }
  cout << ans << endl;
}
