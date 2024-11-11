#include <bits/stdc++.h>
using namespace std;
long long int c[77][77];
long long int n, t;
void do1() {
  long long int i, j;
  c[0][0] = 1;
  for (i = 1; i <= 50; i++)
    for (j = 0; j <= i; j++) c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
}
long long int do2() {
  long long int i, j, k, l, r, m, p, q;
  j = 0;
  p = 0;
  n++;
  n++;
  for (i = 1; i < t; i <<= 1) j++;
  j++;
  if (i > t) return 0;
  for (k = 49; k >= 0; k--)
    if (n & (1ll << k)) {
      p += c[k][j];
      j--;
      if (j < 0) break;
    }
  if (t == 1) p--;
  return p;
}
int main() {
  cin >> n >> t;
  do1();
  cout << do2();
  return 0;
}
