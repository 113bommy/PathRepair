#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    if (n == 1) {
      cout << 0 << endl;
      continue;
    }
    int three = 0;
    while (n % 3 == 0) {
      n = n / 3;
      three++;
      continue;
    }
    int two = 0;
    while (n % 2 == 0) {
      n = n / 2;
      two++;
    }
    if (n != 1) {
      cout << -1 << endl;
      continue;
    }
    if (two > three) {
      cout << -1 << endl;
      continue;
    }
    cout << three + three - two << endl;
  }
}
