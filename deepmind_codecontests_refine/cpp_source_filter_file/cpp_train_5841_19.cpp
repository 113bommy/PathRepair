#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n;
  cin >> n;
  long long ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  if ((bx < ax && cx < ax && by < ay && cy < ay) ||
      (bx > ax && cx > ax && by > ay && cy > ay))
    cout << "YES";
  else if ((bx < ax && cx < ax && by > ay && cy > ay) ||
           (bx < ax && cx < ax && by > ay && cy > ay))
    cout << "YES";
  else
    cout << "NO";
}
