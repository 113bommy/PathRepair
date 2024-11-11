#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  if (a == b) {
    cout << 0;
    return 0;
  }
  if (b == 0) {
    cout << 1;
    return 0;
  }
  if (b <= a / 2) {
    cout << b;
    return 0;
  }
  cout << a - b;
}
