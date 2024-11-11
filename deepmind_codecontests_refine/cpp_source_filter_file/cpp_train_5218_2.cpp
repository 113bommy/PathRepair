#include <bits/stdc++.h>
using namespace std;
struct State {
  int i = 0;
  int j = 0;
  char ch;
  int remK = 0;
};
State createState(int i, int j, char ch, int k) {
  State res;
  res.i = i;
  res.j = j;
  res.ch = ch;
  res.remK = k;
  if (res.remK > 0 && ch != 'a') {
    res.remK--;
    res.ch = 'a';
  }
  return res;
}
vector<pair<int, int>> ds = {{0, 1}, {1, 0}};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<map<pair<int, int>, State>> state(2 * n - 1);
  auto init = createState(0, 0, a[0][0], k);
  state[0][{0, 0}] = init;
  string res;
  for (int pos = 0; pos < 2 * n - 1; pos++) {
    res += state[pos].begin()->second.ch;
    for (auto stPr : state[pos]) {
      auto st = stPr.second;
      for (auto dpr : ds) {
        int nxtI = st.i + dpr.first;
        int nxtJ = st.j + dpr.second;
        if (nxtI >= n || nxtJ >= n) {
          continue;
        }
        pair<int, int> nxtPr = {nxtI, nxtJ};
        auto nxt = createState(nxtI, nxtJ, a[nxtI][nxtJ], st.remK);
        auto &mp = state[pos + 1];
        if (mp.size() == 0) {
          mp[nxtPr] = nxt;
        } else {
          char ch = mp.begin()->second.ch;
          if (nxt.ch == ch) {
            if (mp.count(nxtPr) == 0) {
              mp[nxtPr] = nxt;
            } else {
              auto upd = mp[nxtPr];
              upd.remK = min(upd.remK, nxt.remK);
            }
          } else if (nxt.ch < ch) {
            mp.clear();
            mp[nxtPr] = nxt;
          }
        }
      }
    }
  }
  cout << res << endl;
}
