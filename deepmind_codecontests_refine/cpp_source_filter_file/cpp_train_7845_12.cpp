#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5, INF = 1e9 + 7;
int n;
int usd[N];
int main() {
  cin >> n;
  for (int i = 3; i <= 100; ++i) {
    if (((i - 2) * 180) % i == 0) usd[((i - 2) * 180) / i]++;
  }
  for (int i = 1; i <= n; ++i) {
    int t;
    cin >> t;
    if (usd[t] == true)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
