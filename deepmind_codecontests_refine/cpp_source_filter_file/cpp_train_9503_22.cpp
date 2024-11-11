#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, neg = 1;
  char op = getchar();
  while (!isdigit(op)) {
    if (op == '-') neg = -1;
    op = getchar();
  }
  while (isdigit(op)) {
    x = 10 * x + op - '0';
    op = getchar();
  }
  return neg * x;
}
inline void print(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
int f[22];
int main() {
  int n;
  cin >> n;
  f[0] = 1;
  for (int i = 1; i <= 20; i++) {
    f[i] = f[i - 1] * i;
  }
  long long ans = f[n] / f[n / 2] / f[n / 2];
  ans *= f[n / 2 - 1];
  ans *= f[n / 2 - 1];
  ans /= 2;
  cout << ans << endl;
  return 0;
}
