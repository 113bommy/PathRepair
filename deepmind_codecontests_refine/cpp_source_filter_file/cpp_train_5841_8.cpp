#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  if (bx < ax && by < ay) {
    if (cx < ax && cy < ay) {
      cout << "YES";
      return 0;
    } else {
      cout << "NO";
      return 0;
    }
  }
  if (bx < ax && by > ay) {
    if (cx < ax && cy > ay) {
      cout << "YES";
      return 0;
    } else {
      cout << "NO";
      return 0;
    }
  }
  if (bx > ax && by < ay) {
    if (cx > ax && cy < ay) {
      cout << "YES";
      return 0;
    } else {
      cout << "NO";
      return 0;
    }
  }
  if (bx > ax && by > ay) {
    if (cx < ax && cy < ay) {
      cout << "YES";
      return 0;
    } else {
      cout << "NO";
      return 0;
    }
  }
}
