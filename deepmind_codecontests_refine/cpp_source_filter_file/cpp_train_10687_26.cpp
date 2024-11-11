#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  int k = 0;
  cin >> n >> k;
  for (int i = 0; i <= k; i++) {
    if (n - (n / 10) * 10 == 0) {
      n = n / 10;
    } else {
      n = n - 1;
    }
  }
  cout << n << endl;
  return 0;
}
