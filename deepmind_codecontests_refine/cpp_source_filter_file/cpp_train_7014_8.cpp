#include <bits/stdc++.h>
using namespace std;
const int INF = 2E9 + 7;
template <class C>
void mini(C& a4, C b4) {
  a4 = min(a4, b4);
}
template <class C>
void maxi(C& a4, C b4) {
  a4 = max(a4, b4);
}
struct Tree {
  int dp[2 * (1 << 18) + 7], best[(1 << 18) + 7];
  Tree() {
    for (int i = 0; i < (2 * (1 << 18) + 7); ++i) dp[i] = INF;
  }
  void ust(int l, int r, int v, int x = 1, int ll = 1, int rr = (1 << 18)) {
    if (r < l || r < ll || rr < l) return;
    if (l <= ll && rr <= r)
      mini(dp[x], v);
    else {
      ust(l, r, v, 2 * x, ll, (ll + rr) / 2);
      ust(l, r, v, 2 * x + 1, (ll + rr + 1) / 2, rr);
    }
  }
  void prop(int l = 1, int r = (1 << 18), int v = INF, int x = 1) {
    mini(v, dp[x]);
    if (l == r)
      best[l] = v;
    else {
      prop(l, (l + r) / 2, v, 2 * x);
      prop((l + r + 1) / 2, r, v, 2 * x + 1);
    }
  }
};
Tree tree;
int n, m, l[(1 << 18)], r[(1 << 18)], t[(1 << 18)], q[(1 << 18)],
    ans[(1 << 18)];
vector<int> wsp;
long long sum = 0, kor = 0;
struct E {
  int co;
  int kto;
  int kiedy;
  E(int co_, int kto_, int kiedy_) {
    co = co_;
    kto = kto_;
    kiedy = kiedy_;
  }
  bool operator<(const E& e) const { return kiedy < e.kiedy; }
};
vector<E> events;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = (1); i <= (n); ++i) cin >> l[i] >> r[i] >> t[i];
  for (int i = (1); i <= (m); ++i) cin >> q[i];
  wsp.push_back(-1);
  for (int i = (1); i <= (n); ++i) wsp.push_back(l[i]), wsp.push_back(r[i]);
  sort((wsp).begin(), (wsp).end());
  wsp.erase(unique((wsp).begin(), (wsp).end()), wsp.end());
  for (int i = (1); i <= (n); ++i) {
    l[i] = lower_bound((wsp).begin(), (wsp).end(), l[i]) - wsp.begin();
    r[i] = lower_bound((wsp).begin(), (wsp).end(), r[i]) - wsp.begin();
  }
  for (int i = (1); i <= (n); ++i) {
    tree.ust(l[i], r[i] - 1, t[i]);
  }
  tree.prop();
  for (int i = (1); i <= ((1 << 18)); ++i)
    if (tree.best[i] < INF) {
      events.push_back(E(1, i, tree.best[i] - wsp[i + 1]));
      events.push_back(E(2, i, tree.best[i] - wsp[i]));
    }
  for (int i = (1); i <= (m); ++i) events.push_back(E(3, i, q[i]));
  sort((events).begin(), (events).end());
  for (__typeof((events).begin()) e = ((events).begin()); e != (events).end();
       ++e) {
    if (e->co == 1) {
      kor++;
      sum -= e->kiedy;
    } else if (e->co == 2) {
      kor--;
      sum += e->kiedy;
    } else if (e->co == 3) {
      ans[e->kto] = sum + e->kiedy * kor;
    }
  }
  for (int i = (1); i <= (m); ++i) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
