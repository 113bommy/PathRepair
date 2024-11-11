#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c = 0, d = 0;
  std::cin >> n;
  char a[n];
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    if (a[i] == 'L') {
      c--;
    } else if (a[i] == 'R') {
      d++;
    }
  }
  std::cout << abs(d - c) << std::endl;
}
