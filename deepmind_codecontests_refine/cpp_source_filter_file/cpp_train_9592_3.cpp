#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7fffffff;
const double eps = 1e-10;
const double pi = acos(-1.0);
inline int read() {
  int x = 0, f = 1;
  char ch;
  ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch & 15);
    ch = getchar();
  }
  if (f)
    return x;
  else
    return -x;
}
const int N = 1e5 + 10;
int n;
char a[N], b[N];
int v[N];
long long cnt, now;
void add(int n);
void sub(int n) {
  if (a[n] == '0' || a[n + 1] == '0') add(n + 1);
  a[n]--, a[n + 1]--, printf("%d %d\n", n, -1), now++;
  if (now >= 100000) exit(0);
}
void add(int n) {
  if (a[n] == '9' || a[n + 1] == '9') add(n + 1);
  a[n]++, a[n + 1]++, printf("%d %d\n", n, 1), now++;
  if (now >= 100000) exit(0);
}
int main() {
  n = read();
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  for (int i = 1; i <= n; i++) v[i] = a[i] - b[i];
  for (int i = 1, t; i < n; i++) {
    v[i + 1] -= v[i];
    cnt += 1ll * abs(v[i]);
    v[i] -= v[i];
  }
  if (v[n] != 0)
    printf("-1\n");
  else {
    printf("%lld\n", cnt);
    for (int i = 1; i < n; i++) {
      while (a[i] > b[i]) sub(i);
      while (a[i] < b[i]) add(i);
    }
  }
  return 0;
}
