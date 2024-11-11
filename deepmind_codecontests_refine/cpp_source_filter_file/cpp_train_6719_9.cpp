#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const long long N = 1e5 + 7;
const double pi = 2 * acos(0.0);
void solve() {
  int n, a, t[101];
  cin >> n >> a;
  for (int i = 0; i < n; i++) cin >> t[i];
  int i, j, count = 0;
  i = a - 2;
  j = a;
  if (t[a - 1] == 1) count++;
  while (i > 0 || j < n) {
    if (i < 0 && j < n && t[j] == 1) {
      count++;
      j++;
      continue;
    } else if (i >= 0 && j > n - 1 && t[i] == 1) {
      count++;
      i--;
      continue;
    } else if (t[i] == t[j] && t[i] == 1) {
      count += 2;
    }
    if (i >= 0) i--;
    if (j < n) j++;
  }
  cout << count;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long test = 1;
  while (test-- > 0) {
    solve();
  }
}
