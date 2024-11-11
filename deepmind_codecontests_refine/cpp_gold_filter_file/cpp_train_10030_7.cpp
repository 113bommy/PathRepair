#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, r;
  while (~scanf("%d%d%d", &n, &m, &r)) {
    if (n >= 2 * r && m >= 2 * r) {
      printf("First\n");
    } else {
      printf("Second\n");
    }
  }
  return 0;
}
