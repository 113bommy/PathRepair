#include <bits/stdc++.h>
using namespace std;
const int N = 1000000;
const int inf = (int)1e9 + 1;
const long long big = (long long)1e18 + 1;
const int P = 239;
const int MOD = (int)1e9 + 7;
const int MOD1 = (int)1e9 + 9;
const double eps = 1e-9;
const double pi = atan2(0, -1);
const int ABC = 26;
int F[N];
void add(int x) {
  for (; x < N; x = (x | (x + 1))) F[x]++;
}
int get(int x) {
  int res = 0;
  for (; x >= 0; x = (x & (x + 1)) - 1) res += F[x];
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(20);
  int n, T;
  cin >> n >> T;
  T--;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans = 0;
  pair<int, int> b[n];
  for (int i = 0; i < n; i++) b[i] = {max(0, a[i] - (i + 1)), i};
  sort(b, b + n);
  for (int i = 0; i < n; i++) {
    add(b[i].second);
    ans = max(ans, get(min(N - 1, T - b[i].first - 1)));
  }
  cout << ans << "\n";
  return 0;
}
