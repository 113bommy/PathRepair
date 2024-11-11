#include <bits/stdc++.h>
using namespace std;
int lg(long long n) {
  assert(n > 0);
  int ans = -1;
  while (n) {
    ans++;
    n >>= 1;
  }
  return ans;
}
void solve() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (auto &a : A) cin >> a;
  auto cmp1 = [&](const pair<int, int> &a, const pair<int, int> &b) {
    int lena = a.second - a.first + 1, lenb = b.second - b.first + 1;
    return lena > lenb || (lena == lenb && a.first < b.first);
  };
  auto s1 = set<pair<int, int>, decltype(cmp1)>(cmp1);
  set<pair<int, int> > s2;
  for (int l = 0; l < N;) {
    int r = l;
    while (r < N && A[l] == A[r]) r++;
    s1.insert(make_pair(l, r - 1));
    s2.insert(make_pair(l, r - 1));
    l = r;
  }
  int ans = 0;
  while (!s1.empty()) {
    ans++;
    auto rmv = *s1.begin();
    auto it = s2.find(rmv);
    if (next(it) != s2.end() && it != s2.begin()) {
      auto prv = prev(it), nxt = next(it);
      if (A[prv->first] == A[nxt->first]) {
        int len = prv->second - prv->first + nxt->second - nxt->first + 2;
        auto seg = make_pair(prv->first, prv->first + len - 1);
        s1.erase(*prv), s1.erase(*nxt);
        s2.erase(prv), s2.erase(nxt);
        s1.insert(seg), s2.insert(seg);
      }
    }
    s1.erase(rmv);
    s2.erase(rmv);
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
