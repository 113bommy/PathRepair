#include <iostream>
int main() {
  int64_t n, m;
  std::cin >> n >> m;
  for (int i=m/n; i>=1; --i)
    if (m%i==0) {
      std::cout << i << endl;
      return 0;
    }
  return 0;
}