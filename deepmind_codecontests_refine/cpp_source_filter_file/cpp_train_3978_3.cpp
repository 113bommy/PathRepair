#include <bits/stdc++.h>
using namespace std;
int n, arr[30010], book[30010];
bool judge() {
  int ps, gap;
  int t1 = 1, t2;
  while (t1 <= n && book[t1]) t1++;
  t2 = t1 + 1;
  if (t1 > n) return false;
  while (t2 <= n && book[t2]) t2++;
  if (t2 > n) return true;
  gap = arr[t2] - arr[t1];
  ps = t2;
  for (int i = t2 + 1; i <= n; i++)
    if (!book[i]) {
      if (arr[i] - arr[ps] == gap)
        ps = i;
      else
        return false;
    }
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
  if (n == 2)
    printf("%d\n%d", arr[1], arr[2]);
  else {
    int x[3] = {arr[2] - arr[1], arr[3] - arr[2], arr[3] - arr[1]};
    int flag = 0;
    for (int i = 0; i < 3; i++) {
      int st = 4, tmp = arr[3];
      memset(book, 0, sizeof(book));
      if (i == 0) {
        book[2] = book[1] = 1;
        st = 3;
        tmp = arr[2];
      } else if (i == 1)
        book[2] = book[3] = 1;
      else
        book[1] = book[3] = 1;
      for (int ii = st; ii <= n; ii++)
        if (arr[ii] == tmp + x[i]) {
          book[ii] = 1;
          tmp = arr[ii];
        }
      if (judge()) {
        flag = 1;
        break;
      } else {
        int p = n;
        while (!book[p]) p--;
        book[p] = 0;
        if (judge()) {
          flag = 1;
          break;
        }
      }
    }
    if (flag) {
      for (int i = 1; i <= n; i++)
        if (book[i]) printf("%d ", arr[i]);
      printf("\n");
      for (int i = 1; i <= n; i++)
        if (!book[i]) printf("%d ", arr[i]);
    } else
      printf("NO solution");
  }
  return 0;
}
