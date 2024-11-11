#include <bits/stdc++.h>
const int inf = 1e9;
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  string s;
  cin >> n >> k >> s;
  map<char, int> mp;
  int mx = 0;
  for (auto i : s) {
    mx = max(mx, mp[i]++);
  }
  cout << (mx <= k ? "YES\n" : "NO\n");
  return 0;
}
