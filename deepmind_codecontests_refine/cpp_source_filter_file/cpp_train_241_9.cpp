#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[3], i, total = 0;
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);
  if ((a[0] + a[1]) % 2 == 0) {
    cout << a[1] << endl;
    return 0;
  }
  cout << a[2];
  return 0;
}
