#include <bits/stdc++.h>
using namespace std;
int main() {
  int X;
  cin >> X;
  int ans = 1;
  for (int i = 2; i * i <= X; i++) {
    for (int b = i; b < X; b *= i) {
      ans = max(ans, b);
    }
  }
  cout << ans << endl;
}
