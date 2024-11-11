#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;
long long x;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  cin >> x;
  vector<pair<long long, long long> > ans;
  for (long long n = 1;; n++) {
    long long up = 6 * x + n * n * n - n;
    long long down = 3 * n * n + 3 * n;
    if (down > up) break;
    if (n > up / down) break;
    if (up % down == 0) {
      ans.push_back({n, up / down});
      if (n != up / down) ans.push_back({up / down, n});
    }
  }
  sort((ans).begin(), (ans).end());
  cout << ((int)(ans).size()) << '\n';
  for (auto p : ans) {
    cout << p.first << ' ' << p.second << '\n';
  }
  return 0;
}
