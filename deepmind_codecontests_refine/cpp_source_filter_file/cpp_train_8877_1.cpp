#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, k, q;
const int INF = 1e9 + 5;
const int nax = 1e5 + 5;
void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << min(a + b, c + d) << "\n";
}
int main() {
  {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  };
  int test_case = 1;
  cin >> test_case;
  while (test_case--) {
    solve();
  }
}
