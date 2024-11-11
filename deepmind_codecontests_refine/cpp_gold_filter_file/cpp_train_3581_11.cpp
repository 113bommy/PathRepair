#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T& x) {
  bool fu = 0;
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') fu = 1, c = getchar();
  for (x = 0; c > 32; c = getchar()) x = x * 10 + c - '0';
  if (fu) x = -x;
};
template <class T>
inline void read(T& x, T& y) {
  read(x);
  read(y);
}
template <class T>
inline void read(T& x, T& y, T& z) {
  read(x);
  read(y);
  read(z);
}
inline char getc() {
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  return c;
}
const int N = 300010;
int n, m, i, j, k, l, p, x, y;
int a[N], pos[N];
int s[N];
void A(int i, int t) {
  for (; i <= n; i += i & -i) s[i] += t;
}
int S(int i) {
  int ans = 0;
  for (; i; i -= i & -i) ans += s[i];
  return ans;
}
void h(int x, int t) {
  if (pos[x] - pos[x - 1] < 0) A(x, -1);
  if (pos[x + 1] - pos[x] < 0) A(x + 1, -1);
  pos[x] = t;
  if (pos[x] - pos[x - 1] < 0) A(x, 1);
  if (pos[x + 1] - pos[x] < 0) A(x + 1, 1);
}
int main() {
  read(n);
  pos[0] = pos[n + 1] = n + 1;
  for (i = 1; i <= n; i++) read(a[i]), pos[a[i]] = i;
  for (i = 1; i <= n; i++)
    if (pos[i] - pos[i - 1] < 0) {
      A(i, 1);
    }
  for (read(m); m; m--) {
    int t;
    read(t);
    if (t == 1) {
      read(x, y);
      printf("%d\n", S(y) - S(x) + 1);
    } else if (t == 2) {
      read(x, y);
      h(a[x], y);
      h(a[y], x);
      swap(a[x], a[y]);
    }
  }
  return 0;
}
