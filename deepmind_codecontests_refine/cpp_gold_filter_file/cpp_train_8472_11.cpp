#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  long long middle = n / 2;
  if (n % 2 == 1) {
    middle += 1;
  }
  if (k <= middle) {
    cout << k * 2 - 1 << endl;
  } else {
    cout << (k - middle) * 2 << endl;
  }
  return 0;
}
