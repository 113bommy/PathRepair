#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 5, M = 1e5 + 10, inf = 20005;
inline int read() {
  int s = 1, ret = 0;
  char ss = getchar();
  while (ss < '0' || ss > '9') {
    if (ss == '-') s = -s;
    ss = getchar();
  }
  while (ss >= '0' && ss <= '9') {
    ret = ret * 10 + (ss - '0');
    ss = getchar();
  }
  return ret * s;
}
int n, k;
int q[N];
map<bool, int> v;
int main() {
  n = read();
  k = read();
  int x = 0, tail = 0, head = 0;
  for (int i = 1; i <= n; i++) {
    x = read();
    if (!v[x]) {
      tail++;
      if (tail - head + 1 > k) v[q[head]] = 0, head++;
      q[tail] = x;
      v[x] = 1;
    } else {
    }
  }
  int ans = 0;
  for (int i = tail; i >= head; i--)
    if (q[i]) ans++;
  printf("%d\n", ans);
  for (int i = tail; i >= head; i--)
    if (!q[i])
      break;
    else
      printf("%d ", q[i]);
  return 0;
}
