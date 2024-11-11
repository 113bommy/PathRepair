#include <bits/stdc++.h>
using namespace std;
int a[17];
int main() {
  cin >> a[1] >> a[2] >> a[3];
  sort(a + 1, a + 4);
  cout << min(0, a[3] - (a[1] + a[2]) + 1);
  return 0;
}
