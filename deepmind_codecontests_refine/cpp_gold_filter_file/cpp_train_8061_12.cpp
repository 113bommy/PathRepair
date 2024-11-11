#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int PR = 727;
const int INF = INT_MAX;
const long long LINF = LLONG_MAX;
const int N = 1e5 + 20;
long long n, m, a[N], b[N];
long long first(int k) {
  long long res = 0;
  for (int i = 0; i < n; i++)
    if (a[i] < k)
      res += k - a[i];
    else
      break;
  for (int i = m - 1; i >= 0; i--)
    if (b[i] > k)
      res += b[i] - k;
    else
      break;
  return res;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + m);
  int l = 0, r = 1e9 + 20;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    (first(mid) > first(mid - 1) ? r : l) = mid;
  }
  cout << first(l) << endl;
}
