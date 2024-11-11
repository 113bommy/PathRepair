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
      m *= 2;
      printf("%d\n", m);
    }
  }
  return 0;
}
