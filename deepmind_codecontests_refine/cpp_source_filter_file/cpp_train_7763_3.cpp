#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s, a;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    a ^= int((-1 + sqrt(1 + 8 * s)) / 2);
  }
  cout << (a ? "NO" : "YES");
  return 0;
}
