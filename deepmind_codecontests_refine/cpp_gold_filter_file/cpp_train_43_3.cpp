#include <bits/stdc++.h>
using namespace std;
int possibilies(int n, int c, int b, int a) {
  int result = 0;
  for (int i = 0; i <= a; i++) {
    for (int j = min(n - (2 * i), b); j >= 0; j--) {
      int z = (n - (2 * i) - j) * 2;
      if (z <= c) {
        result += 1;
      }
    }
  }
  return result;
}
int main(int argc, const char* argv[]) {
  int n = 10, a = 5, b = 5, c = 5;
  cin >> n >> a >> b >> c;
  std::cout << possibilies(n, a, b, c);
  return 0;
}
