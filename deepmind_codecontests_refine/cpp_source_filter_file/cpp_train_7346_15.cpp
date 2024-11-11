#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum = 0, c = 0;
  cin >> n;
  if (n == 2)
    cout << 1 << endl << 2;
  else if (n == 1)
    cout << 1 << endl << 2;
  else {
    while (sum <= n) {
      c++;
      sum += c;
    }
    cout << c - 1 << endl;
    sum = 0;
    for (int i = 1; i < c - 1; i++) {
      sum += i;
      cout << i << " ";
    }
    cout << n - sum;
  }
  return 0;
}
