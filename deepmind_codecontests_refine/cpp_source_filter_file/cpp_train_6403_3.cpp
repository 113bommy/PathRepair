#include <bits/stdc++.h>
const long double EPS = (-1e-10);
using namespace std;
const int N = 1e3 + 10, NN = 4e5 + 10;
int c[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  long double x, y, mn = 2e4;
  vector<pair<long double, int> > ans;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    complex<long double> xx = {x, y};
    ans.push_back({(atan2((xx).imag(), (xx).real())) + 2 * acos(-1), i + 1});
    if (ans.back().first >= 2 * acos(-1)) ans.back().first -= 2 * acos(-1);
  }
  sort(ans.begin(), ans.end());
  int a, b;
  for (int i = 0; i < n; i++) {
    if (min(abs(ans[i].first - ans[(i + 1) % n].first),
            2 * acos(-1) - abs(ans[i].first - ans[(i + 1) % n].first)) -
            mn <=
        EPS) {
      mn = min(abs(ans[i].first - ans[(i + 1) % n].first),
               2 * acos(-1) - abs(ans[i].first - ans[(i + 1) % n].first));
      a = ans[i].second;
      b = ans[(i + 1) % n].second;
    }
  }
  cout << a << " " << b;
}
