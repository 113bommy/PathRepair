#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  int x[a];
  for (int i = 0; i < a; i++) {
    cin >> x[i];
    if (360 % (180 - x[i]) == 0) {
      cout << "YES";
    } else {
      cout << "No";
    }
    cout << endl;
  }
  return 0;
}
