#include <bits/stdc++.h>
using namespace std;
const long double pi = acos((long double)-1);
int main() {
  int64_t n, c, d;
  cin >> n >> c >> d;
  vector<long double> ang;
  for (int64_t i = 0; i < n; ++i) {
    int64_t r, w;
    cin >> r >> w;
    r -= c;
    w -= d;
    swap(r, w);
    ang.push_back(atan2(r, w));
    ang.push_back(2 * pi + atan2(r, w));
  }
  sort(ang.begin(), ang.end());
  int64_t ans = (n * (n - 1) * (n - 2)) / 6;
  int64_t a1 = 0, a2 = 0;
  for (int64_t i = 0; i < n; ++i) {
    while (ang[a1] - ang[i] < pi - 1e-17) {
      a1++;
    }
    while (ang[a2 + 1] - ang[i] < pi + 1e-17) a2++;
    ans -= (a2 - i) * (a2 - i - 1) / 2;
    ans += (a2 - a1) * (a2 - a1 + 1) / 2;
  }
  cout << ans;
}
