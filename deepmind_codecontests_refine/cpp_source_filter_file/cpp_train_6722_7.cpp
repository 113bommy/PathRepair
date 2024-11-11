#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = sqrt(n); i > 0; i++) {
    if (i * n / i == n) {
      cout << i << " " << n / i;
      return 0;
    }
  }
}
