#include <bits/stdc++.h>
using namespace std;
int main() {
  long long A, B;
  cin >> A >> B;
  long long x, y, z;
  cin >> x >> y >> z;
  long long yellow = 2 * x + y;
  long long blue = 3 * z + y;
  if (A < yellow && B < blue)
    cout << (yellow - A) + (blue - B) << endl;
  else if (A > yellow && B < blue)
    cout << (blue - B);
  else if (A < yellow && B > blue)
    cout << (yellow - A);
  else
    cout << 0;
  return 0;
}
