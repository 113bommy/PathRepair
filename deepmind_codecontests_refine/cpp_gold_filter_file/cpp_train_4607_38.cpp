#include <bits/stdc++.h>
using namespace std;
typedef long long int i64;
const double PI = 3.141592653589793238463;
const int MAXN = 1000500;
const int MAXVALUE = 1000000500;
const long double EPS = 1e-7;
const i64 INF = 1e18;
i64 mod = 1e9 + 7;
i64 T, n, m, k, q;
vector<i64> a;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(16);
  cin >> T;
  for (i64 tt = 0; tt < T; ++tt) {
    i64 a, b;
    cin >> a >> b;
    cout << a + b << endl;
  }
  return 0;
}
