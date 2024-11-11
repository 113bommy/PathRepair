#include <bits/stdc++.h>
using namespace std;
int const N = 1e6 + 10, oo = 1e9, M = 5e6 + 10;
long long const OO = 1e18;
int mod = oo + 7;
double const eps = 5e-6;
int n, m, where[N];
set<pair<int, int> > st;
set<int> occ;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, id;
    cin >> a >> id;
    if (a == 1) {
      int an = -1;
      if (occ.empty()) {
        an = 1;
      } else {
        int p = *occ.begin(), ep = *(--occ.end());
        int tr1 = p - 1, tr2 = n - ep;
        int tp = -oo, ins = -1;
        if (st.size()) {
          auto v = st.begin();
          tp = -v->first;
          ins = v->second;
          if ((tp > tr1 && tp >= tr2)) {
            an = ins;
            st.erase(st.begin());
            auto nxt = occ.lower_bound(ins);
            auto prev = nxt;
            prev--;
            int d = (ins - *nxt) / 2;
            int mid = (ins + *nxt) / 2;
            if (d) st.insert({d, mid});
            d = (*prev - ins) / 2;
            mid = (ins + *prev) / 2;
            if (d) st.insert({d, mid});
          }
        }
        if (an == -1) {
          if (tr1 >= tr2) {
            an = 1;
            st.insert({-tr1 / 2, (1 + p) / 2});
          } else {
            an = n;
            st.insert({-tr2 / 2, (n + ep) / 2});
          }
        }
      }
      where[id] = an;
      occ.insert(an);
      cout << an << '\n';
    } else {
      int at = where[id];
      occ.erase(at);
      if (occ.empty()) continue;
      if ((int)occ.size() == 1)
        st.clear();
      else {
        auto nxt = occ.lower_bound(at);
        if (nxt == occ.begin()) {
          int d = (at - *nxt) / 2;
          int mid = (at + *nxt) / 2;
          st.erase({d, mid});
        } else if (nxt == occ.end()) {
          nxt--;
          int d = (*nxt - at) / 2;
          int mid = (at + *nxt) / 2;
          st.erase({d, mid});
        } else {
          auto prev = nxt;
          prev--;
          int d = (at - *nxt) / 2;
          int mid = (at + *nxt) / 2;
          st.erase({d, mid});
          d = (*prev - at) / 2;
          mid = (at + *prev) / 2;
          st.erase({d, mid});
          d = (*prev - *nxt) / 2;
          mid = (*prev + *nxt) / 2;
          st.insert({d, mid});
        }
      }
    }
  }
  return 0;
}
