#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  scanf("%d", &n);
  int mx = INT_MIN;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (x >= 0) {
      int root = sqrt(x);
      if (root * root == x) {
        continue;
      }
    }
    mx = max(mx, x);
  }
  printf("%d\n", mx);
}
