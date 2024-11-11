#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 2) {
    cout << 3 << endl;
  } else if (n >= 4) {
    cout << n * 3 / 2 << endl;
  }
  return 0;
}
