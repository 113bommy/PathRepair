#include <bits/stdc++.h>
using namespace std;
struct node {
  int val, time;
};
const int N = 5000 + 50;
node r[N], c[N];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= N; ++i) {
    r[i].val = r[i].time = -1;
    c[i].val = c[i].time = -1;
  }
  int a, b, d;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d", &a, &b, &d);
    if (a == 1) {
      r[b].val = d;
      r[b].time = i;
    } else if (a == 2) {
      c[b].val = d;
      c[b].time = i;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (r[i].time == -1 && c[j].time == -1) {
        printf("0 ");
        continue;
      } else {
        if (r[i].time > c[j].time)
          printf("%d ", r[i].val);
        else
          printf("%d ", c[j].val);
      }
    }
    printf("\n");
  }
  return 0;
}
