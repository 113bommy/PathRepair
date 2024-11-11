#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 1;
int n, TV1, TV2;
struct node {
  int st, ed;
} a[maxn];
bool cmp(node a, node b) {
  return (a.st != b.st) ? (a.st < b.st) : (a.ed < b.ed);
}
signed main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].st, &a[i].ed);
  sort(a + 1, a + n + 1, cmp);
  TV1 = TV2 = -1;
  for (int i = 1; i <= n; i++) {
    if (TV1 >= a[i].st && TV2 >= a[i].st) {
      puts("NO");
      return 0;
    }
    if (a[i].st > TV1)
      TV1 = a[i].ed;
    else if (a[i].st > TV2)
      TV2 = a[i].ed;
  }
  puts("YES");
}
