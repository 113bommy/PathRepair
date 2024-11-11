#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
const int INF = 1 << 30;
int Min[4], Max[4], ans[4];
int main() {
  int n;
  int total;
  while (scanf("%d", &n) != EOF) {
    total = 0;
    for (int i = 1; i <= 3; ++i) {
      scanf("%d%d", &Min[i], &Max[i]);
      ans[i] = Max[i];
      total += Max[i];
    }
    for (int i = 3; i >= 1; --i) {
      int tmp = total - n;
      if (ans[i] - tmp >= Min[i]) {
        ans[i] -= tmp;
        break;
      } else {
        ans[i] = Min[i];
      }
      total -= Max[i] - Min[i];
    }
    printf("%d %d %d\n", ans[1], ans[2], ans[3]);
  }
  return 0;
}
