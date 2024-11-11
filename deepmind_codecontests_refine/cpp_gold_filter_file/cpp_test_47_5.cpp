#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2 * 1e5 + 7;
const int INF = 1e10 + 7;
const int MOD = 1e9 + 7;
const int LOG = 22;
long long a[MAX_N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    vector<long long> v;
    long long ans = 0, p = n;
    for (int i = 0; i < n; i++) {
      if (a[i] >= 0) {
        p = i;
        break;
      }
    }
    long long MIN = INF, MAX = 0;
    for (int i = 0; i < p; i += k) {
      MIN = INF;
      if (i + k - 1 >= p) {
        for (int j = i; j < p; j++) MIN = min(MIN, a[j]);
      } else {
        for (int j = i; j < i + k; j++) MIN = min(MIN, a[j]);
      }
      v.push_back(abs(MIN));
    }
    for (int i = n - 1; i >= p; i -= k) {
      MAX = 0;
      if (i - k + 1 < p) {
        for (int j = i; j >= p; j--) MAX = max(MAX, a[j]);
      } else {
        for (int j = i; j > i - k; j--) MAX = max(MAX, a[j]);
      }
      v.push_back(MAX);
    }
    sort(v.begin(), v.end());
    for (int x : v) ans += (2 * x);
    ans -= v[v.size() - 1];
    cout << ans << '\n';
    v.clear();
  }
}
