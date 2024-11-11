#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T read(T &x) {
  x = 0;
  int f = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    f |= (ch == '-'), ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
  }
  return x = f ? -x : x;
}
int main(void) {
  int n;
  read(n);
  int sqrt_n = (int)sqrt((double)n);
  int cow = 0;
  for (int i = 1; i <= sqrt_n; i++) {
    if (n % i == 0) {
      if (n / i != i)
        cow += 2;
      else
        cow += 1;
    }
  }
  cout << cow << "\n";
  return 0;
}
