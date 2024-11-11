#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10 + 1e5;
const int MOD = 1e9 + 7;
int n, m;
int a[MAXN], c[MAXN];
void Inout() {
  freopen(
      "ABC"
      ".inp",
      "r", stdin);
  freopen(
      "ABC"
      ".out",
      "w", stdout);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    c[i] = max(c[i - 1], a[i] + 1);
  }
  for (int i = 1; i <= n; ++i) c[i] = max(c[i], c[i + 1] - 1);
  for (int i = 1; i <= n; ++i) {
    ans += c[i] - a[i] - 1;
  }
  cout << ans;
  return 0;
}
