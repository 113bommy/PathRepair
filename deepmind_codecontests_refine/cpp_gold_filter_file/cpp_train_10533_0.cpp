#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long INF = 1e18;
const long long MAX = 100001;
void solve() {
  long long n;
  cin >> n;
  vector<long long> fst(n + 1), snd(n + 1);
  vector<pair<long long, long long> > vec(n + 1);
  for (int i = 1; i < (n + 1); i++) cin >> fst[i];
  for (int i = 1; i < (n + 1); i++) cin >> snd[i];
  for (int i = 1; i < (n + 1); i++) vec[i] = make_pair(fst[i], snd[i]);
  vec[0] = {-1, 0};
  sort(vec.begin(), vec.end());
  vec.push_back({-1, 0});
  vector<pair<long long, long long> > temp;
  set<long long> s;
  long long ans = 0;
  for (int i = 1; i < (n + 1); i++) {
    if (vec[i].first == vec[i + 1].first) {
      ans += vec[i].second;
      s.insert(vec[i].first);
    } else if (vec[i].first == vec[i - 1].first)
      ans += vec[i].second;
    else
      temp.push_back(vec[i]);
  }
  for (pair<long long, long long> p : temp) {
    for (long long k : s)
      if ((p.first & k) == p.first) {
        ans += p.second;
        break;
      }
  }
  cout << ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
