#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy[] = {0, -1, 0, 1, -1, 1, 1, -1};
template <class T>
inline bool get(T& n) {
  char c, mul = 1;
  n = 0;
  while (!isdigit(c = getchar_unlocked()) && (c != EOF) && (c != '-'))
    ;
  if (c == EOF) return false;
  if (c == '-') {
    c = getchar_unlocked();
    mul = -1;
  }
  for (; isdigit(c); c = getchar_unlocked()) n = n * 10 + c - '0';
  n *= mul;
  return true;
}
inline void get(char& c) {
  while (isspace(c = getchar_unlocked()))
    ;
}
int main() {
  long long n, m, k;
  get(n);
  get(m);
  get(k);
  if (n - 1 + m - 1 < k) {
    printf("-1\n");
    return 0;
  }
  long long ans = 0;
  if (k <= m - 1)
    ans = m / (k + 1) * n;
  else
    ans = n / (k - m + 2);
  if (k <= n - 1)
    (ans) = max((ans), (n / (k + 1) * m));
  else
    (ans) = max((ans), (m / (k - n + 2)));
  printf("%I64d\n", ans);
  return 0;
}
