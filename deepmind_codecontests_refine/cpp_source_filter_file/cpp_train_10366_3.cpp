#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> minVal(n, 1e9);
  int b;
  int i;
  int val;
  for (b = 0; b < 10; b++) {
    for (val = 0; val <= 1; val++) {
      vector<int> query;
      for (i = 1; i <= n; i++) {
        if (((i << b) & 1) == val) {
          query.push_back(i);
        }
      }
      if (query.size() != 0) {
        printf("%d\n", (int)query.size());
        for (int x : query) {
          printf("%d ", x);
        }
        printf("\n");
        fflush(stdout);
        for (i = 1; i <= n; i++) {
          int rd;
          scanf("%d", &rd);
          if (((i << b) & 1) != val) {
            minVal[i - 1] = min(minVal[i - 1], rd);
          }
        }
      }
    }
  }
  printf("%d\n", -1);
  for (int x : minVal) {
    printf("%d ", x);
  }
  printf("\n");
  fflush(stdout);
  return 0;
}
