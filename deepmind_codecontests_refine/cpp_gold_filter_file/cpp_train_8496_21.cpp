#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int r = 0;
  for (int i = 0; i < n; i++) {
    int l, d;
    scanf("%d%d", &l, &d);
    if (l > r)
      r = l;
    else {
      while (r >= l) {
        l += d;
      }
      r = l;
    }
  }
  printf("%d\n", r);
}
