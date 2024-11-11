#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, x;
  cin >> n >> x;
  if (x > 0) {
    int64_t up_1 = 0;
    int64_t res = 0;
    for (int64_t a; n > 0; --n) {
      cin >> a;
      up_1 = max((int64_t)0, up_1 + a);
      res = max(res, up_1);
    }
    cout << res * x;
  } else {
    int64_t up_1 = 0;
    int64_t down = 0;
    int64_t up_2 = 0;
    int64_t res = 0;
    for (int64_t a; n > 0; --n) {
      cin >> a;
      up_1 = max((int64_t)0, up_1 + a);
      down = max(up_1, down + a * x);
      up_2 = max(down, up_2 + a);
      res = max(max(res, up_1), max(down, up_2));
    }
    cout << res;
  }
  return 0;
}
