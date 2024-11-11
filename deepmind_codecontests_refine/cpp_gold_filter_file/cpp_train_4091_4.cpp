#include <bits/stdc++.h>
using namespace std;
int a, b, c, n, m, T, y[2 * 100010];
struct node {
  int a, b;
} x[2 * 100010];
bool cmp(node a, node b) { return a.a < b.a; }
int main() {
  scanf("%d", &T);
  while (T--) {
    long long w;
    scanf("%d%lld", &n, &w);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &x[i].a);
      x[i].b = i;
      y[i] = 0;
    }
    sort(x + 1, x + 1 + n, cmp);
    long long t = 0;
    int cnt = 0;
    for (int i = n; i > 0; i--) {
      if (t + x[i].a <= w) t += x[i].a, y[x[i].b] = 1, cnt++;
    }
    if (t < (w + 1) / 2)
      cout << "-1\n";
    else {
      cout << cnt << endl;
      for (int i = 1; i <= n; i++)
        if (y[i]) cout << i << ' ';
      cout << endl;
    }
  }
}
