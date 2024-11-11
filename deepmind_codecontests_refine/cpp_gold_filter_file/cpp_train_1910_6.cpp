#include <bits/stdc++.h>
using namespace std;
int maxans[1000005];
long long x[255];
long long y[255];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%lld%lld", &x[i], &y[i]);
  }
  for (int i = 1; i <= n; i++) {
    maxans[i] = 1;
  }
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      long long t = 0;
      if (y[i] != y[j]) {
        if ((((x[i] - x[j]) * y[i]) % (y[i] - y[j])) == 0) {
          t = x[i] - (((x[i] - x[j]) * y[i]) / (y[i] - y[j]));
          if (t >= 1 && t <= n) {
            int cur = 2;
            for (int k = j + 1; k < m; k++) {
              if (((y[i] - y[j]) * (x[i] - x[k])) ==
                  ((y[i] - y[k]) * (x[i] - x[j]))) {
                cur++;
              }
            }
            maxans[t] = max(maxans[t], cur);
          }
        }
      } else {
        t = x[i];
        if (t >= 1 && t <= n) {
          int cur = 1;
          for (int k = i + 1; k < m; k++) {
            if (x[k] == t) {
              cur++;
            }
          }
          maxans[t] = max(maxans[t], cur);
        }
      }
    }
  }
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += maxans[i];
  }
  printf("%lld\n", sum);
}
