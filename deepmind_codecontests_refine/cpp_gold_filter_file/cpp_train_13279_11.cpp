#include <bits/stdc++.h>
using namespace std;
long long n, a[10], c[10], ans[100005];
pair<long long, long long> b[100005];
string s;
map<string, long long> m;
map<long long, string> M;
vector<long long> v;
vector<pair<pair<long long, long long>, long long> > w;
pair<long long, long long> fun(string s) {
  for (__typeof(((long long)s.size())) i = (0); i < ((long long)s.size());
       i++) {
    if (s[i] == ',') return {m[s.substr(0, i)], m[s.substr(i + 1)]};
  }
  return {m[s], -1};
}
string fun2(long long x) { return M[x]; }
void solve() {
  for (__typeof((7)) i = (1); i < (7); i++) cin >> a[i], c[i] = a[i] == 0;
  cin >> n;
  for (__typeof((n + 1)) i = (1); i < (n + 1); i++) {
    cin >> s;
    b[i] = fun(s);
    if (b[i].second == -1) {
      a[b[i].first]--;
      ans[i] = 1;
      if (a[b[i].first] < 0) {
        cout << "NO"
             << "\n";
        return;
      };
      if (a[b[i].first] == 0) c[b[i].first] = 1;
    } else
      v.push_back(i);
  }
  for (auto i : v) {
    if (c[b[i].first] && c[b[i].second]) {
      cout << "NO"
           << "\n";
      return;
    };
    if (c[b[i].first]) {
      a[b[i].second]--;
      ans[i] = 2;
      if (a[b[i].second] == 0) c[b[i].second] = 1;
      continue;
    }
    if (c[b[i].second]) {
      a[b[i].first]--;
      ans[i] = 1;
      if (a[b[i].first] == 0) c[b[i].first] = 1;
      continue;
    }
    w.push_back({{b[i].first, b[i].second}, i});
  }
  sort((w).begin(), (w).end());
  for (auto i : w) {
    if (!c[i.first.first]) {
      a[i.first.first]--;
      if (a[i.first.first] == 0) c[i.first.first] = 1;
      ans[i.second] = 1;
    } else if (!c[i.first.second]) {
      a[i.first.second]--;
      if (a[i.first.second] == 0) c[i.first.second] = 1;
      ans[i.second] = 2;
    } else {
      cout << "NO"
           << "\n";
      return;
    };
  }
  cout << "YES"
       << "\n";
  for (__typeof((n + 1)) i = (1); i < (n + 1); i++) {
    if (ans[i] == 1)
      cout << fun2(b[i].first) << "\n";
    else
      cout << fun2(b[i].second) << "\n";
  }
}
void prep() {
  m["S"] = 1, m["M"] = 2, m["L"] = 3;
  m["XL"] = 4, m["XXL"] = 5, m["XXXL"] = 6;
  for (auto i : m) M[i.second] = i.first;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  prep();
  cout << fixed << setprecision(12);
  while (t--) solve();
  return 0;
}
