#include <bits/stdc++.h>
using namespace std;
void solve() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, a, b, c, d, n;
  cin >> t;
  while (t--) {
    cin >> n >> a >> b >> c >> d;
    int a1 = (a + b) * n, a2 = (a - b) * n, c1 = c - d, c2 = c + d;
    if (a2 > c2 || a1 < c1)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}
int main() { solve(); }
