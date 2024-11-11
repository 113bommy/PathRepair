#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if (a + b >= n) {
    cout << (n - a) << endl;
  } else {
    cout << (b + 1) << endl;
  }
  return 0;
}
