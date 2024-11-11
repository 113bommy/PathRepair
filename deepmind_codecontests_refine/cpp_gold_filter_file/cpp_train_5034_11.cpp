#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
long long pre[N], suf[N];
int n;
int a[N];
int main() {
  cin >> n;
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % 3 != 0) {
    cout << 0;
    return 0;
  }
  sum /= 3;
  long long num = 0;
  for (int i = 1; i <= n; ++i) {
    num += a[i - 1];
    pre[i] += pre[i - 1];
    if (num == sum) {
      pre[i]++;
    }
    if (num == 2 * sum) {
      suf[i] = 1;
    }
  }
  long long ans = 0;
  for (int i = 2; i < n; ++i) {
    if (suf[i]) {
      ans += pre[i - 1];
    }
  }
  cout << ans << endl;
  return 0;
}
