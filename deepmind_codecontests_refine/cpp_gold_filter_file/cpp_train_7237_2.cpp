#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, n;
  cin >> n >> a;
  if (a % 2 == 1) {
    cout << (a + 1) / 2 << endl;
  } else {
    cout << (n - a + 2) / 2 << endl;
  }
  return 0;
}
