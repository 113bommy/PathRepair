#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
const long long inf = 998244353;
long long n, m;
long long ans = 0;
int main() {
  cin >> n >> m;
  int x1 = 1, y1 = 1;
  int x2 = n, y2 = m;
  bool flag = 0;
  bool flag1 = 1;
  bool flag2 = 1;
  while (ans < n * m) {
    if (flag) {
      printf("%d %d\n", x2, y2);
      if (flag2) {
        y2--;
        if (y2 == 0) {
          y2 = 1;
          x2--;
          flag2 = 0;
        }
      } else {
        y2++;
        if (y2 > m) {
          y2 = m;
          x2--;
          flag2 = 1;
        }
      }
      ans++;
    } else {
      printf("%d %d\n", x1, y1);
      if (flag1) {
        y1++;
        if (y1 > m) {
          x1++;
          y1 = m;
          flag1 = 0;
        }
      } else {
        y1--;
        if (y1 == 0) {
          x1++;
          y1 = 1;
          flag1 = 1;
        }
      }
      ans++;
    }
    if (flag)
      flag = false;
    else
      flag = true;
  }
  return 0;
}
