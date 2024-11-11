#include <bits/stdc++.h>
int main() {
  char loop[] = "6842";
  long long n;
  std::cin >> n;
  if (n == 0) {
    std::cout << '1';
  } else {
    std::cout << loop[n % 4];
  }
}
