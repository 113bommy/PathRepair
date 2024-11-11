#include <bits/stdc++.h>
using namespace std;
const int size = 2e5 + 7;
const int maxm = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b, c;
  cin >> b >> a >> c;
  int n, x, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x > a && x < c) ans++;
  }
  cout << ans;
  return 0;
}
