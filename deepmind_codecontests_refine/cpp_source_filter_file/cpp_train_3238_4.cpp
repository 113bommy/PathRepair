#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, inf = 1e9;
int n, s1, s2, sum, last;
int a[N];
pair<int, int> pa;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int main() {
  n = read();
  pa = make_pair(inf, 0);
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    if (a[i] == 0) s1++;
    if (a[i] < 0) {
      s2++;
      pa = min(pa, make_pair(-a[i], i));
    }
  }
  if (s2 & 1) a[pa.second] = 0;
  last = -1;
  for (int i = 1; i <= n; i++) {
    if (a[i] != 0) continue;
    if (last == -1)
      last = i;
    else {
      printf("1 %d %d\n", last, i);
      last = i;
      sum++;
    }
  }
  if (last != -1 && sum < n - 1) printf("2 %d\n", last);
  last = -1;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) continue;
    if (last == -1)
      last = i;
    else {
      printf("1 %d %d\n", last, i);
      last = i;
    }
  }
  return 0;
}
