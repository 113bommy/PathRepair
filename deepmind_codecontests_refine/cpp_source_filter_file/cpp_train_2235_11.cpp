#include <bits/stdc++.h>
using namespace std;
int ans1[1000], ans2[1000];
int main() {
  int a, b, h = 0, j = 0, Max1 = 0, Max, Max2 = 0;
  long long sum1 = 0, sum2 = 0;
  scanf("%d %d", &a, &b);
  while (a) {
    Max1 = max(Max1, a % 10);
    ans1[++h] = a % 10;
    a /= 10;
  }
  while (b) {
    Max2 = max(Max, b % 10);
    ans2[++j] = b % 10;
    b /= 10;
  }
  Max = max(Max1, Max2) + 1;
  for (int i = h; i >= 1; --i) {
    sum1 = sum1 * Max + ans1[i];
  }
  for (int i = j; i >= 1; --i) {
    sum1 = sum1 * Max + ans2[j];
  }
  long long sum = sum1 + sum2;
  int ans = 0;
  while (sum) {
    ans++;
    sum /= Max;
  }
  printf("%d\n", ans);
  return 0;
}
