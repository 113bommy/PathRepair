#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
using gr = vector<vll>;
using wgr = vector<vpll>;
struct d_ {
  template <typename T>
  d_& operator,(const T& x) {
    cerr << ' ' << x;
    return *this;
  }
  template <typename T>
  d_& operator,(const vector<T>& x) {
    for (auto x : x) cerr << ' ' << x;
    return *this;
  }
} d_t;
ll B[500007];
void buildTable(string& patt) {
  (memset(B, 0, sizeof(B)));
  B[0] = -1;
  for (ll i(0); i < patt.size(); i++) {
    int j = B[i];
    while (j != -1 && patt[j] != patt[i]) j = B[j];
    B[i + 1] = j + 1;
  }
}
vll kmp(string& txt, string& patt, map<int, int>& occ, int start) {
  vll foundpos;
  vll res(txt.size(), -1);
  buildTable(patt);
  ll pos = 0;
  for (int i = 0; i < txt.size(); ++i) {
    while (pos != -1 && patt[pos] != txt[i]) pos = B[pos];
    ll ns = patt.size();
    pos++;
    if (pos == ns) {
      res[i] = pos;
      int t = pos;
      while (i >= start && occ.find(t) == occ.end()) {
        occ[t] = i;
        t = B[t];
      }
      pos = B[ns];
    } else {
      res[i] = pos;
      int t = pos;
      while (i >= start && occ.find(t) == occ.end()) {
        occ[t] = i;
        t = B[t];
      }
    }
  }
  return res;
}
int main() {
  ll n, m, k;
  cin >> n >> m >> k;
  string s, t;
  cin >> s >> t;
  string prefT = t.substr(0, k);
  map<int, int> prefs;
  vll temp = kmp(s, prefT, prefs, k - 1);
  for (ll i(0); i < temp.size(); i++) {
    vector<int> res(2);
    if (temp[i] == m) {
      int start = max(0LL, i - k + 1);
      cout << "Yes" << endl;
      cout << start + 1 << " " << start + k + 1 << endl;
      return 0;
    }
  }
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  string suffT = t.substr(0, k);
  map<int, int> sufs;
  temp = kmp(s, suffT, sufs, k - 1);
  reverse(temp.begin(), temp.end());
  sufs[0] = k - 1;
  prefs[0] = k - 1;
  for (int i = 0; i <= k; ++i) {
    if (prefs.find(i) != prefs.end() && sufs.find(m - i) != sufs.end()) {
      if (prefs[i] < (n - 1 - sufs[m - i])) {
        cout << "Yes" << endl;
        cout << prefs[i] - k + 2 << " " << (n - 1 - sufs[m - i]) + 1 << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
