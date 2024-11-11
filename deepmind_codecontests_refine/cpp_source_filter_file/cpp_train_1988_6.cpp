#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T& x) {
  char c = getchar();
  bool f = false;
  for (x = 0; !isdigit(c); c = getchar()) {
    if (c == '-') {
      f = true;
    }
  }
  for (; isdigit(c); c = getchar()) {
    x = x * 10 + c - '0';
  }
  if (f) {
    x = -x;
  }
}
template <typename T, typename... U>
inline void read(T& x, U&... y) {
  read(x), read(y...);
}
int n;
bool Sum(int id) {
  int a, b;
  printf("? %d\n", id);
  fflush(stdout);
  read(a);
  printf("? %d\n", id + n / 2);
  fflush(stdout);
  read(b);
  if (a == b) {
    printf("! %d\n", a);
    fflush(stdout);
    exit(0);
  }
  return a < b;
}
int main() {
  read(n);
  if (n % 4) return puts("! -1"), 0;
  int L = 1, R = n / 2 + 1;
  bool GG = Sum(1);
  while (L < R) {
    int mid = L + R >> 1;
    bool opt = Sum(mid);
    if (opt == GG)
      L = mid + 1;
    else
      R = mid;
  }
  puts("! -1");
  fflush(stdout);
  return 0;
}
