#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const int MAXN = 100009;
int n, a[MAXN];
int main() {
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  long long tmp = 0;
  for (int i = 1; i <= n; ++i) {
    tmp += a[i];
    if (tmp * 2 >= sum) {
      printf("%d\n", i);
      break;
    }
  }
  return 0;
}
