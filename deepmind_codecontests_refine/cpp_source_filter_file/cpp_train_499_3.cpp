#include <iostream>
using namespace std;
int a, b, c, x, y, r1, r2, r3;
int main() {
  cin >> a >> b >> c >> x >> y;
  r1 = a*x+b*y;
  r2 = c*2*max(x,y);
  r3 = min(x,y)*2*c+abs(x-y)*(x>y ? a:b);
  cout << min(r1,r2,r3);
  return 0;
}