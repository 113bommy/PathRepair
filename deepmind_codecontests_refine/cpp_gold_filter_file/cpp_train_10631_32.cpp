#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  int array[n];
  for (int i = 0; i < n; i++) {
    cin >> array[i];
  }
  int tr = 0;
  for (int i = 0; i < n - 1; i++) {
    if (array[i] < array[i + 1]) {
    } else {
      tr = 1;
    }
  }
  if (tr == 0) {
    cout << "0\n";
    exit;
  } else {
    cout << n + 1 << "\n";
    cout << "2 " << n << " 1\n";
    cout << "1 " << n << " 1000000\n";
    for (int i = 0; i < n - 1; i++) {
      cout << "2 " << i + 1 << " " << (1000000) - (2 * i) << "\n";
    }
  }
}
