#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> &p, pair<int, int> &p2) { return p.second < p2.second; }
void solve() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  };
  string s;
  cin >> s;
  vector<pair<int, int>> like, dis;
  int ct = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '1') {
      like.push_back({a[i], i});
      ct++;
    } else {
      dis.push_back({a[i], i});
    }
  }
  if (dis.size() == 0) {
    for (long long i = 1; i < n + 1; i++) {
      cout << i << " ";
    }
    cout << "\n";
    return;
  }
  sort(like.begin(), like.end());
  sort(dis.begin(), dis.end());
  vector<int> ansvec(n);
  for (long long i = 0; i < like.size(); i++) {
    ansvec[like[i].second] = n - ct + 1;
    ct--;
  }
  ct = 1;
  for (long long i = 0; i < dis.size(); i++) {
    ansvec[dis[i].second] = ct;
    ct++;
  }
  for (auto i : ansvec) {
    cout << i << " ";
  }
  cout << "\n";
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
