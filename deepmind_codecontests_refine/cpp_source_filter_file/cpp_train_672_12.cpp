#include <bits/stdc++.h>
using namespace std;
const int LIM = 500000;
vector<int> ps[LIM + 10];
vector<pair<int, int>> ps_comb[LIM + 10];
void init() {
  for (int p = 2; p <= LIM; p++)
    if (ps[p].empty()) {
      for (int kp = p; kp <= LIM; kp += p) {
        ps[kp].push_back(p);
      }
    }
  for (int n = 2; n <= LIM; n++) {
    int sz = ps[n].size();
    for (int mask = 1; mask < 1 << sz; mask++) {
      int t = 1;
      int k = -1;
      for (int i = 0; i < sz; i++)
        if ((mask >> i) & 1) {
          t *= ps[n][i];
          k = -k;
        }
      ps_comb[n].push_back(make_pair(t, k));
    }
  }
}
int cnt[LIM + 10];
int calc_insect(int n) {
  int res = 0;
  for (auto c : ps_comb[n]) {
    res += cnt[c.first] * c.second;
  }
  return res;
}
void put(int n) {
  for (auto c : ps_comb[n]) {
    ++cnt[c.first];
  }
}
void del(int n) {
  for (auto c : ps_comb[n]) {
    --cnt[c.first];
  }
}
int main() {
  init();
  int n, q;
  cin >> n >> q;
  vector<bool> now(n, false);
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int res = 0;
  int tot = 0;
  for (int t = 0; t < q; t++) {
    int x;
    cin >> x;
    --x;
    if (now[x] == false) {
      res += tot - calc_insect(a[x]);
      put(a[x]);
      now[x] = true;
      ++tot;
    } else {
      del(a[x]);
      now[x] = false;
      --tot;
      res -= tot - calc_insect(a[x]);
    }
    cout << res << endl;
  }
  return 0;
}
