#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t, s, x;
  cin >> t >> s >> x;
  cout << ((x >= t && x % s == t % s) || (x > t + s && (x - 1 + s) % s == t)
               ? "YES"
               : "NO")
       << endl;
  return 0;
}
