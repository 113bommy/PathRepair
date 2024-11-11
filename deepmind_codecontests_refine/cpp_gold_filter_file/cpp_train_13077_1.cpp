#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  long long ans = 1, x = a + 1;
  for (long long i = x; i <= b; ++i) {
    ans = (ans * i) % 10;
    if (ans == 0) break;
  }
  cout << ans << endl;
}
