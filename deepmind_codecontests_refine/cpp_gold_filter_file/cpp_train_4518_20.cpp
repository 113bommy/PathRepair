#include <bits/stdc++.h>
using namespace std;
template <class T>
int len(const T& c) {
  return (int)c.size();
}
double a, b, n;
int main() {
  cin >> a >> b >> n;
  if (a == b) {
    cout << 1 << endl;
    return 0;
  } else if (b == 0) {
    cout << "0";
    return 0;
  } else if (a == 0) {
    cout << "No solution";
    return 0;
  }
  a = b / a;
  if (a == (int)a) {
    for (int i = -abs(a); i < (int)abs(a) + 1; i++) {
      if (pow(i, n) == a) {
        cout << i << endl;
        return 0;
      }
    }
  } else {
    cout << "No solution";
    return 0;
  }
  cout << "No solution";
}
