#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, n;
  cin >> x >> n;
  if (n / 2 >= x) {
    cout << x << endl;
  }
  if (x / 2 >= n) {
    cout << n << endl;
  } else {
    cout << (n + x) / 3 << endl;
  }
}
