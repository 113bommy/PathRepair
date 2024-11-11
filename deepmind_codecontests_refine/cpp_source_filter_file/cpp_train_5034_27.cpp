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
int n, i, j, k, l, p;
long long a[100100], s[100010];
long long ans, tot;
int main() {
  read(n);
  for (i = 1; i <= n; i++) read(a[i]), s[i] = s[i - 1] + a[i];
  if (s[n] % 3 != 0) {
    printf("0\n");
    return 0;
  }
  long long t = s[n] / 3;
  for (i = 1; i <= n; i++) {
    if (i > 1 && s[i - 1] == t) tot++;
    if (s[n] - s[i] == t) ans += tot;
  }
  cout << ans << endl;
  scanf("\n");
  return 0;
}
