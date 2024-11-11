#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream &operator<<(ostream &cout, vector<T> &a) {
  for (size_t i = 0; i < a.size(); ++i) cout << a[i] << " ";
  return cout;
}
template <typename T>
ostream &operator<<(ostream &cout, vector<vector<T> > &a) {
  for (size_t i = 0; i < a.size(); ++i) cout << a[i] << endl;
  return cout;
}
long long a[200000];
int main() {
  ios_base::sync_with_stdio(0);
  long long n, k;
  cin >> n >> k;
  long long sum = 0;
  int start = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[start] == 0) ++start;
    sum = max(sum, a[i]);
  }
  if (sum >= k) {
    cout << 0 << endl;
    return 0;
  } else if (start == n - 2) {
    cout << (k - a[n - 1] + a[n - 2] - 1) / a[n - 2] << endl;
    return 0;
  } else if (start == n - 3) {
    k -= a[n - 1];
    long long l = -1, r = sqrt(k / a[n - 3]) + 1, m;
    while (r - l > 1) {
      m = (r + l) / 2;
      if ((2 * a[n - 2] + (m + 1) * a[n - 3]) * m >= 2 * k)
        r = m;
      else
        l = m;
    }
    cout << r << endl;
    return 0;
  }
  int ans = 0;
  for (ans = 0; sum < k; ++ans) {
    sum = 0;
    for (int i = start; i < n; ++i) {
      sum += a[i];
      a[i] = sum;
      if (sum >= k) {
        cout << ans + 1 << endl;
        return 0;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
