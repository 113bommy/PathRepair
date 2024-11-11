#include <bits/stdc++.h>
using namespace std;
const long long int MAXN = 2e5 + 51;
long long int n, d;
inline long long int read() {
  register long long int num = 0, neg = 1;
  register char ch = getchar();
  while (!isdigit(ch) && ch != '-') {
    ch = getchar();
  }
  if (ch == '-') {
    neg = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    num = (num << 3) + (num << 1) + (ch - '0');
    ch = getchar();
  }
  return num * neg;
}
int main() {
  n = read();
  d = n / 2 + n / 3 + n / 5 + n / 7 - n / 6 - n / 10 - n / 14 - n / 15 -
      n / 21 - n / 35 + n / 30 + n / 42 + n / 70 + n / 105 - n / 210;
  printf("%lld\n", n - d);
}
