#include <bits/stdc++.h>
using namespace std;
int main() {
  int a = 0, b = 0, j = 0;
  cin >> a;
  for (int i = 0; i < a; i++) {
    cin >> b;
    if (b == '0') {
      j++;
    } else {
      j--;
    }
  }
  cout << abs(j);
  return 0;
}
