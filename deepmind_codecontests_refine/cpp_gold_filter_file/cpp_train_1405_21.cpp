#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, value;
  cin >> n >> value;
  int init = n - value;
  for (int i = 1; i < n; i++) {
    cin >> value;
    (value += ((i % 2 != 0) ? n - init : init)) %= n;
    if (value != i) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}
