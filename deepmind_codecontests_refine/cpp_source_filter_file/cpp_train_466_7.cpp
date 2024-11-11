#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int m[5], w[5], hs, hu;
  for (int i = 0; i < 5; ++i) {
    scanf("%d", &m[i]);
  }
  for (int i = 0; i < 5; ++i) {
    scanf("%d", &w[i]);
  }
  scanf("%d %d", &hs, &hu);
  int sum = 0;
  for (int i = 0; i < 5; ++i) {
    int x = 500 * (i + 1);
    sum += max(0.3 * x, (1 - m[i] / 250.0) * x - 50 * w[i]);
  }
  sum += hs * 100 - hu * 50;
  printf("%d\n", sum);
  return 0;
}
