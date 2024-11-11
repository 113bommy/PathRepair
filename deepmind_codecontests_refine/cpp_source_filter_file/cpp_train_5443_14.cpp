#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int l, r;
    scanf("%d%d", &l, &r);
    int ans = r + 1;
    if (l > ans / 2)
      printf("YES\n");
    else if (l % 3 == 0) {
      ans = l / 3 * 2;
      if (r < ans * 2)
        printf("YES\n");
      else
        printf("NO\n");
    } else
      printf("NO\n");
  }
}
