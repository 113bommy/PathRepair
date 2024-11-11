#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[4];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3, greater<int>());
  if (a[0] < a[1] + a[2])
    cout << "0" << endl;
  else
    cout << a[0] - a[1] - a[2] + 1 << endl;
  return 0;
}
