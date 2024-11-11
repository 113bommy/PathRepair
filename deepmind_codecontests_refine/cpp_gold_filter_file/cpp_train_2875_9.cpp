#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
constexpr int INF = 1e9;
constexpr long double eps = 1e-8;
int main() {
  int n, k;
  cin >> n >> k;
  int mi = 0, ma = 0;
  if (k == 0 || n == k) {
    mi = 0;
  } else {
    mi = 1;
  }
  if (2 * k > n - k) {
    ma = n - k;
  } else {
    ma = 2 * k;
  }
  cout << mi << ' ' << ma << endl;
}
