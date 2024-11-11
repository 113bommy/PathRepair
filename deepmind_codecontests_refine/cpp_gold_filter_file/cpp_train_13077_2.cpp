#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, ans = 1;
  cin >> a >> b;
  if (b - a >= 10) {
    cout << 0 << endl;
  } else {
    for (long long i = a + 1; i <= b; i++) {
      ans = ans * (i % 10);
    }
    cout << ans % 10 << endl;
  }
}
