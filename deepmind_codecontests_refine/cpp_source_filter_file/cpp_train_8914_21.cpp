#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
struct node {
  int id, v;
} q[100010];
int a[100011];
int ans[100010];
int find(int x) {
  int l = 1, r = cnt;
  while (l < r) {
    int mid = l + (r - l) / 2;
    if (x >= q[mid].v)
      r = mid;
    else
      l = mid + 1;
  }
  return q[r].id;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  q[0].v = 9999999;
  for (int i = n; i >= 1; i--) {
    if (cnt == 0 || a[i] <= q[cnt].v) {
      cnt++;
      q[cnt].v = a[i];
      q[cnt].id = i;
      ans[i] = -1;
    } else {
      ans[i] = find(a[i]) - 1 - i;
    }
  }
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
