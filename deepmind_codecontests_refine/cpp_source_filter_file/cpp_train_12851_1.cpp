#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a[100], temp = -1, max = -1, li = 0;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    temp = ceil((float)a[i] / m);
    if (temp >= max && i > li) {
      max = temp;
      li = i;
    }
  }
  printf("%d", li + 1);
  return 0;
}
