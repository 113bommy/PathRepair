#include <bits/stdc++.h>
using namespace std;
int main() {
  long long j = 0, x, y;
  cin >> x >> y;
  if (x > y) swap(x, y);
  for (int i = 1; i <= x; i++) {
    int z = (i + y) / 5 - i / 5;
    j += z;
  }
  cout << j;
  return 0;
}
