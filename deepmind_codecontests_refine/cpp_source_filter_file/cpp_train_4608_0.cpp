#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, n, m;
    cin >> a >> b >> n >> m;
    if (a + b >= n + m && m < min(a, b))
      cout << "Yes\n";
    else
      cout << "No\n";
  }
}
