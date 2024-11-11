#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e18;
const int MX = 2e5 + 5;
int n;
int a[MX];
long long c, r;
long long res = 0;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = (1); i <= (n); i++) cin >> a[i];
  sort(a + 1, a + n + 1, greater<int>());
  int m = (n + 1) / 2;
  for (int i = (1); i <= (m); i++) c += a[i];
  for (int i = (m + 1); i <= (n); i++) r += a[i];
  res = c * c + r * r;
  cout << res;
}
