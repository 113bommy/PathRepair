#include <bits/stdc++.h>
using namespace std;
const long long LINF = (long long)1e18 + 47;
const int INF = 1e9 + 47;
const int MOD = 1e9 + 7;
const int modulo = 1e8;
const int nax = 3 * (int)1e5 + 10;
const double EPS = 1e-9;
const double PI = acos(-1.0);
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  int tt;
  cin >> tt;
  for (int test = (1); test < (tt + 1); test++) {
    int n;
    cin >> n;
    int cnt = n / 4 + (n % 4 == 0 ? 0 : 1);
    for (int i = (0); i < (n - cnt); i++) cout << 9;
    for (int i = (0); i < (cnt); i++) cout << 8;
    cout << endl;
  }
}
