#include <bits/stdc++.h>
using namespace std;
long long n, x, c[19], i, s, s1, k;
int main(void) {
  cin >> x;
  n = x;
  while (n > 0) {
    c[k] = n % 10;
    s += c[k];
    n /= 10;
    ++k;
  }
  --k;
  s1 = c[k] - 1 + k * 9;
  if (s >= s1 || k == 0) {
    cout << x;
    return 0;
  }
  i = 1;
  while (c[k - i] == 9 && i < k) {
    ++i;
  }
  if (c[k - i + 1] == 9) {
    c[k - i + 1] = 8;
    for (i = k - i; i >= 0; --i) c[i] = 9;
  } else {
    --c[k];
    for (i = k - 1; i >= 0; --i) c[i] = 9;
  }
  n = 0;
  for (i = k; i >= 0; --i) {
    n = n * 10 + c[i];
  }
  cout << n;
  return 0;
}
