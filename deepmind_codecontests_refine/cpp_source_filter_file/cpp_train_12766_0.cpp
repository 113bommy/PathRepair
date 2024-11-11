#include <bits/stdc++.h>
using namespace std;
struct Num {
  int x, y, no;
} num[25];
bool cmp1(Num x1, Num x2) { return x1.x < x2.x; }
bool cmp2(Num x1, Num x2) { return x1.no < x2.no; }
int main() {
  bool flag;
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &num[i].x);
    num[i].no = i;
  }
  sort(num + 1, num + 1 + n, cmp1);
  for (int i = 1; i < n; i++) num[i].y = num[i + 1].x;
  num[n].y = num[1].x;
  if (n > 1) {
    for (int i = 1; i <= n; i++) {
      if (num[i].x == num[i].y) flag = 1;
    }
  }
  if (flag)
    printf("-1\n");
  else {
    sort(num + 1, num + 1 + n, cmp2);
    for (int i = 1; i < n; i++) printf("%d ", num[i].y);
    printf("%d\n", num[n].y);
  }
  return 0;
}
