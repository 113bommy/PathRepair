#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, i, j = 0, t, l;
  int p = 0, h, s, k, d, x, y;
  m = 0;
  h = 0;
  p = 0;
  x = 0;
  std::cin >> n >> k;
  char a[n];
  int b[26];
  int c[26];
  for (i = 0; i < 26; i++) {
    b[i] = -1;
    c[i] = -1;
  }
  for (i = 0; i < n; i++) {
    cin >> a[i];
    b[(a[i] - 65)] = i;
  }
  p = 0;
  for (i = n - 1; i >= 0; i--) c[a[i] - 65] = i;
  for (i = 0; i < n; i++) {
    for (j = 0; j < 26; j++) {
      if (i == c[j]) {
        p++;
        break;
      }
    }
    if (p > k) break;
    for (j = 0; j < 26; j++) {
      if (i == b[j]) {
        p--;
        break;
      }
    }
  }
  if (i == n)
    std::cout << "NO" << std::endl;
  else
    std::cout << "YES" << std::endl;
  return 0;
}
