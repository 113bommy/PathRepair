#include <bits/stdc++.h>
int main() {
  long long n, k, bat;
  std::cin >> n >> bat;
  std::string a;
  std::cin >> a;
  std::vector<int> ind(n, 0);
  long long cur = 0, ans = n, L = 0, R = n - 2;
  for (k = 0; k != n; ++k) {
    if (a[k] == '1')
      ++cur;
    else {
      if (cur > L) L = cur;
      cur = 0;
    }
  }
  if (cur > L) L = cur;
  cur = 0;
  --L;
  for (k = 0; k != n; ++k) {
    if (a[k] == '0') cur = k;
    ind[k] = cur;
  }
  while (R - L > 1) {
    long long m = (L + R) / 2;
    long long cur = 0, b = 1;
    for (k = 0; k < n - 1;) {
      if (k + m + 1 >= n - 1) {
        ++b;
        k += m + 1;
      } else {
        ++b;
        if (k != ind[k + m + 1])
          k = ind[k + m + 1];
        else {
          k = n + 1;
          b = bat + 1;
        }
      }
    }
    if (b <= bat)
      R = m;
    else
      L = m;
  }
  std::cout << R;
}
