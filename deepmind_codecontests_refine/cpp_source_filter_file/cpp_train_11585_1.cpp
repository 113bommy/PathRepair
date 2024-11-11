#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, a, b;
  cin >> x;
  for (int i = 0; i < x; i++) {
    cin >> a;
    cin >> b;
    int x1 = abs(a - b);
    int result = x1 / 10;
    if (x1 % 10 != 0) {
      result++;
    }
    cout << result;
  }
}
