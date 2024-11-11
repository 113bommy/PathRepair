#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c;
  cin >> a >> b >> c;
  if (a >= c || b >= c) {
    cout << "0";
  } else if (a <= 0 && b <= 0) {
    cout << "-1";
  } else {
    long long int count = 0;
    while (a < c && b < c) {
      if (a > b) {
        swap(a, b);
      } else if (a < 0) {
        count += (abs(a) / b + (abs(a) % b));
        if (abs(a) % b) {
          long long int r = abs(a) % b;
          a = (b - r);
        } else {
          a = 0;
        }
      } else {
        long long int p = b;
        b += a;
        a = p;
        count++;
      }
    }
    cout << count;
  }
}
