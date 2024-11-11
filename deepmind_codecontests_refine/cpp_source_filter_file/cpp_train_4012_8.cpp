#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  if (b < a) swap(a, b);
  int ans = 0;
  while (a > 0) {
    ++a;
    b -= 2;
    ++ans;
    if (b < a) swap(a, b);
  }
  cout << ans;
}
