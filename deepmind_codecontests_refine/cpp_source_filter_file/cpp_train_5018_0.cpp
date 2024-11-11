#include <bits/stdc++.h>
using namespace std;
const int N = int(5e5) + 3;
const int LG = 20;
const long long mod = 1e9 + 7;
const int INF = 2147483647;
const long long linf = 1e18;
const long double pi = acos(-1);
const long double EPS = 1e-10;
const long long maxn = 1e5 + 7;
int n, m;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int h, t, b, y, bb = 0;
    int gg;
    cin >> t >> b;
    gg = abs(b - t);
    if (gg >= 5) {
      bb += gg / 5;
      gg = gg - (5 * bb);
    }
    if (gg >= 2) {
      bb += gg / 2;
      gg = gg - (h * 2);
    }
    if (gg == 1) {
      bb++;
    }
    cout << bb << "\n";
  }
}
