#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const long long nax = 200001;
void solve() {
  long long n;
  cin >> n;
  long long a[n], ans[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  long long x = 0;
  for (int i = 0; i < n; ++i) {
    long long temp = a[i], sum = a[i];
    vector<long long> v(n);
    v[i] = a[i];
    for (int j = i - 1; j >= 0; --j) {
      temp = min(temp, a[j]);
      v[j] = temp;
      sum += a[i];
    }
    temp = a[i];
    for (int j = i + 1; j < n; ++j) {
      temp = min(temp, a[j]);
      v[j] = temp;
      sum += a[i];
    }
    if (sum > x) {
      x = sum;
      for (int i = 0; i < n; ++i) {
        ans[i] = v[i];
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1, t1 = 1;
  while (t--) {
    solve();
  }
  return 0;
}
