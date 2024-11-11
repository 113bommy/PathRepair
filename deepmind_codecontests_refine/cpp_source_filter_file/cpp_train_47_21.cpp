#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1.0);
const double EPS = 1E-6;
const int INF = 2 * (1e+9) + 1;
const int MAXN = 3 * 100000001;
const int MOD = (1e+9) + 7;
int n;
pair<int, int> x[100100];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < (n); ++i) {
    cin >> x[i].first >> x[i].second;
  }
  sort(x, x + n);
  int cnt = 1, r = 0;
  for (int i = (1); i <= (n - 1); ++i) {
    if (r && x[i - 1].first + x[i - 1].second > x[i].first) {
      r = 0;
    } else if (r)
      cnt++;
    if (!r && x[i].first - x[i - 1].first >= x[i].second) {
      cnt++;
    } else {
      if (x[i].first - x[i - 1].first >= x[i].second + x[i - 1].second) {
        cnt++, r = 0;
      } else {
        r = 1;
      }
    }
  }
  if (r) cnt++;
  cout << cnt;
  return 0;
}
