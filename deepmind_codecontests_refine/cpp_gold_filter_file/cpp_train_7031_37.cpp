#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  int min = 999999;
  for (int i = 0; i < 4; i++) {
    cin >> a;
    if (a < min) min = a;
  }
  int mid;
  cin >> a >> mid;
  if (a >= min)
    cout << "0";
  else {
    if (mid < min && a != mid)
      cout << mid - a + 1;
    else
      cout << min - a;
  }
  return 0;
}
