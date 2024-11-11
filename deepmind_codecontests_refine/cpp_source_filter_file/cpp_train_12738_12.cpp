#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  if (x == 1)
    cout << -1 << endl;
  else {
    for (int i = x; i >= 1; i--) {
      if (i == 1)
        cout << i << endl;
      else
        cout << i << " ";
    }
  }
  return 0;
}
