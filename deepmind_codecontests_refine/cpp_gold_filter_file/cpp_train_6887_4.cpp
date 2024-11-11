#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long int k;
  std::cin >> k;
  unsigned long long int l;
  std::cin >> l;
  int count = 0;
  while (l > k) {
    if (l % k == 0) {
      count++;
      l /= k;
    } else
      break;
  }
  if (l == k) {
    std::cout << "YES\n";
    std::cout << count << "\n";
  } else
    std::cout << "NO\n";
  return 0;
}
