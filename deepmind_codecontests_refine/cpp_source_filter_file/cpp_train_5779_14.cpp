#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int n, ans;
bool judge(int x) {
  if (x == 2) return true;
  for (int i = 2; i * i < x; ++i)
    if (x % i == 0) return false;
  return true;
}
int main(int argc, char const *argv[]) {
  scanf("%d", &n);
  if (n == 3) {
    printf("1\n");
    printf("3\n");
    return 0;
  }
  if (n == 5) {
    printf("2\n");
    printf("2 3\n");
    return 0;
  }
  n -= 3;
  for (int i = 2; i <= n / 2; ++i)
    if (judge(i) && judge(n - i)) {
      ans = i;
      break;
    }
  printf("3\n");
  printf("3 %d %d\n", ans, n - ans);
  return 0;
}
