#include <bits/stdc++.h>
using namespace std;
long long n, k, l;
long long a[100005];
void solve() {
  if (a[n - 1] - a[0] > l) {
    cout << 0 << endl;
    return;
  }
  long long num = 0;
  for (long long i = n; i < n * k; i++) {
    if (a[i] - a[0] <= l) {
      num++;
    } else {
      break;
    }
  }
  long long ans = 0, c = n, i = 0;
  while (num > 0) {
    ans += a[i];
    c--;
    if (num >= k) {
      num -= k;
      i += k;
    } else {
      i += num + 1;
      num = 0;
    }
  }
  while (c) {
    ans += a[i];
    i++;
    c--;
  }
  cout << ans << endl;
}
int main() {
  cin >> n >> k >> l;
  for (long long i = 0; i < n * k; i++) {
    cin >> a[i];
  }
  sort(a, a + n * k);
  solve();
}
