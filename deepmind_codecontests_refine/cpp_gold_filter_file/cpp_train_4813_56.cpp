#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int a[12017], c[12017];
vector<int> v;
int main() {
  int T;
  scanf("%d", &T);
  int len, res, A, B, C, val_a, val_c, ans;
  while (T--) {
    scanf("%d%d%d", &A, &B, &C);
    res = INF;
    ans = 0;
    for (int b = 1; b <= 12000; ++b) {
      if (abs(B - b) > res) continue;
      v.clear();
      len = sqrt(b);
      val_a = val_c = INF;
      for (int i = 1; i <= len; ++i)
        if (b % i == 0) v.push_back(i), v.push_back(b / i);
      for (auto x : v)
        if (abs(A - x) < val_a) a[b] = x, val_a = abs(A - x);
      int tmp = C / b;
      val_c = abs(C - b), c[b] = b;
      if (val_c > abs(C - b * (tmp + 1)))
        val_c = abs(C - b * (tmp + 1)), c[b] = b * (tmp + 1);
      if (tmp > 0 && val_c > abs(C - b * tmp))
        val_c = abs(C - b * tmp), c[b] = b * tmp;
      if (tmp > 1 && val_c > abs(C - b * (tmp - 1)))
        val_c = abs(C - b * (tmp - 1)), c[b] = b * (tmp - 1);
      if (abs(A - a[b]) + abs(b - B) + abs(C - c[b]) < res) {
        res = abs(A - a[b]) + abs(b - B) + abs(C - c[b]);
        ans = b;
      }
    }
    printf("%d\n%d %d %d\n", res, a[ans], ans, c[ans]);
  }
}
