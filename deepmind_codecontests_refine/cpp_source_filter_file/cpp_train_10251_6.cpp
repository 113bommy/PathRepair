#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n;
  if (n % 2 != 0) {
    cout << (n - 1) / 2 - n;
  } else {
    cout << n / 2;
  }
}
