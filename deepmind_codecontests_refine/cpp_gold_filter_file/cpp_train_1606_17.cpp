#include <bits/stdc++.h>
using namespace std;
int n, m;
struct node {
  int x;
  int y;
  int z;
} a[200010];
int b[200010];
bool cmp1(node p, node q) { return p.x < q.x; }
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &a[i + n]);
  for (int i = 1; i <= 2 * n; i++) a[i].y = i;
  sort(a + 1, a + 2 * n + 1, cmp1);
  memset(b, 0, sizeof(b));
  for (int i = 1; i <= n; i++) b[a[i].y] = 1;
  for (int i = 1; i <= n; i++) {
    if (i <= n / 2 || b[i])
      printf("%d", 1);
    else
      printf("%d", 0);
  }
  cout << endl;
  for (int i = n + 1; i <= 2 * n; i++) {
    if ((i - n) <= n / 2 || b[i])
      printf("%d", 1);
    else
      printf("%d", 0);
  }
}
