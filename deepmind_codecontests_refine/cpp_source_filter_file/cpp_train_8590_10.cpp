#include <bits/stdc++.h>
using namespace std;
vector<long long int> v, v1, v2, v3, v4;
vector<pair<long long int, pair<long long int, long long int> > > vec1, vec2;
vector<pair<long long int, long long int> > vec, Vec;
vector<pair<int, string> > adj[100005];
map<long long int, long long int> Mp, Mp1, Mp2;
set<string> st, st1, st2;
queue<long long int> Q;
stack<long long int> Stk;
multiset<long long int> S;
vector<string> vs;
long long int n, m, k;
string s;
void Reset() {}
void Input() {
  cin >> n >> m >> k;
  if (m > 2 * k) {
    cout << -1 << endl;
    exit(0);
  }
  if (n > 2 && k == 1) {
    cout << -1 << endl;
    exit(0);
  }
}
void Calculation() {
  for (int i = 1; i <= k; i++) vec.push_back({i, i + 1});
  if (m == k) {
    for (int i = k + 2; i <= n; i++) vec.push_back({2, i});
  } else {
    vec.push_back({1, k + 2});
    for (int i = k + 2; i <= m; i++) vec.push_back({i, i + 1});
    for (int i = m + 2; i <= n; i++) vec.push_back({1, i});
  }
  for (auto x : vec) {
    cout << x.first << " " << x.second << endl;
    if (x.first == n || x.second == n) break;
  }
}
void solve() {
  Reset();
  Input();
  Calculation();
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) solve();
  return 0;
}
