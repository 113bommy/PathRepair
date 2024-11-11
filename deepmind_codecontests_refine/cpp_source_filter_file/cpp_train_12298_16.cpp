#include <bits/stdc++.h>
using namespace std;
const int white = 0, gray = 1, black = 2;
const int inf = 0x0fffffff;
const int Size = 10000;
char buffer[Size];
int n, p1, p2, p3, t1, t2;
int ar[1500];
int Solution(int nTest) {
  scanf("%d%d%d%d%d%d", &n, &p1, &p2, &p3, &t1, &t2);
  int rn = 0;
  int ln = 1500;
  for (int i = 0; i < n; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    for (int j = l; j < r; j++) ar[j] = 1;
    rn = max(r, rn);
    ln = min(ln, l);
  }
  int res = 0;
  int t = 0;
  t2 += t1;
  for (int i = ln; i < rn; i++) {
    if (ar[i] == 0) {
      t++;
      if (t > t2)
        res += p3;
      else if (t > t1)
        res += p3;
      else
        res += p1;
    } else {
      res += p1;
      t = 0;
    }
  }
  printf("%d\n", res);
  return 0;
}
int main() {
  int i = 0, n = 99999;
  while (i < n && Solution(i)) {
    i++;
  }
  return 0;
}
