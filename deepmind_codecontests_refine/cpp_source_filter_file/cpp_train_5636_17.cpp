#include <bits/stdc++.h>
using namespace std;
int n, ar[10];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    ++ar[((i - 1) % 9 + 1)];
    ans -= n / i;
  }
  for (int i = 1; i <= 9; ++i)
    for (int j = 1; j <= 9; ++j)
      ans += ar[i] * ar[j] * ar[((i * j - 1) % 9 + 1)];
  cout << ans << endl;
}
