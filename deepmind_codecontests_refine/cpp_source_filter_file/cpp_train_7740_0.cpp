#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
};
int main() {
  point A[3];
  cin >> A[0].x >> A[0].y >> A[1].x >> A[1].y >> A[2].x >> A[2].y;
  long long p = (A[0].x * A[1].y - A[1].x * A[0].y) +
                (A[1].x * A[2].y - A[2].x * A[1].y) +
                (A[2].x * A[0].y - A[0].x * A[2].y);
  if (p == 0)
    cout << "TOWARDS";
  else if (p > 0)
    cout << "LEFT";
  else
    cout << "RIGHT";
  return 0;
}
