#include <bits/stdc++.h>
using namespace std;
int n, p;
bool check(int x) {
  int sum = n - x * p, cnt = 0, cnt2 = 0;
  if (sum <= 0) return 0;
  for (int i = 0; i <= 30; ++i)
    if (sum & (1 << i)) ++cnt, cnt2 += i;
  return cnt <= x && x <= cnt2;
}
int main() {
  scanf("%d%d", &n, &p);
  int l = 1, r = 1e9;
  for (int x = 1; x <= 1e6; ++x) {
    if (check(x)) {
      printf("%d\n", x);
      return 0;
    }
  }
  printf("-1\n");
}
