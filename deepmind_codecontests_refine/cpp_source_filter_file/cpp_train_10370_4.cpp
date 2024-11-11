#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  int day = 0;
  int last = 0;
  int ans = 0;
  bool flag = false;
  for (int i = 0; i < n && !flag; i++) {
    int a;
    scanf("%d", &a);
    a += a + last;
    last = a - 8 > 0 ? a - 8 : 0;
    ans += a - last;
    day++;
    if (ans >= k) {
      printf("%d", day);
      flag = true;
    }
  }
  if (!flag) printf("-1");
  return 0;
}
