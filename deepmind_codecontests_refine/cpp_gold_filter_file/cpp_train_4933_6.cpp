#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, s, t;
  cin >> n >> s >> t;
  long long p[n + 1];
  for (long long i = 0; i < n; i++) cin >> p[i];
  if (s == t) {
    cout << "0";
    return 0;
  }
  long long k = s;
  long long ans = 0;
  while (k != t) {
    k = p[k - 1];
    if (ans >= n) {
      cout << "-1";
      return 0;
    }
    ans++;
  }
  cout << ans << endl;
  return 0;
}
