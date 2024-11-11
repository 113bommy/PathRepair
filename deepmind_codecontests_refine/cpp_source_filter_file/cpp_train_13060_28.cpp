#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << n / 2 << " " << n / 2 << endl;
  } else {
    cout << 9 << " " << (n - 9) << endl;
  }
  return 0;
}
