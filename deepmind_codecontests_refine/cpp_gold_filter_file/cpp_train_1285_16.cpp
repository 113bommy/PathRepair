#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3fLL;
const double err = 1e-9;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
ll fexp() {}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  ll k, b, n, t;
  cin >> k >> b >> n >> t;
  ll z = 1;
  ll s = 0;
  while (z * k + b <= t) {
    z *= k;
    z += b;
    s++;
  }
  cout << max(n - s, 0LL) << endl;
  return 0;
}
