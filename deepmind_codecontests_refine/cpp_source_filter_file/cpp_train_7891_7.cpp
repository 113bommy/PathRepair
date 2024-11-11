#include <cstdio>

#include <algorithm>

using namespace std;

int main() {
  long long a;
  int ans = 1000;
  scanf("%lld", &a);
  while (a > 99) {
    ans = min(ans, abs(753 - a % 1000));
    a /= 10;
  }
  printf("%d\n", ans);
  return 0;
}
