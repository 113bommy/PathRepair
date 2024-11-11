#include <bits/stdc++.h>
using namespace std;
int n;
int maxn;
struct node {
  char a;
  int x, y;
} edge[5000];
bool cmp(node temp1, node temp2) { return temp1.y < temp2.y; }
int main() {
  int ant1, ant2;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    cin >> edge[i].a;
    scanf("%d%d", &edge[i].x, &edge[i].y);
  }
  sort(edge, edge + n, cmp);
  maxn = 0;
  for (int i = 0; i < n; i++) {
    ant1 = 0, ant2 = 0;
    for (int j = i + 1; j < n; j++) {
      if (edge[j].x <= edge[i].y)
        if (edge[i].a != edge[j].a) {
          ant1++;
        } else {
          ant2++;
        }
      else
        continue;
    }
    ant2++;
    maxn = max(maxn, min(ant1, ant2));
  }
  printf("%d\n", maxn * 2);
  return 0;
}
