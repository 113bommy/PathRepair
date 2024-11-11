#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
using ll = long long;
int n, a[N], q[N], ptr;
ll sum[N], s2[N];
inline double X(int p) { return p; }
inline double Y(int p) { return p * sum[p] - s2[p]; }
double slope(int i, int j) { return (Y(i) - Y(j)) / (X(i) - X(j)); }
ll calc(int i, int j) { return s2[j] - s2[i] - i * (sum[j] - sum[i]); }
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i], sum[i] = sum[i - 1] + a[i], s2[i] = s2[i - 1] + a[i] * ll(i);
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ll k = sum[i];
    int l = 0, r = ptr - 1, p = ptr;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (slope(q[mid], q[mid + 1]) > k)
        l = mid + 1;
      else
        p = mid, r = mid - 1;
    }
    int t = q[p];
    ans = max(ans, calc(t, i));
    while (ptr > 1 && slope(q[ptr], q[ptr - 1]) < slope(q[ptr], i)) --ptr;
    q[++ptr] = i;
  }
  cout << ans << endl;
  return 0;
}
