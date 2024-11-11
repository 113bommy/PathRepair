#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (k % 2 != 0) {
    cout << k / 2 + 1;
  } else {
    cout << n / 2 - k / 2 + 1;
  }
}
