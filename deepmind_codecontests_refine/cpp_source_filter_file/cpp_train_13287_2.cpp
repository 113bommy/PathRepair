#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, a, b;
  cin >> n >> a >> b;
  long long ans = 1;
  for (int i = 1; i < min(a, b); i++) {
    if (((a / i) + (b / i)) >= n) {
      ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}
