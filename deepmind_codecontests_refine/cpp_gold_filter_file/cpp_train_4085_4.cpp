#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
pair<long long, long long> ginkl[maxn];
pair<long long, long long> sarv[maxn];
pair<long long, pair<long long, long long> > monst[maxn];
struct node {
  long long nuo, iki;
  long long laz, mak;
  node *left, *right;
  void upd(long long a, long long c) {
    push();
    if (a < ginkl[nuo].first)
      laz += c;
    else if (a < ginkl[iki].first) {
      if (left) {
        left->upd(a, c);
        right->upd(a, c);
      }
    }
    push();
    if (left) mak = max(mak, max(left->mak, right->mak));
  }
  void push() {
    if (left) {
      left->laz += laz;
      right->laz += laz;
    }
    mak += laz;
    laz = 0;
  }
  node(long long a, long long b) {
    nuo = a;
    iki = b;
    left = 0;
    right = 0;
    laz = 0;
    mak = -ginkl[a].second;
    if (a != b) {
      left = new node(a, (a + b) / 2);
      right = new node((a + b) / 2 + 1, b);
      mak = max(left->mak, right->mak);
    }
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, p;
  cin >> n >> m >> p;
  for (int i = 0; i < n; ++i) {
    long long a, ca;
    cin >> a >> ca;
    ginkl[i] = {a, ca};
  }
  for (int i = 0; i < m; ++i) {
    long long b, cb;
    cin >> b >> cb;
    sarv[i] = {b, cb};
  }
  for (int i = 0; i < p; ++i) {
    long long x, y, z;
    cin >> x >> y >> z;
    monst[i] = {x, {y, z}};
  }
  sort(ginkl, ginkl + n);
  node medis(0, n - 1);
  sort(sarv, sarv + m);
  sort(monst, monst + p,
       [](pair<long long, pair<long long, long long> > a,
          pair<long long, pair<long long, long long> > b) -> bool {
         return a.second.first < b.second.first;
       });
  int sarvC = 0;
  int monstC = 0;
  long long ans = -1e10;
  while (sarvC < m) {
    while (monstC < p) {
      if (monst[monstC].second.first >= sarv[sarvC].first) break;
      medis.upd(monst[monstC].first, monst[monstC].second.second);
      ++monstC;
    }
    ans = max(ans, medis.mak - sarv[sarvC].second);
    ++sarvC;
  }
  cout << ans;
  return 0;
}
