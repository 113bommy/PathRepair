#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000 * 100 + 10;
int a[maxn], maxval = -1;
void relax(int pos, int start, int finish) {
  if (a[pos + 1] - a[pos - 1] > 1) maxval = max(maxval, finish - start + 1);
  if (pos - 2 > 0 && a[pos] - a[pos - 2] > 1)
    maxval = max(maxval, finish - start + 1);
  maxval = max(maxval, pos - start + 1);
  maxval = max(maxval, finish - (pos - 1) + 1);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int cnt = 0, pos = n + 1, j = 2, i = 1;
  for (; i <= n && j <= n;) {
    while (cnt < 2 && j <= n) {
      if (a[j] <= a[j - 1]) {
        cnt++;
        if (cnt == 2) {
          j++;
          break;
        }
        pos = j;
      }
      j++;
    }
    if (cnt == 2) {
      relax(pos, i, j - 2);
      i = pos;
      pos = j - 1;
      cnt = 1;
    } else {
      if (cnt == 1)
        relax(pos, i, j - 1);
      else
        maxval = max(maxval, j - i);
    }
  }
  printf("%d\n", maxval);
  return 0;
}
