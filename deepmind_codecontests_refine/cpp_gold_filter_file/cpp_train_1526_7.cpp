#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, i = 0;
  cin >> n >> a >> b;
  a--;
  b--;
  while (n != 1) {
    n = n / 2;
    i++;
  }
  for (int j = 1; j <= i; j++) {
    if (j == i) {
      cout << "Final!";
      break;
    }
    a = a / 2;
    b = b / 2;
    if (a == b) {
      cout << j;
      break;
    }
  }
}
