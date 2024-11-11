#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int main() {
  int n, a[maxn];
  cin >> n;
  long long sum = 0, ans = 0;
  int maxx = INT_MIN, minn = INT_MAX;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += 1LL * a[i];
    maxx = max(maxx, a[i]);
    minn = min(minn, a[i]);
    ans += 1LL * abs(a[i]);
  }
  bool neg = true, pos = true;
  for (int i = 1; i <= n; i++) {
    if (a[i] > 0) neg = false;
    if (a[i] < 0) pos = false;
  }
  if (n > 1) {
    if (neg) {
      ans = 2LL * maxx - 1LL * sum;
    } else if (pos) {
      ans = 1LL * sum - 2LL * minn;
    }
  } else
    ans = sum;
  cout << ans << endl;
}
