#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  ll mx = -1, mn = 1e9;
  map<char, ll> mp;
  for (char i : s) {
    mp[i]++;
  }
  for (auto i : mp) {
    mx = max(mx, i.second);
    mn = min(mn, i.second);
  }
  if (mp.size() < k or k > n) return cout << 0, 0;
  return cout << ((ll)mp.size() * mn), 0;
}
