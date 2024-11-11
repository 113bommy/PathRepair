#include <bits/stdc++.h>
using namespace std;
int num[1005];
int minn, t;
int main() {
  int n, sum;
  minn = 666666;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
  for (int i = 1; i <= 100; i++) {
    sum = 0;
    for (int j = 1; j <= n; j++) {
      if (num[j] > i) sum += num[j] - (i + 1);
      if (num[j] < i) sum += (i - 1) - num[j];
    }
    if (sum < minn) {
      minn = sum;
      t = i;
    }
  }
  printf("%d %d\n", t, sum);
  return 0;
}
