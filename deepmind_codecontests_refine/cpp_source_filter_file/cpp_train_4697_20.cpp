#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);
  if (a[0] + a[1] > a[2])
    cout << "0";
  else
    cout << a[2] - (a[0] - a[1] - 1);
}
