#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    if (n == 1) {
      printf("%d\n", 0);
    } else if (n == 2) {
      printf("%d\n", m);
    } else {
      n *= 2;
      printf("%d\n", n);
    }
  }
  return 0;
}
