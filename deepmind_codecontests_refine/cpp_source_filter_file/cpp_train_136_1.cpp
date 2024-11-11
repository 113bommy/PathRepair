#include <bits/stdc++.h>
using namespace std;
const int MAX = 50005;
const int inf = (1) << 30;
bool check(int res, int a, int b, int c) {
  int tot = a * c;
  int have = res * b;
  for (int i = 1; i <= c; i++) {
    have += b;
    if (have < a * i) return false;
  }
  return true;
}
int main() {
  int i, j, k, a, b, c;
  while (scanf("%d%d%d", &a, &b, &c) != EOF) {
    int res = 0;
    int l = 0, r = (1 << 23), mid;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (check(mid, a, b, c)) {
        res = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    cout << res << endl;
  }
  return 0;
}
