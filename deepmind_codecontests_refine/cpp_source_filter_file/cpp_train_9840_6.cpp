#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 5;
struct sd {
  int cot, t1, t2;
};
int n;
long long x1[M], x2[M];
sd bak[M];
void in() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", &x1[i]), x1[i] += x1[i - 1];
  for (int i = 1; i <= n; ++i) scanf("%lld", &x2[i]), x2[i] += x2[i - 1];
}
void ac() {
  bool flag = 0;
  if (x1[n] > x2[n]) flag = 1, swap(x1, x2);
  int j = 0, hh, s1 = 1, s2 = 1, e1 = 1, e2 = 1;
  for (int i = 1; i <= n; ++i) {
    while (x2[j] <= x1[i]) {
      ++j;
    }
    hh = x2[j] - x1[i];
    bak[hh].cot++;
    if (bak[hh].cot >= 2) {
      s1 = bak[hh].t1;
      s2 = bak[hh].t2;
      e1 = i;
      e2 = j;
      break;
    }
    bak[hh].t1 = i;
    bak[hh].t2 = j;
  }
  if (flag) {
    swap(x1, x2);
    swap(e1, e2);
    swap(s1, s2);
  }
  printf("%d\n", e1 - s1);
  for (int i = s1 + 1; i <= e1; ++i) printf("%d ", i);
  printf("\n%d\n", e2 - s2);
  for (int i = s2 + 1; i <= e2; ++i) printf("%d ", i);
}
int main() {
  in();
  ac();
  return 0;
}
