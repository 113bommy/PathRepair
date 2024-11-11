#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
long long m, ans;
long long cal(long long mid) {
  ans = 0;
  for (long long k = 2; k <= mid && k * k <= mid && k * k * k <= mid; k++)
    ans += mid / (k * k * k);
  return ans;
}
int main() {
  cin >> m;
  long long l = 0, r = 2e16;
  while (l < r) {
    long long mid = (l + r) / 2;
    if (cal(mid) >= m)
      r = mid;
    else
      l = mid + 1;
  }
  if (cal(l) == m)
    cout << l << endl;
  else
    cout << -1 << endl;
}
