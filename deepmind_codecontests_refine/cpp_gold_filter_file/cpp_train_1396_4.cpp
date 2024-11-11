#include <bits/stdc++.h>
using namespace std;
long long a, b;
long long ans;
int main() {
  cin >> a >> b;
  while (b) {
    ans += a / b;
    a %= b;
    swap(b, a);
  }
  cout << ans;
  return 0;
}
