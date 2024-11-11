#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
const int INF = 1e9 + 7;
const int mod = 1e9 + 7;
int get(int x) {
  int ans;
  printf("? %d\n", x);
  fflush(stdout);
  scanf("%d", &ans);
  return ans;
}
int main() {
  int i, j, n, m, t, z;
  scanf("%d", &n);
  int x = get(1), y = get(1 + n / 2);
  if (x == y) {
    printf("! %d\n", x);
    return 0;
  }
  int l = 2, r = n / 2;
  int flag = x > y;
  while (l <= r) {
    int mid = (l + r) >> 1;
    int x = get(mid), y = get(mid + n / 2);
    int flagg = x > y;
    if (x == y) {
      printf("! %d\n", x);
      return 0;
    }
    if (flagg != flag) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  printf("! -1\n");
  return 0;
}
