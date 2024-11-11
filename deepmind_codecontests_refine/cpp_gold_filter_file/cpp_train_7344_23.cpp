#include <bits/stdc++.h>
using namespace std;
int n, b, d;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> b >> d;
  int x, sum = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> x;
    sum += (x <= b ? x : 0);
    if (sum > d) {
      sum = 0;
      ans++;
    }
  }
  cout << ans;
  return 0;
}
