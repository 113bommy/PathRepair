#include <bits/stdc++.h>
using namespace std;
int T[100000];
int main() {
  int sum, n, m;
  int t[1000];
  while (~scanf("%d", &n)) {
    memset(T, 0, sizeof(T));
    sum = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &t[i]);
      sum += t[i];
    }
    scanf("%d", &m);
    int a, b;
    while (m--) {
      scanf("%d%d", &a, &b);
      for (int i = a; i <= b; i++) {
        T[i] = 1;
      }
    }
    if (sum > b)
      printf("-1\n");
    else {
      for (int i = sum; 1; i++) {
        if (T[i]) {
          printf("%d\n", T[i]);
          break;
        }
      }
    }
  }
  return 0;
}
