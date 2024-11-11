#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);
  int diff = a[2] - (a[1] + a[0]);
  if (diff < 0) diff = 0;
  cout << diff << endl;
}
