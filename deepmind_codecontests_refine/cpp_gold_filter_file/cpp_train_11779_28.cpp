#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z, a, b, c;
  cin >> x >> y >> z >> a >> b >> c;
  int s1 = a - x;
  int s2 = s1 + b - y;
  int s3 = s2 + c - z;
  if (s1 < 0) {
    cout << "NO";
  } else if (s2 < 0) {
    cout << "NO";
  } else if (s3 < 0) {
    cout << "NO";
  } else {
    cout << "YES";
  }
  return 0;
}
