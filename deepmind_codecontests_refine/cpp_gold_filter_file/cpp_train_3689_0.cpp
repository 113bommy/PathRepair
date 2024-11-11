#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vpll = vector<pll>;
struct dbg_ {
  template <typename T>
  dbg_& operator,(const T& x) {
    cerr << x << ' ';
    return *this;
  }
} dbg_t;
string s;
int pos = 0, cnt = 1;
map<string, int> vars;
vll ng[1030];
int val[1030];
int deg[1030];
void addEdge(ll a, ll b) {
  ng[a].push_back(b);
  deg[b]++;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin >> s;
  ll end = s.find(":-");
  vll retvars;
  string a = "";
  for (ll i(0); i < end; i++) {
    if (isalnum(s[i]) || s[i] == '_') {
      a += s[i];
    } else {
      if (a.size()) {
        if (!vars[a]) vars[a] = cnt++;
        retvars.push_back(vars[a]);
      }
      a = "";
    }
  }
  a = "";
  char op = 0;
  string prev;
  for (ll i(end + 2); i < s.size(); i++) {
    if (isalnum(s[i]) || s[i] == '_') {
      a += s[i];
    } else {
      if (s[i] == ',' || s[i] == '.') {
        if (op == '<')
          addEdge(vars[prev], vars[a]);
        else
          addEdge(vars[a], vars[prev]);
      } else {
        assert(s[i] == '<' || s[i] == '>');
        op = s[i];
      }
      prev = a;
      a = "";
    }
  }
  queue<ll> q;
  for (ll i(1); i < cnt; i++)
    if (!deg[i]) q.push(i);
  while (q.size()) {
    ll a = q.front();
    q.pop();
    for (auto i : ng[a]) {
      deg[i]--;
      if (deg[i] == 0) {
        q.push(i);
      }
      val[i] = val[a] + 1;
    }
  }
  bool ok = 1;
  for (ll i(1); i < cnt; i++) ok &= deg[i] == 0;
  for (ll i(1); i < cnt; i++) ok &= val[i] < 10;
  if (!ok)
    cout << "false" << endl;
  else {
    for (auto i : retvars) cout << val[i];
    cout << endl;
  }
  return 0;
}
