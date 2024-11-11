#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000");
const double PI = acos(-1.0);
using namespace std;
struct N {
  int x, k;
} p[1001000];
int ans[1000100];
int main() {
  int n;
  int i;
  scanf("%d", &n);
  memset(ans, 0, sizeof(ans));
  for (i = 0; i < n; ++i) {
    scanf("%d %d", &p[i].x, &p[i].k);
  }
  bool mark = false;
  for (i = 0; i < n; ++i) {
    if (ans[p[i].k] == p[i].x) {
      ans[p[i].k]++;
    } else if (ans[p[i].k] < p[i].x) {
      mark = true;
    }
  }
  if (mark) {
    printf("NO\n");
  } else {
    printf("YES\n");
  }
  return 0;
}
