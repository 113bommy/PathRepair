#include <bits/stdc++.h>
using namespace std;
struct target {
  int x, rad;
} t[10011];
struct shot {
  int x, y;
} s[200011];
int n, m, ontarget, order[200011], result[10011];
void qsort(int left, int right) {
  if (left >= right) return;
  int i = left, j = right, px = s[(left + right) >> 1].x,
      py = s[(left + right) >> 1].y;
  while (i <= j) {
    while (s[i].x < px || (s[i].x == px && s[i].y < py)) i++;
    while (s[j].x > px || (s[j].x == px && s[j].y > py)) j--;
    if (i <= j) {
      if (i < j) {
        swap(s[i].x, s[j].x);
        swap(s[i].y, s[j].y);
        swap(order[i], order[j]);
      }
      i++;
      j--;
    }
  }
  qsort(left, j);
  qsort(i, right);
}
int find_first(int t) {
  int ans = 0, left = 0, right = m;
  while (left <= right) {
    int mid = (left + right) >> 1;
    if (s[mid].x < t)
      left = mid + 1;
    else {
      right = mid - 1;
      ans = mid;
    }
  }
  return ans;
}
int find_last(int t) {
  int ans = 0, left = 0, right = m;
  while (left <= right) {
    int mid = (left + right) >> 1;
    if (s[mid].x <= t) {
      ans = mid;
      left = mid + 1;
    } else
      right = mid - 1;
  }
  return ans;
}
int sqr(int x) { return x * x; }
int main() {
  scanf("%d", &n);
  if (n == 0) {
    printf("0");
    return 0;
  }
  for (int i = 1; i <= n; i++) scanf("%d%d", &t[i].x, &t[i].rad);
  scanf("%d", &m);
  if (m == 0) {
    printf("0\n");
    for (int i = 1; i <= n; i++) printf("-1 ");
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &s[i].x, &s[i].y);
    order[i] = i;
  }
  order[0] = 2000000000;
  order[m + 1] = 2000000000;
  qsort(1, m);
  for (int i = 1; i <= n; i++) {
    int first = find_first(t[i].x - t[i].rad),
        last = find_last(t[i].x + t[i].rad);
    result[i] = 2000000000;
    for (int j = first; j <= last; j++)
      if (sqr(t[i].x - s[j].x) + sqr(s[j].y) <= sqr(t[i].rad))
        result[i] = min(result[i], order[j]);
    if (result[i] == 2000000000)
      result[i] = -1;
    else
      ontarget++;
  }
  printf("%d\n", ontarget);
  for (int i = 1; i <= n; i++) printf("%d ", result[i]);
  return 0;
}
