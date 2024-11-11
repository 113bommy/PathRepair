#include <bits/stdc++.h>
using namespace std;
unordered_map<long long, long long> mp;
int main() {
  long long n, p, k;
  cin >> n >> p >> k;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    mp[(((x * x % p) * (x * x % p) - k * x % p) % p + p) % p]++;
  }
  long long ans = 0;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    ans += (it->second - 1ll) * (it->second) / 2;
  }
  cout << ans << endl;
}
