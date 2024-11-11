#include <bits/stdc++.h>
using namespace std;
map<string, int> mp, win;
int main() {
  int n, p;
  scanf("%d", &n);
  string s, winner;
  vector<pair<string, int>> v;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> s;
    scanf("%d", &p);
    mp[s] += p;
    v.push_back({s, p});
  }
  for (auto it = mp.begin(); it != mp.end(); it++) mx = max(mx, it->second);
  for (int i = 0; i < n; i++) {
    pair<string, int> pi;
    pi = v[i];
    win[pi.first] += pi.second;
    if (win[pi.first] <= mx && mp[pi.first] == mx) {
      winner = pi.first;
      break;
    }
  }
  cout << winner << "\n";
}
