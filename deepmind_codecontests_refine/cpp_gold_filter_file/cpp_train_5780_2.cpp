#include <bits/stdc++.h>
using namespace std;
struct node {
  int w, v1, v2, tell, num;
};
bool cmp(node a, node b) {
  if (a.w != b.w) return a.w < b.w;
  return a.tell > b.tell;
}
int main() {
  int n, m, a, b;
  scanf("%d%d", &n, &m);
  node arr[m];
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &arr[i].w, &arr[i].tell);
    arr[i].num = i;
  }
  sort(arr, arr + m, cmp);
  int select[n], s[m], d[m];
  for (int i = 0; i < n; i++) select[i] = i + 2;
  int ver = 0;
  for (int i = 0; i < m; i++) {
    if (arr[i].tell == 1) {
      arr[i].v1 = ver;
      arr[i].v2 = ver + 1;
      ver++;
    } else {
      for (int j = 0; j < n; j++) {
        if (select[j] <= ver) {
          arr[i].v1 = j;
          arr[i].v2 = select[j];
          select[j]++;
          break;
        } else if (j == n - 1) {
          printf("-1\n");
          return 0;
        }
      }
    }
  }
  for (int i = 0; i < m; i++) {
    d[arr[i].num] = arr[i].v1;
    s[arr[i].num] = arr[i].v2;
  }
  for (int i = 0; i < m; i++) printf("%d %d\n", d[i] + 1, s[i] + 1);
}
