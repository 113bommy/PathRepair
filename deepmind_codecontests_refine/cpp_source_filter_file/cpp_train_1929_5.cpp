#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  double px, py, vx, vy, a, b, c, d;
  cin >> px >> py >> vx >> vy >> a >> b >> c >> d;
  double vs = sqrt(vx * vx + vy * vy);
  cout << setprecision(15) << px + vx * b / vs << " " << py + vy / vs * b
       << endl;
  cout << setprecision(15) << px - vy / vs * a / 2 << " "
       << py + vx / vs * a / 2 << endl;
  cout << setprecision(15) << px - vy / vs * c / 2 << " "
       << py + vx / vs * c / 2 << endl;
  cout << setprecision(15) << px - vy / vs * c / 2 - vx / vs * d << " "
       << py + vx / vs * c / 2 - vy / vs * d << endl;
  cout << setprecision(15) << px + vy / vs * c / 2 - vx / vs * d << " "
       << py + vx / vs * c / 2 - vy / vs * d << endl;
  cout << setprecision(15) << px + vy / vs * c / 2 << " "
       << py + vx / vs * c / 2 << endl;
  cout << setprecision(15) << px + vy / vs * a / 2 << " "
       << py + vx / vs * a / 2 << endl;
  return 0;
}
