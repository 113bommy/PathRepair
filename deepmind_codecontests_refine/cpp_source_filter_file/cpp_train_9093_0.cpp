#include <bits/stdc++.h>
using namespace std;
struct node {
  int v, id;
} arr[110000];
int n, h;
int cmp(node a, node b) { return a.v < b.v; }
int main() {
  int i, j, k;
  while (scanf("%d%d", &n, &h) != EOF) {
    for (i = 1; i <= n; ++i) scanf("%d", &arr[i].v), arr[i].id = i;
    sort(arr + 1, arr + 1 + n, cmp);
    int minx = arr[n].v + arr[n - 1].v - arr[1].v - arr[1].v;
    int maxx = ((arr[n].v + arr[1].v + h) > (arr[n].v + arr[n - 1].v)
                    ? (arr[n].v + arr[1].v + h)
                    : (arr[n].v + arr[n - 1].v));
    maxx -= ((arr[1].v + arr[2].v + h) < (arr[2].v + arr[3].v)
                 ? (arr[1].v + arr[2].v + h)
                 : (arr[2].v + arr[3].v));
    if (minx < maxx) {
      printf("%d\n", minx);
      for (i = 1; i <= n; ++i) printf("%d ", 1);
    } else {
      printf("%d\n", maxx);
      for (i = 1; i <= n; ++i)
        if (arr[1].id == i)
          printf("1 ");
        else
          printf("2 ");
    }
    printf("\n");
  }
}
