#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  if (n == 0) {
    cout << 1;
    return 0;
  }
  int index = n - (n / 4) * 4;
  if (index == 1) {
    cout << 8;
  } else if (index == 2) {
    cout << 4;
  } else if (index == 3) {
    cout << 2;
  } else if (index == 0) {
    cout << 6;
  }
  return 0;
}
