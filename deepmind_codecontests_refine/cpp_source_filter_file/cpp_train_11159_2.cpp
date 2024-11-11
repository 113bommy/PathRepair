#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int flag = 1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x % 2 == 0) {
      cout << x / 2 << endl;
    } else {
      cout << (x + flag) / 2 << '\n';
      flag = -1;
    }
  }
  return 0;
}
