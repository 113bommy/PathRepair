#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a;
  cin >> a;
  int ans = 0;
  while (a) {
    if (a % 8 == 0) ++ans;
    a /= 8;
  }
  cout << ans << endl;
}
