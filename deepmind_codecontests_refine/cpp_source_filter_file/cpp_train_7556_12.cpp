#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
constexpr int N = 2e5 + 5;
int n;
void Solve() {
  cin >> n;
  ll m = 1;
  while (m * 10 < n) m *= 10;
  if (n / m == 9) {
    m *= 10;
  }
  cout << m - (n % m);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  Solve();
  return 0;
}
