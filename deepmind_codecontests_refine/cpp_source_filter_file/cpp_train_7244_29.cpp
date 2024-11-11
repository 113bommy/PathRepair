#include <bits/stdc++.h>
using namespace std;
const int N = 250;
int t, a[N];
void read_input() {
  for (int i = 0; i < N; i++) cin >> a[i];
}
void solve() {
  int sum = 0, mx = 0;
  for (int i = 0; i < N; i++) {
    sum += a[i] * a[i];
    mx = max(mx, abs(a[i]));
  }
  cout << (mx > 2 * sqrt(1. * sum / N) ? "poisson" : "uniform");
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  for (cin >> t; t--; read_input(), solve())
    ;
  return 0;
}
