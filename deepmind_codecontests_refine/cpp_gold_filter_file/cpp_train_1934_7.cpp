#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n;
  if (n % 2 == 0) {
    k = n / 2;
    cout << k << endl;
    for (int i = 0; i < k; i++) cout << 2 << " ";
  } else {
    k = (n - 3) / 2 + 1;
    cout << k << endl;
    for (int i = 0; i < k - 1; i++) cout << 2 << " ";
    cout << 3;
  }
  return 0;
}
