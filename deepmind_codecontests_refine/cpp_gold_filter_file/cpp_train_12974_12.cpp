#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t, s;
  cin >> n >> t;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    t -= (86400 - s);
    if (t <= 0) return cout << i, 0;
  }
}
