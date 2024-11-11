#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= 9; i++) {
    int sum = n * i;
    if (sum % 10 == k) {
      cout << i << endl;
      break;
    } else if (sum % 10 == 0) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
