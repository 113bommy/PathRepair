#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
struct node {
  int v, id;
  bool operator<(const node &T) const { return v < T.v; }
} p[N];
int main() {
  int n, i;
  while (scanf("%d", &n) == 1) {
    for (i = 0; i < n; i++) scanf("%d", &p[i].v), p[i].id = i;
    sort(p, p + n);
    printf("%d\n", (n + 1) >> 1);
    for (i = 0; i < n; i += 2) printf("%d ", p[i].id);
    printf("%d\n", n >> 1);
    for (i = 1; i < n; i += 2) printf("%d ", p[i].id);
    puts("");
  }
  return 0;
}
