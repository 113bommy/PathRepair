#include <bits/stdc++.h>
const int N = 100 + 10;
int arr[N];
int main() {
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
    int t = n / m;
    for (int i = 0; i < m; ++i) arr[i] = t;
    int num = n - t * m;
    for (int i = 0; i < num; ++i) arr[i]++;
    bool first = true;
    for (int i = 0; i < m; ++i) {
      if (first)
        printf("%d", arr[i]);
      else
        printf(" %d", arr[i]);
      first = false;
    }
    printf("\n");
  }
  return 0;
}
