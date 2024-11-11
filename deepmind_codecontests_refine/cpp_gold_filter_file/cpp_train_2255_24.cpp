#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, Q;
  cin >> n >> Q;
  long long i;
  long long a[200001], pre[200001], q[200001];
  pre[0] = 0;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    pre[i] = pre[i - 1] + a[i];
  }
  for (i = 1; i <= Q; i++) cin >> q[i];
  long long prev = 1;
  long long sub = 0;
  for (i = 1; i <= Q; i++) {
    long long k = q[i];
    long long lo = prev;
    long long hi = n;
    long long ans = -1;
    while (lo <= hi) {
      long long mid = (lo + hi) / 2;
      if (pre[mid] - sub <= k) {
        ans = mid;
        lo = mid + 1;
      } else
        hi = mid - 1;
    }
    if (ans == -1) {
      cout << n - lo + 1 << endl;
      sub += k;
    } else {
      if ((pre[ans] - sub) == k) {
        if (ans == n) {
          cout << n << endl;
          prev = 1;
          sub = 0;
        } else {
          cout << n - ans << endl;
          prev = ans + 1;
          sub = pre[ans];
        }
      } else {
        if (ans == n) {
          cout << n << endl;
          prev = 1;
          sub = 0;
        } else {
          cout << n - ans << endl;
          prev = ans + 1;
          sub += k;
        }
      }
    }
  }
  return 0;
}
