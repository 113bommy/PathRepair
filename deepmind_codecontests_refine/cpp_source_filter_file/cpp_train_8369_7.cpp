#include <bits/stdc++.h>
using namespace std;
string a;
int b;
int long long c = 1;
int long long ans = 0;
int main() {
  cin >> a;
  b = a.length() - 1;
  for (int x = 0; x <= b; x++) {
    int long long t = 1;
    if (a[x] == '1') {
      for (int y = 0; y < 2 * b - x; y++) {
        t *= 2;
        t %= 100000007;
      }
      ans += t;
      ans %= 100000007;
    }
  }
  cout << ans << endl;
}
