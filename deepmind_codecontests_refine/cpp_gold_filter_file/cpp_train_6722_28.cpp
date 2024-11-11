#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = sqrt(n); i > 0; i--) {
    if ((n / i) * i == n) {
      cout << i << " " << n / i;
      return 0;
    }
  }
}
