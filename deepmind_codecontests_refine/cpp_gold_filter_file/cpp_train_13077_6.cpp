#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> b >> a;
  if (a - b >= 5) {
    cout << 0;
    return 0;
  }
  a %= 10, b %= 10;
  if (a < b) a += 10;
  int ans = 1;
  for (int i = b + 1; i <= a; i++) {
    ans = (ans * i) % 10;
  }
  cout << ans;
  return 0;
}
