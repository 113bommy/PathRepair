#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  cout << max(n - abs(a - d) - abs(b - c), 0) * 1ll * n;
}
