#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  for (int i = 9; i >= 1; i--) {
    if (n % i == 0) {
      cout << n / i << endl;
      for (int j = 1; j <= (n / i); j++) cout << i << " ";
      return 0;
    }
  }
  return 0;
}
