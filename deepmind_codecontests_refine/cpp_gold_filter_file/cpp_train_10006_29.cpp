#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0LL) return b;
  if (b == 0LL) return a;
  return gcd(b, a % b);
}
const int N = 200005;
void solve() {
  int n;
  int dx[] = {1, 0, -1, 0};
  int dy[] = {0, -1, 0, 1};
  cin >> n;
  cout << "0 0\n";
  n--;
  for (int i = 1;; i++) {
    if (n == 0) return;
    for (int j = 0; j < 4; j++) {
      if (n > 0) {
        cout << i * dx[j] << " " << i * dy[j] << "\n";
        n--;
      }
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  clock_t clk = clock();
  int t = 1;
  for (int tests = 1; tests <= t; tests++) {
    solve();
  }
  clk = clock() - clk;
  cerr << "Time Elapsed: " << fixed << setprecision(10)
       << ((long double)clk) / CLOCKS_PER_SEC << "\n";
  return 0;
}
