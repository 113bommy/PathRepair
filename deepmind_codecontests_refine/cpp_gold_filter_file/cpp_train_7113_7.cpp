#include <bits/stdc++.h>
using namespace std;
void afify() {
  ios::sync_with_stdio(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const long long oo = (long long)1e13;
vector<long long> v, v2, v3;
long long n, k, tmp;
bool ok(long long mid) {
  long long res = mid;
  while (mid > 0) {
    mid /= k;
    res += mid;
  }
  if (res < n) {
    return 1;
  } else
    return 0;
}
int main() {
  afify();
  cin >> n >> k;
  long long l = 0, r = 1e15, ans = 0;
  while (l < r) {
    long long mid = (l + r) / 2;
    if (ok(mid)) {
      l = mid + 1;
      ans = mid;
    } else
      r = mid - 1;
  }
  while (ok(ans)) ans++;
  ans--;
  cout << ans + 1 << endl;
  return 0;
}
