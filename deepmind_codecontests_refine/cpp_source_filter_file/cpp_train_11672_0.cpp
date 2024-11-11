#include <bits/stdc++.h>
int main() {
  long long n, m, l, k;
  long long rez;
  std::cin >> n >> m >> l >> k;
  rez = (k + l + 1) / m;
  if ((k + l + 1) % m != 0) rez++;
  if (rez * m > n)
    std::cout << -1;
  else
    std::cout << rez;
  return 0;
}
