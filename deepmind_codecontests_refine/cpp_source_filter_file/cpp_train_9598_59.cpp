#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  if (n - b >= n - a) {
    cout << b + 1 << endl;
  } else {
    cout << a + 1 << endl;
  }
  return 0;
}
