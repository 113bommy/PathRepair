#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  std::cin >> n;
  int k;
  std::cin >> k;
  if (n * 2 == k) {
    std::cout << n << "\n";
    return 0;
  }
  if ((n * 2) < k) {
    std::cout << "0\n";
    return 0;
  }
  int val = (k - (n * 2));
  while (val > 0) {
    val--;
    n--;
  }
  std::cout << n << "\n";
}
