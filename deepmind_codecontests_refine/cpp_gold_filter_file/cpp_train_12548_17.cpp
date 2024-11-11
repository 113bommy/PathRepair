#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
int a[maxn], dp[maxn], dp2[maxn];
int main() {
  int n;
  cin >> n;
  if (n == 2) {
    cout << -1;
    return 0;
  }
  cout << "22\n33\n";
  long long x = 2;
  for (int i = 1; i <= n - 2; i++, x *= 2) cout << 3LL * x << "\n";
  return 0;
}
