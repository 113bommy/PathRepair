#include <bits/stdc++.h>
using namespace std;
int main() {
  int sum = 0, maxi = 0, x;
  for (int i = 0; i < 3; i++) {
    cin >> x;
    if (x > maxi) {
      maxi = x;
    }
    sum += x;
  }
  if (sum - maxi <= maxi) {
    cout << maxi - (sum - maxi) + 1;
  } else {
    cout << 0;
  }
}
