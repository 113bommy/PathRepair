#include <bits/stdc++.h>
using namespace std;
long px, py, x[1001], y[1001], temp, n, i, res, j, tx, ty, first, last, mid;
bool p;
void quick(long l1, long r1) {
  long i1, j1;
  if (l1 >= r1) return;
  px = x[(l1 + r1) >> 1];
  py = y[(l1 + r1) >> 1];
  i1 = l1;
  j1 = r1;
  do {
    while (x[i1] < px || (x[i1] == px && y[i1] < py)) i1++;
    while (x[j1] > px || (x[j1] == px && y[j1] > py)) j1--;
    if (i1 <= j1) {
      if (i1 < j1) {
        temp = x[i1];
        x[i1] = x[j1];
        x[j1] = temp;
        temp = y[i1];
        y[i1] = y[j1];
        x[j1] = temp;
      }
      i1++;
      j1--;
    }
  } while (i1 <= j1);
  quick(l1, j1);
  quick(i1, r1);
}
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) cin >> x[i] >> y[i];
  quick(1, n);
  res = 0;
  for (i = 1; i <= n - 1; i++)
    for (j = i + 1; j <= n; j++)
      if (((x[i] + x[j]) & 1) == 0 && ((y[i] + y[j]) & 1) == 0) {
        tx = (x[i] + x[j]) >> 1;
        ty = (y[i] + y[j]) >> 1;
        first = 0;
        last = n + 1;
        p = false;
        while (first + 1 < last && p == false) {
          mid = (first + last) >> 1;
          if (x[mid] < tx || (x[mid] == tx && y[mid] < tx))
            first = mid;
          else
            last = mid;
          if (x[mid] == tx && y[mid] == tx) p = true;
        }
        if (p == true) res++;
      }
  cout << res;
}
