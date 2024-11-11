#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int a[n + 1];
  int b[m + 1];
  int zeroes = 0;
  int next_index, prev_element;
  int g = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (a[i] == 0) {
      prev_element = i - 1;
      next_index = i + 1;
      continue;
    }
    if (i > 1) {
      if (a[i] < a[i - 1]) g = 1;
    }
  }
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
  if (g == 1)
    printf("Yes\n");
  else if (m > 1)
    printf("Yes\n");
  else {
    if (next_index == 2) {
      if (b[1] > a[next_index])
        printf("Yes\n");
      else
        printf("No\n");
    } else if (prev_element == n - 1) {
      if (a[prev_element] > b[1])
        printf("Yes\n");
      else
        printf("No\n");
    } else if (a[next_index] < b[1] || a[prev_element] > b[1])
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
