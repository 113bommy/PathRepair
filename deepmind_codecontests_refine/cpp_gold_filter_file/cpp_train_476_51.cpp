#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  {
    long long test;
    test = 1;
    while (test--) {
      long long n, a, b, c, d;
      cin >> n >> a >> b >> c >> d;
      long long ans1 = n * a + 2 * c;
      long long ans2 = b * n + 2 * d;
      if (ans2 > ans1)
        cout << "First";
      else if (ans1 > ans2)
        cout << "Second";
      else
        cout << "Friendship";
    }
  }
}
