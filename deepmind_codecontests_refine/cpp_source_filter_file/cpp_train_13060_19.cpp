#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << 2 << ' ' << n - 2;
  } else {
    cout << 4 << ' ' << n - 4;
  }
}
