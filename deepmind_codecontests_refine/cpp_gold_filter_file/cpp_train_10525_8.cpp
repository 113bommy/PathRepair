#include <bits/stdc++.h>
using namespace std;
unsigned long long n, t, x;
unsigned long long arrive[200005], mx_arrive[200005], mx_pos[200005], b[200005];
void solve() {
  b[n] = 3 * (1e18);
  for (int i = n - 1; i >= 1; i--) {
    b[i] = min(b[i + 1] - 1, mx_arrive[i]);
    if (mx_pos[i] == mx_pos[i + 1] && b[i] < arrive[i + 1]) {
      cout << "No";
      return;
    }
  }
  cout << "Yes\n";
  for (int i = 1; i <= n; i++) cout << b[i] << " ";
}
int main() {
  cin >> n >> t;
  mx_arrive[n + 1] = 3 * (1e18);
  arrive[n + 1] = 3 * (1e18);
  mx_arrive[n + 1]++;
  arrive[n + 1]++;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    arrive[i] = x + t;
    mx_arrive[i] = 3 * (1e18);
  }
  for (int i = 1; i <= n; i++) {
    cin >> mx_pos[i];
    if (mx_pos[i] < i || mx_pos[i] < mx_pos[i - 1]) {
      cout << "No";
      return 0;
    }
    if (mx_pos[i] < n) mx_arrive[mx_pos[i]] = arrive[mx_pos[i] + 1] - 1;
  }
  solve();
  return 0;
}
