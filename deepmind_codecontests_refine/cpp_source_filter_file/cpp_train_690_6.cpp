#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)3e5 + 500;
int n, x1, x2;
pair<int, int> c[MAXN];
int main() {
  scanf("%d%d%d", &n, &x1, &x2);
  for (int i = 0; i < n; i++) {
    scanf("%d", &c[i].first);
    c[i].second = i;
  }
  sort(c, c + n);
  for (int i = 0; i < n; i++) {
    int nxt = (x1 + c[i].first - 1) / c[i].first;
    if (i + nxt >= n) continue;
    int nxt2 = (x2 + c[i + nxt].first - 1) / c[i + nxt].first;
    if (i + nxt + nxt2 > n) continue;
    printf("YES\n");
    printf("%d %d\n", nxt, nxt2);
    for (int j = i; j < i + nxt; j++) printf("%d ", c[j].second + 1);
    printf("\n");
    for (int j = i + nxt; j < i + nxt + nxt2; j++)
      printf("%d ", c[j].second + 1);
    return 0;
  }
  for (int i = 0; i < n; i++) {
    int nxt = (x2 + c[i].first - 1) / c[i].first;
    if (i + nxt >= n) continue;
    int nxt2 = (x1 + c[i + nxt].first - 1) / c[i + nxt].first;
    if (i + nxt + nxt2 > n) continue;
    printf("YES\n");
    printf("%d %d\n", nxt2, nxt);
    for (int j = i + nxt; j < i + nxt + nxt2; j++)
      printf("%d ", c[j].second + 1);
    printf("\n");
    for (int j = i; j < i + nxt; j++) printf("%d ", c[j].second + 1);
    return 0;
  }
  printf("NO");
}
