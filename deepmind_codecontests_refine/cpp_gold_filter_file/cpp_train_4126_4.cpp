#include <bits/stdc++.h>
using namespace std;
long f(long x) {
  long n = x;
  while (n > 0) {
    x += n % 10;
    n /= 10;
  }
  return x;
}
int main() {
  long n, j = 0, t[100], i;
  cin >> n;
  if (n >= 10000) {
    for (i = n - 90; i <= n; i++)
      if (f(i) == n) t[++j] = i;
  } else {
    for (i = 0; i <= n; i++)
      if (f(i) == n) t[++j] = i;
  }
  cout << j << endl;
  for (i = 1; i <= j; i++) cout << t[i] << endl;
}
