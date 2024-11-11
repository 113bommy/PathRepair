#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  unsigned a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);
  if ((a[1] - a[0]) % 2) {
    if (!((a[2] - a[1]) % 2))
      rotate(a, a + 1, a + 3);
    else
      swap(a[1], a[2]);
  }
  unsigned count = a[0];
  a[2] += a[0];
  a[1] -= a[0];
  a[0] = 0;
  count += a[1];
  cout << count << endl;
  return 0;
}
