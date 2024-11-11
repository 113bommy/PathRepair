#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
int32_t main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    map<long long, long long, greater<long long>> mp;
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      mp[x]++;
    }
    long long g = 0, s = 0, b = 0;
    g = mp.begin()->second;
    mp.erase(mp.begin()->first);
    while (!mp.empty() && s <= g) {
      s += mp.begin()->second;
      mp.erase(mp.begin()->first);
    }
    while (!mp.empty() && b <= g) {
      b += mp.begin()->second;
      mp.erase(mp.begin()->first);
    }
    if (g < s && g < b && (g + s + b) <= n / 2) {
      for (auto c : mp) {
        if (g + s + b + c.second <= n / 2) {
          b += c.second;
        } else
          break;
      }
      cout << g << ' ' << s << ' ' << b << '\n';
    } else
      cout << 0 << ' ' << 0 << ' ' << 0 << '\n';
  }
}
