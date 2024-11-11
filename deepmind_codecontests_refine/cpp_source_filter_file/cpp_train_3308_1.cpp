#include <bits\stdc++.h>

using namespace std;

int main() {
  int N, Q;
  cin >> N;
  vector<int> V(N + 1), W(N + 1);
  for (int i = 1; i <= N; ++i) cin >> V[i] >> W[i];
  cin >> Q;
  constexpr int b = 9;
  vector<pair<int, int>> l1, l2, tmp;
  while (Q--) {
    int v, L;
    cin >> v >> L;
    l1.clear();
    l2.clear();
    auto gen = [&](vector<pair<int, int>> &l, int thr) {
      l.emplace_back(0, 0);
      while (v >= thr) {
        int p1 = 0, p2 = 0;
        while (p1 < l.size() || p2 < l.size()) {
          pair<int, int> nxt;
          if (p1 < l.size() && l[p1].first < l[p2].first + W[v])
            nxt = l[p1++];
          else
            nxt = {l[p2].first + W[v], l[p2++].second + V[v]};
          if (tmp.empty() || tmp.back().second > nxt.second) tmp.push_back(nxt);
        }
        v /= 2;
        l.swap(tmp);
        tmp.clear();
      }
    };
    gen(l1, 1 << b);
    gen(l2, 1);
    int p1 = 0, p2 = 0;
    while (p2 + 1 < l2.size() && l1[p1].first + l2[p2 + 1].first <= L) p2++;
    int ans = l1[p1].second + l2[p2].second;
    while (++p1 < l1.size() && l1[p1].first <= L) {
      while (l1[p1].first + l2[p2].first > L) p2--;
      ans = max(ans, l1[p1].second + l2[p2].second);
    }
    cout << ans << "\n";
  }
  return 0;
}
