#include <bits/stdc++.h>
using namespace std;
int n, m, dign, digm, s, res;
bool mark[7];
int digCnt(int a) {
  int res = 0;
  do {
    a /= 7;
    ++res;
  } while (a);
  return res;
}
int tmp[7];
void duyet(int i) {
  if (i == s) {
    int a = 0, b = 0;
    for (int j = 0; j < dign; ++j) a = a * 7 + tmp[j];
    for (int j = 0; j < digm; ++j) b = b * 7 + tmp[j + dign];
    if (a < n && b < m) ++res;
    return;
  }
  for (int j = 0; j < 7; ++j) {
    if (!mark[j]) {
      mark[j] = 1;
      tmp[i] = j;
      duyet(i + 1);
      mark[j] = 0;
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  dign = digCnt(n - 1);
  digm = digCnt(m - 1);
  s = dign + digm;
  if (s > 7) {
    printf("0\n");
    return 0;
  }
  res = 0;
  duyet(0);
  printf("%d\n", res);
}
