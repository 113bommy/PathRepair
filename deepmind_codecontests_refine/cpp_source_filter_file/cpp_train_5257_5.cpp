#include <bits/stdc++.h>
using namespace std;
set<int> st[26];
set<int> ed[26];
int calcs[30];
int g(char a) { return a - 'a'; }
int calc(int qi, int qj, int g) {
  int ret = 0;
  while (true) {
    auto e = ed[g].lower_bound(qi);
    if (e == ed[g].end()) break;
    auto s = st[g].upper_bound(*e);
    s--;
    int sv = *s, ev = *e;
    if (sv > qj) break;
    ret += min(qj, ev) - max(qi, sv) + 1;
    st[g].erase(s);
    ed[g].erase(e);
    if (qi > *s) {
      st[g].insert(sv);
      ed[g].insert(qi - 1);
    }
    if (qj < *e) {
      ed[g].insert(ev);
      st[g].insert(qj + 1);
    }
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  string S;
  cin >> S;
  for (int i = 0; i < (int)S.length(); i++) {
    if (i == 0 || S[i] != S[i - 1]) {
      st[g(S[i])].insert(i + 1);
    }
    if (i == (int)S.length() - 1 || S[i] != S[i + 1]) {
      ed[g(S[i])].insert(i + 1);
    }
  }
  for (int i = 0; i < q; i++) {
    int qi, qj, qk;
    cin >> qi >> qj >> qk;
    if (qk > 0) {
      for (int j = g('a'); j <= g('z'); j++) {
        calcs[j] = calc(qi, qj, j);
      }
      for (int j = g('a'); j <= g('z'); j++) {
        if (calcs[j] > 0) {
          st[j].insert(qi);
          ed[j].insert(qi + calcs[j] - 1);
        }
        qi += calcs[j];
      }
    } else {
      for (int j = g('z'); j >= g('a'); j--) {
        calcs[j] = calc(qi, qj, j);
      }
      for (int j = g('z'); j >= g('a'); j--) {
        if (calcs[j] > 0) {
          st[j].insert(qi);
          ed[j].insert(qi + calcs[j] - 1);
        }
        qi += calcs[j];
      }
    }
  }
  for (int i = g('a'); i <= g('z'); i++) {
    while (!st[i].empty()) {
      auto s = st[i].begin();
      auto e = ed[i].begin();
      for (int j = *s; j <= *e; j++) {
        S[j - 1] = i + 'a';
      }
      st[i].erase(s);
      ed[i].erase(e);
    }
  }
  cout << S << endl;
  return 0;
}
