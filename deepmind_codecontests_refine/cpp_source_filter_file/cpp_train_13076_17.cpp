#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 * 3;
const long long M = 1e3;
long long n;
string s[N];
long long ans = 0, res, mx = -123;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  for (long long i = 1; i <= 7; ++i) {
    for (long long j = 1; j <= n; ++j) {
      if (s[j][i] == '1') {
        ans++;
      }
    }
    mx = max(ans, mx);
    ans = 0;
  }
  cout << mx;
}
