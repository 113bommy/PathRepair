#include <bits/stdc++.h>
using namespace std;
int n;
long long t1, w1;
vector<pair<long long, long long>> v;
multiset<long long> s;
void code() {
  cin >> n >> t1 >> w1;
  for (int i = 0; i < n - 1; i++) {
    long long t, w;
    cin >> t >> w;
    v.push_back({t, w});
  }
  sort((v).begin(), (v).end());
  reverse((v).begin(), (v).end());
  int i = 0, rem = 0, rk = INT_MAX;
  while (i < n - 1) {
    while (i < n - 1 && v[i].first > t1) {
      s.insert(v[i].second - v[i].first + 1);
      i++;
    }
    rk = min(rk, (int)s.size() + 1);
    if (s.size() > 0 && t1 >= *s.begin()) {
      t1 -= *s.begin();
      s.erase(s.begin());
    } else {
      break;
    }
  }
  rk = min(rk, (int)s.size() + 1);
  cout << rk << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    code();
  }
}
