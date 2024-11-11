#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a == 0)
    return b;
  else
    return gcd(b % a, a);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n;
  cin >> n;
  long long int ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  long long int x1 = ax - bx;
  long long int x2 = cx - bx;
  if ((bx < ax && ax < cx) || (cx < ax && ax < bx) || (by < ay && ay < cy) ||
      (cy < ay && ay < by))
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
}
