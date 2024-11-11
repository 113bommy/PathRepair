#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  t = 1;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (min(b, c) >= a)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
