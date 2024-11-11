#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  cin >> n >> a;
  if (a % 2) {
    cout << a / 2 + 1;
  } else {
    cout << (n + 1 - a) / 2 + 1;
  }
  return 0;
}
