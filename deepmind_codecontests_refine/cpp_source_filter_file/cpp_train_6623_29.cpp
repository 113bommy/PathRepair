#include <bits/stdc++.h>
using namespace std;
int n, k, x, a[101], ans;
void input() {
  cin >> n >> k >> x;
  for (int i = 1; i <= n; i++) cin >> a[i];
}
void output() { cout << ans; }
void solve() {
  int S = 0;
  for (int i = 1; i <= n - k; i++) {
    S += a[i];
    ans = S + k * x;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  input();
  solve();
  output();
}
