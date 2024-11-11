#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int max(int a, int b, int c) { return max(a, max(b, c)); }
int min(int a, int b, int c) { return min(a, min(b, c)); }
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int sum = a + b + c - max(a, b, c);
  if (sum >= max(a, b, c))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
