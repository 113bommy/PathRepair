#include <bits/stdc++.h>
using namespace std;
long long int *a;
long long int *b;
int n;
long long int what(long long x) {
  long long int s = 0;
  for (int i = 0; i < n; i++) {
    s += (x * a[i]) / b[i];
  }
  return s;
}
int main() {
  int i, j;
  int c;
  cin >> n >> c;
  a = new long long int[n];
  b = new long long int[n];
  for (i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  c = c - n;
  long long int l = 0;
  long long int r = ((c + 1) * b[0]) / a[0] + 3;
  long long int x;
  x = l;
  while (r - l > 1) {
    if (what(x) < c)
      l = x;
    else
      r = x;
    x = (l + r) / 2;
  }
  long long int rl = r;
  l = 0;
  r = ((c + 1) * b[0]) / a[0] + 3;
  x = l;
  while (r - l > 1) {
    if (what(x) <= c)
      l = x;
    else
      r = x;
    x = (l + r) / 2;
  }
  cout << (r - rl);
  return 0;
}
