#include <bits/stdc++.h>
using namespace std;
template <typename T>
using matrix = vector<vector<T>>;
const long long INFL = (1LL << 62) - 1;
const int INF = (1 << 30) - 1;
const double EPS = 1e-7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 1;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int avg = 0;
    vector<int> v(250);
    int maxi = 0;
    int last;
    for (int i = 0; i < 250; i++)
      cin >> v[i], avg += v[i], maxi = max(maxi, v[i]);
    avg /= 250;
    double dev = 0;
    for (int i = 0; i < 250; i++) dev += (v[i] - avg) * (v[i] - avg);
    dev /= 250;
    if (dev / avg > 2) {
      cout << maxi / 2 << '\n';
      last = maxi / 2;
    } else {
      cout << avg << '\n';
      last = avg;
    }
  }
  return 0;
}
