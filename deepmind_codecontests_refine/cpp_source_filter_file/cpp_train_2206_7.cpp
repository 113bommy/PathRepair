#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MOD2 = 998244353;
const long long N = 1e6 + 5;
const long double pi = 3.14159265359;
void SRAND() {
  auto duration = std::chrono::system_clock::now().time_since_epoch();
  auto millis =
      std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
  srand(millis);
}
long long q, n, ans;
string s, t, a, b;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> q;
  while (q--) {
    cin >> n >> s >> t;
    a = s;
    b = t;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a != b) {
      cout << "NO\n";
      continue;
    }
    ans = 0;
    for (long long i = 0; i < n; i++) {
      long long ti = i;
      for (long long j = 0; j < n; j++) {
        if (s[j] == t[ti] && ti < n) ti++;
      }
      ans = max(ans, ti - i);
    }
    cout << n - ans << "\n";
  }
  return 0;
}
