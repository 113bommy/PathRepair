#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long mod = 1e9 + 7;
int n, k, a[N], b[N];
bool check(int x) {
  int k1 = k, c = 0, f = 1;
  for (int i = 0; i < n; i++)
    if (a[i] <= x)
      b[i] = 0;
    else
      b[i] = 1;
  if (b[0] == 1) k1--;
  int i = 0;
  while (i < n) {
    if (b[i] == 0) {
      if (i == n - 1) f = 0;
      c++, i += 2;
    } else
      i++;
  }
  if (k1 % 2 == 0 && 2 * c > k1) return 1;
  if (k1 % 2 == 0 && 2 * c == k1 && f == 1) return 1;
  if (k1 % 2 && 2 * c >= k1 + 1) return 1;
  if (b[0] == 1) return 0;
  i = 1;
  c = 0;
  k1 = k - 1;
  f = 1;
  while (i < n) {
    if (b[i] == 0) {
      if (i == n - 1) f = 0;
      c++, i += 2;
    } else
      i++;
  }
  if (k1 % 2 == 0 && 2 * c > k1) return 1;
  if (k1 % 2 && 2 * c >= k1 + 1) return 1;
  if (k1 % 2 == 0 && 2 * c == k1 && f == 1) return 1;
  return 0;
}
void solve() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  int l = 1, r = 1e9;
  while (l + 1 < r) {
    int mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  if (l < r) {
    if (check(l))
      cout << l;
    else
      cout << r;
  } else {
    if (check(r))
      cout << r;
    else
      cout << l;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
