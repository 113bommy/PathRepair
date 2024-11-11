#include <bits/stdc++.h>
using namespace std;
int c[200000], n, a, b, sum, k;
char s;
int main() {
  cin >> n >> a >> b;
  int a1 = a;
  int b1 = b;
  sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    if (s == '*') c[i] = 1;
    if (s == '.') c[i] = 0;
  }
  c[n + 1] = 1;
  int i = 0;
  while (i < n) {
    i++;
    k = 0;
    if (c[i] == 0) {
      while (c[i] == 0) {
        i++;
        k++;
      }
      i--;
    }
    if (k % 2 == 0) {
      a = a - k / 2;
      b = b - k / 2;
    } else {
      if (a > b) {
        b = b - k / 2;
        a = a - k / 2 - 1;
      } else {
        b = b - k / 2 - 1;
        a = a - k / 2;
      }
    }
  }
  if (a <= 0)
    sum = sum + a1;
  else
    sum = sum + a1 - a;
  if (b <= 0)
    sum = sum + b1;
  else
    sum = sum + b1 - b;
  cout << sum;
}
