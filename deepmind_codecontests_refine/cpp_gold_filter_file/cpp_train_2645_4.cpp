#include <bits/stdc++.h>
using namespace std;
const int OO = 0x3f3f3f3f, N = 1e5 + 5, mod = 1e9 + 7;
long long a, b, ans;
int main() {
  cin >> a >> b;
  while (a && b) {
    ans += a / b;
    long long tmp = a % b;
    a = b, b = tmp;
  }
  cout << ans;
  return 0;
}
