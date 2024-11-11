#include <bits/stdc++.h>
using namespace std;
int main() {
  long long X, Y, Z;
  cin >> X >> Y >> Z;
  long long x, y, z;
  cin >> x >> y >> z;
  long long a[10];
  for (int i = 1; i <= 6; i++) cin >> a[i];
  long long sum = 0;
  if (X > x) sum += a[6];
  if (X < 0) sum += a[5];
  if (Y > y) sum += a[2];
  if (Y < 0) sum += a[1];
  if (Z > z) sum += a[4];
  if (Z < 0) sum += a[3];
  cout << sum << endl;
  return 0;
}
