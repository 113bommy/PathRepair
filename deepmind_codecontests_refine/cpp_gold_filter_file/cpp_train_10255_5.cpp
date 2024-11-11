#include <bits/stdc++.h>
using namespace std;
bool chmin(int& a, int b) { return b < a ? a = b, true : false; }
bool chmax(int& a, int b) { return b > a ? a = b, true : false; }
bool chmin(long long& a, long long b) { return b < a ? a = b, true : false; }
bool chmax(long long& a, long long b) { return b > a ? a = b, true : false; }
const int inf = 1e09 + 5e3;
const long long linf = 2e18 + 5e3;
const int mod = 1e9 + 7;
const int mxn = 2e4 + 30;
int p[mxn], s[mxn], lp[mxn], ls[mxn];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  vector<pair<int, int> > out;
  long long oval = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i], p[i]--;
    lp[p[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> s[i], s[i]--;
    ls[s[i]] = i;
  }
  int change = 1;
  while (change) {
    change = 0;
    set<pair<int, int> > se;
    set<int> sew;
    for (int i = 0; i < n; i++) {
      if (s[i] == p[i]) continue;
      if (ls[p[i]] > i) {
        se.insert({ls[p[i]], i});
        sew.insert(i);
      } else {
        while (se.size() && se.begin()->first < i) {
          sew.erase(se.begin()->second);
          se.erase(se.begin());
        }
        auto it = sew.lower_bound(ls[p[i]]);
        if (it == sew.end()) continue;
        se.erase({ls[p[*it]], *it});
        change = 1;
        out.push_back({*it, i});
        oval += abs(i - *it);
        lp[p[i]] = *it;
        lp[p[*it]] = i;
        swap(p[*it], p[i]);
        sew.erase(it);
      }
    }
  }
  cout << oval << '\n' << out.size() << '\n';
  for (auto blah : out)
    cout << blah.first + 1 << ' ' << blah.second + 1 << '\n';
}
