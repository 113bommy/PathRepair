#include <bits/stdc++.h>
using namespace std;
const int MXMX = 2000000;
int P[MXMX + 10], RUB[MXMX + 10];
bool PRIM(int n) {
  if (n < 2) return 0;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
bool PALL(int n) {
  int a[10], m = n, i = 0;
  for (; n != 0; i++) {
    a[i] = n % 10;
    n /= 10;
  }
  n = 0;
  i--;
  for (int j = 1; i >= 0; i--, j *= 10) {
    n += a[i] * j;
  }
  if (m == n) return 1;
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int p, q;
  cin >> p >> q;
  for (int i = 1; i < MXMX; i++) {
    P[i] = P[i - 1] + PRIM(i);
    RUB[i] = RUB[i - 1] + PALL(i);
  }
  int ANS;
  for (int i = 0; i < MXMX; i++) {
    if (P[i] * q <= RUB[i] * p) ANS = i;
  }
  cout << ANS;
}
