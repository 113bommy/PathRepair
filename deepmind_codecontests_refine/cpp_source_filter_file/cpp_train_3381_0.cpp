#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long a, b, s, co = 0;
  cin >> a >> b >> s;
  co = abs(a + b);
  if (co > s) {
    cout << "No";
  } else if ((s - co) % 2 == 0) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  return 0;
}
