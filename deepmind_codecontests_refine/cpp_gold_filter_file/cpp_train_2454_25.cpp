#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, ans;
  cin >> a >> b >> c;
  for (long long i = 0; i <= a; i++) {
    if (b >= i * 2 && c >= i * 4) ans = i + i * 2 + i * 4;
  }
  cout << ans;
}
