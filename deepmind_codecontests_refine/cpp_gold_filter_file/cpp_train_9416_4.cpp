#include <bits/stdc++.h>
using namespace std;
int check(int array[], int n, int pro, int w, int m) {
  int value[n];
  int i;
  for (i = 0; i < n; i++) value[i] = 0;
  int pres = 0;
  for (i = 0; i < n; i++) {
    int req = pro - array[i] - pres;
    value[i] = req;
    value[i] = max(0, value[i]);
    pres = pres + value[i];
    if (i - w + 1 >= 0) pres = pres - value[i - w + 1];
  }
  long long sum = 0;
  for (i = 0; i < n; i++) sum += value[i];
  if (sum <= m) return 1;
  return 0;
}
int main() {
  int n, m, w;
  scanf("%d%d%d", &n, &m, &w);
  int array[n];
  int i, j;
  for (i = 0; i < n; i++) scanf("%d", &array[i]);
  int first = 0;
  int last = 1000100001;
  while (first < last) {
    int mid = (first + last) / 2;
    if ((first + last) % 2) mid += 1;
    if (check(array, n, mid, w, m))
      first = mid;
    else
      last = mid - 1;
  }
  printf("%d\n", first);
  return 0;
}
