#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 4;
bool possible(long long n, int k) { return 1LL * k * (k + 1) / 2 <= n; }
int main() {
  long long n, ans = -1, k;
  cin >> n >> k;
  if (n <= k || k > 2e5) return cout << -1, 0;
  for (int i = 1; 1LL * i * i <= n; ++i)
    if (n % i == 0) {
      if (possible(i, k)) ans = max(ans, n / i);
      if (possible(n / i, k)) ans = max(ans, 1LL * i);
    }
  if (ans == -1) return cout << -1, 0;
  long long sum = 0;
  for (int i = 1; i < k; ++i) {
    cout << i * ans << " ";
    sum += i * ans;
  }
  cout << n - sum;
  return 0;
}
