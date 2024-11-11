#include <bits/stdc++.h>
using namespace std;
int n, m;
struct wall {
  int w, t, s;
  wall(int _w, int _t, int _s) : w(_w), t(_t), s(_s) {}
  bool operator<(const wall &T) const { return (w < T.w); }
};
vector<wall> V, T;
multiset<int> S;
int main() {
  std::ios::sync_with_stdio(false);
  while (cin >> n >> m) {
    V.clear();
    T.clear();
    for (int i = 0; i < m; i++) {
      int l, r, t;
      cin >> l >> r >> t;
      V.push_back(wall(l, t, 1));
      V.push_back(wall(r, t, 0));
    }
    sort(V.begin(), V.end());
    int last = -1;
    S.clear();
    long long ans = 0;
    int p = V.size();
    for (int i = 0; i < p; i++) {
      int w = V[i].w;
      if (last >= 0 && w > last && !S.empty()) {
        int t = *S.begin();
        T.push_back(wall(t - last, t, 1));
        T.push_back(wall(t - w, t, -1));
      }
      last = w;
      if (V[i].s == 1)
        S.insert(V[i].t);
      else
        S.erase(S.find(V[i].t));
    }
    sort(T.begin(), T.end());
    int c = T.size(), j = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
      int t;
      cin >> t;
      for (; T[j].w < t && j < c; j++) {
        if (T[j].s > 0) {
          ans += T[j].w;
          cnt--;
        } else {
          ans -= T[j].w;
          cnt++;
        }
      }
      cout << ans + (cnt) * (long long)(t) << endl;
    }
  }
  return 0;
}
