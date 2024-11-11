#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int mod = 1e9 + 7;
const int inf = 1061109567;
const int dir[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int main() {
  int n, h1, h2, w1, w2;
  cin >> n >> h1 >> h2 >> w1 >> w2;
  if (w1 < w2) {
    swap(w1, w2);
    swap(h1, h2);
  }
  long long ans = 0;
  if (w1 >= sqrt(n * 1.0)) {
    for (int i = 0; i <= n / w1; i++) {
      ans = max(ans, 1LL * i * h1 + (n - i * w1) / w2 * h2);
    }
  } else {
    if (h1 * 1.0 / w1 > h2 * 1.0 / w2) {
      swap(w1, w2);
      swap(h1, h2);
    }
    for (int i = 0; i <= w1; i++) {
      ans = max(ans, 1LL * i * h1 + (n - i * w1) / w2 * h2);
    }
  }
  cout << ans << endl;
}
