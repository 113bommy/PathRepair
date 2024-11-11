#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main() {
  int rec;
  int min = 0x3f3f3f3f;
  int sum = 0;
  int num;
  scanf("%d", &num);
  for (int i = 0; i < num; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a + num);
  for (int i = a[0]; i <= a[num - 1]; i++) {
    sum = 0;
    for (int j = 0; j < num; j++) {
      if (abs(a[j] - i) <= 1)
        sum += 0;
      else
        sum += abs(a[j] - i) - 1;
    }
    if (sum < min) {
      min = sum;
      rec = i;
    }
  }
  printf("%d %d\n", rec, min);
  return 0;
}
