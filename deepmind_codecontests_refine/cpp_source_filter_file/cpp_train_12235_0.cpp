#include <bits/stdc++.h>
using namespace std;
int main() {
  int T = 1;
  while (T--) {
    int N;
    std::cin >> N;
    long long int z = 0;
    z = 2 * 4 * 3 * (1 << 2 * (N - 3));
    z += (N - 3) * 9 * 4 * (1 << 2 * (N - 4));
    std::cout << z << std::endl;
  }
  return 0;
}
