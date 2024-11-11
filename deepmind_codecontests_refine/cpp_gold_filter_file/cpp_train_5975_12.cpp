#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int maxn = 100010;
struct num {
  int s, id;
  int ans1, ans2;
} a[maxn];
bool cmp1(num l, num r) { return l.s < r.s; }
bool cmp2(num l, num r) { return l.id < r.id; }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].s);
    a[i].id = i;
  }
  puts("YES");
  sort(a, a + n, cmp1);
  int t = n / 3;
  if (n % 3 != 0) t++;
  for (int i = 0; i < t; i++) {
    a[i].ans1 = i;
    a[i].ans2 = a[i].s - a[i].ans1;
  }
  for (int i = t; i < 2 * t; i++) {
    a[i].ans2 = i;
    a[i].ans1 = a[i].s - a[i].ans2;
  }
  for (int i = 2 * t; i < n; i++) {
    a[i].ans2 = n - 1 - i;
    a[i].ans1 = a[i].s - a[i].ans2;
  }
  sort(a, a + n, cmp2);
  for (int i = 0; i < n; i++) {
    if (i > 0) printf(" ");
    printf("%d", a[i].ans1);
  }
  puts("");
  for (int i = 0; i < n; i++) {
    if (i > 0) printf(" ");
    printf("%d", a[i].ans2);
  }
  puts("");
  return 0;
}
