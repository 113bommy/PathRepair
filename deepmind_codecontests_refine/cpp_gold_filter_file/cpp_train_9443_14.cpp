#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long a[100];
int n, k;
inline bool check(long long num, int id = 0, int cnt = 0) {
  if (id >= n)
    return (cnt == k);
  else if (cnt >= k)
    return false;
  else if (n - id < k - cnt)
    return false;
  long long sum = 0;
  for (int i = id; i < n; i++) {
    sum += a[i];
    if ((sum & num) == num)
      if (check(num, i + 1, cnt + 1)) return true;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  long long ans = 0;
  for (int i = 59; i >= 0; i--)
    if (check(ans + (long long)((long long)1 << i)))
      ans += (long long)((long long)1 << i);
  cout << ans;
  return 0;
}
