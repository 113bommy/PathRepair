#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
}
void solve() {
  int t;
  cin >> t;
  map<string, int> mp;
  vector<string> v(t);
  for (int i = 0; i < t; i++) cin >> v[i];
  reverse(v.rbegin(), v.rend());
  for (int i = 0; i < t; i++) {
    if (mp[v[i]] == 0) {
      cout << v[i] << "\n";
      mp[v[i]]++;
    }
  }
}
int main() {
  fast();
  solve();
}
