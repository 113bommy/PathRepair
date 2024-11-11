#include <bits/stdc++.h>
using namespace std;
long long a[200001];
stack<int> s;
long long l[200001];
long long r[200001];
long long ans;
int main() {
  long long n, k, x;
  cin >> n >> k >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (i > n - k) {
      ans += min(a[i], x);
    } else
      ans += a[i];
  }
  cout << ans;
  return 0;
}
