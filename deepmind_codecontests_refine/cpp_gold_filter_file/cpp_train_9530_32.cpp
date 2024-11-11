#include <bits/stdc++.h>
const long long N = 1007;
using namespace std;
int main() {
  int n, b, a;
  string s;
  bool q = false;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s >> b >> a;
    if (b >= 2400 && a - b > 0) q = true;
  }
  if (q)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
