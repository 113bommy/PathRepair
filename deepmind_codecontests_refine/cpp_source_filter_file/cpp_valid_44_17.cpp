#include <bits/stdc++.h>
using namespace std;
int tc, cs = 1;
void test_cases() {
  long long a, b;
  cin >> a >> b;
  if (a > b) swap(a, b);
  if (a == b) {
    if (a == 0)
      cout << 0 << '\n';
    else
      cout << 1 << '\n';
  } else {
    if (b - a == 1)
      cout << -1 << '\n';
    else
      cout << 2 << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tc;
  while (tc--) {
    test_cases();
  }
}
