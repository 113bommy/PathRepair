#include <bits/stdc++.h>
using namespace std;
typedef unsigned int UI;
typedef long int LI;
typedef unsigned long int ULI;
typedef long long int LL;
typedef unsigned long long int ULL;
const LL MOD = 1e9 + 7;
inline int scanInt() {
  int n = 0;
  char ch = getchar();
  int sign = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') sign = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    n = (n << 1) + (n << 3) + (int)(ch - '0');
    ch = getchar();
  }
  return n * sign;
}
inline LL scanLong() {
  LL n = 0;
  char ch = getchar();
  LL sign = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') sign = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    n = (n << 1) + (n << 3) + (LL)(ch - '0');
    ch = getchar();
  }
  return n * sign;
}
int main() {
  LL n = scanLong();
  ;
  LL stock[n], bought[n];
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n)))
    stock[i] = scanLong();
  for (__typeof(0) i = (n) - ((n) > (0)); i != (0) - ((n) > (0));
       i += 1 - 2 * ((n) > (0))) {
    if (i + 1 == n)
      bought[i] = stock[i];
    else {
      if (stock[i] < bought[i + 1])
        bought[i] = stock[i];
      else
        bought[i] = max(bought[i + 1] - 1, 0ll);
    }
  }
  cout << accumulate(bought, bought + n, 0ll) << endl;
}
