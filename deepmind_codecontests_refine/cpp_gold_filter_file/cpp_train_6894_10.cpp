#include <bits/stdc++.h>
const int N = 1000006;
const long long M = 998244353;
using namespace std;
void debug(string var, int val) { cout << var << " : " << val << endl; }
int gcd(int f, int s) {
  if (s == 0)
    return f;
  else
    return gcd(s, f % s);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    if (a % b != 0)
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}
