#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
const int mod = 1e9 + 7;
const int inf = 1e9 + 5;
int min(int a, int b) {
  if (a < b) return a;
  return b;
}
void solve() {
  long long n;
  cin >> n;
  long long int m1 = 1e6, m2 = 1e6, ans = 0;
  long long int a[n], b[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < m1) m1 = a[i];
  }
  for (long long i = 0; i < n; i++) {
    cin >> b[i];
    if (b[i] < m2) m2 = b[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    int d1 = a[i] - m1;
    int d2 = b[i] - m2;
    if (d2 < d1) {
      ans += d1;
    } else {
      ans += d2;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
