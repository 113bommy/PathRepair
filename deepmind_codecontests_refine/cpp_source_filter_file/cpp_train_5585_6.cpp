#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 77, Mod = 1e9 + 7;
int n, U, a[N];
long double A = -1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> U;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  a[n + 1] = Mod;
  for (int i = 1; i <= n; i++) {
    int pos = upper_bound(a + i, a + n + 2, U + a[i]) - a;
    pos--;
    if (a[pos] - a[i] > U || pos == i + 1) continue;
    A = max(A, (long double)(a[pos] - a[i + 1]) / (long double)(a[pos] - a[i]));
  }
  if (A == -1) return cout << -1, 0;
  cout << fixed << setprecision(13) << A;
  return 0;
}
