#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  int flag = 0, flag2 = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    if (a == b) {
      flag++;
    } else {
      flag2++;
    }
  }
  if (flag2 > flag) {
    cout << "Happy Alex" << endl;
  } else {
    cout << "Poor Alex" << endl;
  }
  return 0;
}
