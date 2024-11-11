#include <bits/stdc++.h>
int main() {
  int a, b, c, d[1000001] = {}, s = 0;
  for (int i = 1; i <= 1000000; i += 1)
    for (int j = i; j <= 1000000; j += i) ++d[j];
  std::cin >> a >> b >> c;
  for (int i = 1; i <= a; i += 1)
    for (int j = 1; j <= b; j += 1)
      for (int k = 1; k <= c; k += 1) s += d[i * j * k];
  std::cout << s;
  return 0;
}
