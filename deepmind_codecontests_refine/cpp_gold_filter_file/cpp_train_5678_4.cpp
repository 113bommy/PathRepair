#include <bits/stdc++.h>
using namespace std;
int main() {
  long long m, sum, p;
  cin >> m;
  for (int i = 5; i < 400006; i++) {
    p = 5, sum = 0;
    while (i / p) sum += i / p, p *= 5;
    if (sum == m) {
      cout << "5\n"
           << i << ' ' << i + 1 << ' ' << i + 2 << ' ' << i + 3 << ' ' << i + 4;
      return 0;
    }
  }
  cout << 0;
  return 0;
}
