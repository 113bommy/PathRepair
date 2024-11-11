#include <bits/stdc++.h>
using namespace std;
int n;
int query(int x) {
  printf("? %d\n", x);
  fflush(stdout);
  int ans1, ans2;
  scanf("%d", &ans1);
  printf("? %d\n", x + n / 2);
  fflush(stdout);
  scanf("%d", &ans2);
  if (ans1 == ans2) {
    printf("! %d\n", x);
    exit(0);
  }
  return ans1 > ans2;
}
int main() {
  scanf("%d", &n);
  if (n % 4) {
    printf("! -1\n");
    exit(0);
  }
  int z = query(1);
  int l = 2, r = n / 2;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (query(mid) == z)
      l = mid + 1;
    else
      r = mid - 1;
  }
}
