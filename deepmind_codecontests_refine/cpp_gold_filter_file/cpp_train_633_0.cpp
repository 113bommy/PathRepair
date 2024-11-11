#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  long long ans = 0;
  for (int i = 2; i <= n; i++) {
    for (int j = i + i; j <= n; j += i) {
      ans += j / i;
    }
  }
  cout << ans * 4 << endl;
  return 0;
}
