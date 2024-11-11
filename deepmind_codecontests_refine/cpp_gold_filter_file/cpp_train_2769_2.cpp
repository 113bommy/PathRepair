#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  if (a >= b) {
    int temp = a;
    a = b;
    b = temp;
  }
  long long ans = 1;
  for (int i = 2; i <= a; i++) {
    ans *= i;
  }
  cout << ans << endl;
  return 0;
}
