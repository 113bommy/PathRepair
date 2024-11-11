#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  int f = 0, s = 0;
  while (n >= 4 && n % 7 != 0) {
    f++;
    n -= 4;
  }
  if (n % 7 == 0) {
    for (int i = 0; i < f; i++) {
      cout << "4";
    }
    while (n != 1) {
      cout << "7";
      n /= 7;
    }
    cout << endl;
    return 0;
  } else {
    cout << "-1" << endl;
    return 0;
  }
  cout << endl;
}
