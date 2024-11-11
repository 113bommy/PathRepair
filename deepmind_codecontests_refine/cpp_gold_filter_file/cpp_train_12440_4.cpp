#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  set<int> d;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    while (a % 3 == 0 || a % 2 == 0) {
      if (a % 3 == 0) {
        if (a % 2 == 0) {
          a /= 3;
        } else {
          a /= 3;
        }
      } else if (a % 2 == 0) {
        a /= 2;
      }
    }
    d.insert(a);
  }
  int c = 0;
  for (int f : d) {
    c++;
  }
  if (c == 1) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
  return 0;
}
