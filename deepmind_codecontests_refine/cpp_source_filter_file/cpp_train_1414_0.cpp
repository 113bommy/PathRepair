#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c;
  cin >> a >> b >> c;
  if (b >= a && c < a) {
    if (c < a && b % a != 0) {
      cout << "-1";
      return 0;
    } else {
      cout << b / a;
    }
  } else if (c >= a && b < a) {
    if (b < a && c % a != 0)
      cout << "-1";
    else {
      cout << c / a;
    }
  } else if (c == a && b == a) {
    cout << "2";
  } else if (c < a && b < a) {
    cout << "-1";
  } else if (c > a && b > a) {
    cout << b / a + c / a;
  }
  return 0;
}
