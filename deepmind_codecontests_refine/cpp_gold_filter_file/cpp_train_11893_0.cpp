#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 5;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;
const double PI = acos(-1.0);
void header() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void solve() {
  long long k;
  cin >> k;
  cout << "3 3\n";
  cout << (1ll << 17) + k << " " << k << " " << k << '\n';
  cout << (1ll << 17) << " " << (1ll << 17) << " " << (1ll << 17) + k << '\n';
  cout << (1ll << 17) << " " << (1ll << 17) << " " << k << '\n';
}
int main() {
  header();
  solve();
  return 0;
}
