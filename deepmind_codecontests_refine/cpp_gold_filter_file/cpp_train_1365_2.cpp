#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 200000;
int ss[MAX_N], ps[MAX_N];
bool check(int m, int sd, int k) {
  for (int i = m, j = k; i > 0 && j < m; i--, j++)
    if (ss[j] + ps[i] > sd) return false;
  return true;
}
int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  d--;
  if (d == 0) {
    puts("1");
    return 0;
  }
  int m = 0, sd = 0;
  for (int i = 0; i < n; i++) {
    int si;
    scanf("%d", &si);
    if (i != d)
      ss[m++] = si;
    else
      sd = si;
  }
  for (int i = 0; i < n; i++) scanf("%d", ps + i);
  sd += ps[0];
  int k0 = -1, k1 = d;
  while (k0 + 1 < k1) {
    int k = (k0 + k1) / 2;
    if (check(m, sd, k))
      k1 = k;
    else
      k0 = k;
  }
  printf("%d\n", k1 + 1);
  return 0;
}
