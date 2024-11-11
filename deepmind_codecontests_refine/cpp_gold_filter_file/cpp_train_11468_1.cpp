#include <bits/stdc++.h>
using namespace std;
const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, 0, 1, -1};
const int maxn = 2 * 1e5;
const int mod = 998244353;
const int maxa = 2 * 1e5;
int m = 1e9, M = -1, n, A[maxn], res[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> A[i];
  for (int i = 0; i < n; ++i) {
    if (m <= A[i] && M >= A[i]) return cout << "NO\n", 0;
    if (m > A[i] && M < A[i]) {
      if (i < n - 1 && A[i + 1] > A[i])
        res[i] = 0;
      else
        res[i] = 1;
    } else
      res[i] = m > A[i];
    (res[i] ? m : M) = A[i];
  }
  cout << "YES\n";
  for (int i = 0; i < n; ++i) cout << res[i] << ' ';
}
