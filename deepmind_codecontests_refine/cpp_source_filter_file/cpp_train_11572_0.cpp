#include <bits/stdc++.h>
using namespace std;
const long long N = 15e4 + 5, mod = 998244353;
long long n, o, e, bit;
vector<long long> v[30], z, x, a, b;
vector<pair<long long, long long>> ans;
string s, t;
bool mk[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> s >> t;
  for (long long i = 0; i < n; i++) {
    if (s[i] != '?')
      v[s[i] - 'a'].push_back(i);
    else
      z.push_back(i), mk[i] = 1;
  }
  for (long long i = 0; i < n; i++) {
    if (t[i] != '?') {
      if (v[t[i] - 'a'].size())
        ans.push_back({i, v[t[i] - 'a'].back()}),
            mk[v[t[i] - 'a'].back()] = 1, v[t[i] - 'a'].pop_back();
      else
        x.push_back(i);
    } else
      b.push_back(i);
  }
  for (long long i = 0; i < min(x.size(), z.size());) {
    ans.push_back({x.back(), z.back()});
    z.pop_back();
    x.pop_back();
  }
  for (long long i = 0; i < n; i++) {
    if (!mk[i]) a.push_back(i);
  }
  for (long long i = 0; i < min(a.size(), b.size());) {
    ans.push_back({a.back(), b.back()});
    b.pop_back();
    a.pop_back();
  }
  for (long long i = 0; i < min(z.size(), b.size());) {
    ans.push_back({z.back(), b.back()});
    b.pop_back();
    z.pop_back();
  }
  cout << ans.size() << endl;
  for (long long i = 0; i < ans.size(); i++) {
    cout << ans[i].second + 1 << " " << ans[i].first + 1 << endl;
  }
}
