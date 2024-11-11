#include <bits/stdc++.h>
const double PI = 3.1415926535897932384626433;
const int KL = 1e6;
const long long MOD = 1e9 + 7;
using namespace std;
int q, x, y, z, n, m, a, b, ans;
string t;
vector<int> vec;
int main() {
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &n);
    scanf("%d", &a);
    scanf("%d", &b);
    if (a + b <= n - 2 && abs(a - b) <= 1) {
      if (a == b + 1) {
        int cnt = n - 1;
        while (a > 0) {
          printf("%d %d ", cnt, cnt + 1);
          cnt -= 2;
          a -= 1;
        }
        for (int i = cnt + 1; i >= 1; i--) printf("%d ", i);
        printf("\n");
      } else if (a == b) {
        int cnt = a + b;
        while (a > 0) {
          printf("%d %d ", cnt, cnt + 1);
          cnt -= 2;
          a--;
        }
        printf("1 ");
        for (int i = b + b + 2; i <= n; i++) printf("%d ", i);
        printf("\n");
      } else {
        int cnt = 2;
        while (b > 0) {
          printf("%d %d ", cnt, cnt - 1);
          cnt += 2;
          b--;
        }
        for (int i = cnt - 1; i <= n; i++) printf("%d ", i);
        printf("\n");
      }
    } else
      printf("-1\n");
  }
  return 0;
}
