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
  long long ans;
  for (int i = 1; i <= a; i++) {
    ans *= a;
  }
  cout << ans << endl;
  return 0;
}
