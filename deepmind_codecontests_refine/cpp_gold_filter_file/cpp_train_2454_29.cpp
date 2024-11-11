#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, i, j, k, q, w, e;
  cin >> a >> b >> c;
  i = a / 1;
  j = b / 2;
  k = c / 4;
  int min = i;
  if (j <= i && j <= k)
    min = j;
  else if (k <= i && k <= j)
    min = k;
  q = min * 1;
  w = min * 2;
  e = min * 4;
  cout << q + w + e;
  return 0;
}
