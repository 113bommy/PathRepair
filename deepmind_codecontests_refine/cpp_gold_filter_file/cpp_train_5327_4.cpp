#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, s, t;
    cin >> n >> s >> t;
    int u = max(s, t) - (n - min(s, t));
    if (n == s && t == s)
      cout << 1 << endl;
    else
      cout << max(n - s, n - t) + 1 << endl;
  }
}
