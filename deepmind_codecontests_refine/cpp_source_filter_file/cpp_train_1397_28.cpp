#include <bits/stdc++.h>
using namespace std;
long long mem[101][10001];
long long n, k;
long long a[101], b[101];
long long solve(long long idx, long long sum) {
  long long &ret = mem[idx][sum];
  if (idx == n) {
    if (sum == 0) {
      return 0;
    }
    return -INFINITY;
  }
  if (ret != -1) return ret;
  ret = solve(idx + 1, sum);
  ret = max(ret, solve(idx + 1, sum + a[idx] - b[idx] * k) + a[idx]);
  return ret;
}
int main() {
  memset(mem, -1, sizeof(mem));
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  long long s = solve(0, 0);
  if (s <= 0)
    cout << -1;
  else
    cout << s;
  return 0;
}
