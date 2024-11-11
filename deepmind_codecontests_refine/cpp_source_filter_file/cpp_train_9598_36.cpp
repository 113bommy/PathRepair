#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if (a + b >= n) {
    cout << (n - 2) << endl;
  } else {
    cout << (b + 1) << endl;
  }
  return 0;
}
