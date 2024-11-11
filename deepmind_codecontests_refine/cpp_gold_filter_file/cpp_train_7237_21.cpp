#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a = 0;
  cin >> n >> a;
  if (a % 2 == 0) {
    cout << (n - a + 2) / 2;
  } else {
    cout << (a + 1) / 2;
  }
  return 0;
}
