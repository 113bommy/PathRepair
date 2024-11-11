#include <bits/stdc++.h>
using namespace std;
bool valid(int n, int x) {
  if (n == 1) {
    return x == 1;
  }
  if (n == 2) {
    return false;
  }
  if (n == 3) {
    return x == 1 || x == 2 || x == 4 || x == 5;
  }
  if (n % 2 == 1) {
    int f = (1 + (n / 2) * (n / 2)) / 2;
    int t = n / 2;
    x -= x % 2;
    if (x % 4 == 2) {
      t--;
      x -= 2;
    }
    f += t / 2;
    return f * 4 >= x;
  } else {
    int f = (1 + (n / 2 - 1) * (n / 2 - 1)) / 2;
    return f * 4 >= x && x % 4 == 0;
  }
}
int main() {
  int x;
  cin >> x;
  int n = 1;
  while (!valid(n, x)) {
    n++;
  }
  cout << n << '\n';
  return 0;
}
