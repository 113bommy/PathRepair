#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a1 = 0, b2 = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 1)
      a1++;
    else
      b2++;
  }
  if (n == 1) {
    if (a1)
      cout << a1 << endl;
    else
      cout << b2 << endl;
  } else {
    int flag = 0;
    if (b2) {
      cout << 2;
      b2--;
      flag = 1;
    }
    if (a1) {
      if (flag)
        cout << " " << 1;
      else
        cout << 1;
      a1--;
    }
    while (b2--) {
      cout << " " << 2;
    }
    while (a1--) {
      cout << " " << 1;
    }
  }
  cout << endl;
}
