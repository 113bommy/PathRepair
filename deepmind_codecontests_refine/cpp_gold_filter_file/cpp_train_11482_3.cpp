#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
struct node {
  int x, y;
} s[maxn];
bool cmp(node a, node b) { return a.x < b.x; }
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &s[i].x), s[i].y = i;
    sort(s + 1, s + 1 + n, cmp);
    if (s[1].x == s[n].x) {
      printf("NO\n");
      continue;
    }
    printf("YES\n");
    int p = -1, sum = 0;
    for (int i = 1; i < n; i++) {
      for (int j = i + 1; j <= n; j++) {
        if (s[i].x != s[j].x) {
          sum++;
          printf("%d %d\n", s[i].y, s[j].y);
          break;
        }
      }
    }
    if (sum != n - 1) {
      for (int i = n; i > 1; i--) {
        for (int j = i - 1; j >= 1; j--) {
          if (s[i].x != s[j].x) {
            sum++;
            printf("%d %d\n", s[i].y, s[j].y);
            break;
          }
        }
        if (sum == n - 1) break;
      }
    }
  }
  return 0;
}
