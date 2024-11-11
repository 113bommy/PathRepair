#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if (n - a > b + 1) {
    cout << b + 1 << endl;
  } else {
    cout << n - a << endl;
  }
  return 0;
}
