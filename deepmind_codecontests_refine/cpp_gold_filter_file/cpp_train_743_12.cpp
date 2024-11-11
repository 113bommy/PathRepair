#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, m, t;
  scanf("%d %d %d %d", &n, &k, &m, &t);
  int f, p;
  for (int i = 0; i < t; i++) {
    scanf("%d %d", &f, &p);
    if (f) {
      n++;
      if (p <= k) k++;
    } else {
      if (p < k) {
        k -= p;
        n -= p;
      } else {
        n = p;
      }
    }
    printf("%d %d\n", n, k);
  }
}
