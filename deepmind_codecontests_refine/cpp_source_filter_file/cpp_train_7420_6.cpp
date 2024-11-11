#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1}, dy[] = {1, -1, 0, 0, 1, -1, -1, 1};
inline void cn(long& n) {
  n = 0;
  long ch = getchar();
  int sign = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') sign = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    n = (n << 3) + (n << 1) + ch - '0', ch = getchar();
  n = n * sign;
}
template <class T>
void cmin(T& a, T b) {
  if (b < a) a = b;
}
template <class T>
void cmax(T& a, T b) {
  if (b > a) a = b;
}
template <class T>
int len(const T& c) {
  return (int)c.size();
}
template <class T>
int len(char c[]) {
  return (int)strlen(c);
}
string itos(long n) {
  string s;
  while (n) {
    s += (n % 10 + 48);
    n /= 10;
  }
  reverse(s.begin(), s.end());
  return s;
}
long stoi(string s) {
  long n = 0;
  for (int i(0), _n(len(s)); i < _n; ++i) n = n * 10 + (s[i] - 48);
  return n;
}
void init() {}
int main() {
  long n, m, ar[10], res = 0, cu[2005];
  ar[0] = 2;
  ar[1] = 2;
  ar[2] = 0;
  ar[3] = 0;
  cu[0] = 0;
  for (int i(0), _n(201); i < _n; ++i) {
    cu[i + 1] = cu[i] + ar[i % 4];
  }
  res = 0;
  cn(n);
  cn(m);
  if (n > m) swap(n, m);
  if (n == 1 || m == 1) {
    printf("%ld\n", max(n, m));
  } else if (n == 2 && m == 2)
    printf("4\n");
  else if (n == 2 && m == 3)
    printf("4\n");
  else if (n == 2) {
    printf("%ld\n", cu[m]);
  } else {
    res = n * m;
    printf("%ld\n", (res + 1) / 2);
  }
  return 0;
}
