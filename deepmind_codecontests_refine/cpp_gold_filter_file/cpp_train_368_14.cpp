#include <bits/stdc++.h>
using namespace std;
struct compare {
  bool operator()(pair<int, int> A, pair<int, int> B) {
    if (A.first == B.first) return A.second > B.second;
    return A.first > B.first;
  }
};
set<pair<int, int>, compare> half, full;
const int mx = 200005;
int pleasure[mx], length[mx];
int main() {
  int i, n, w, k, P, T, hi, lo, t, ans;
  bool H;
  scanf("%d %d %d", &n, &w, &k);
  for (i = 0; i < n; i++) scanf("%d", &pleasure[i]);
  for (i = 0; i < n; i++) scanf("%d", &length[i]);
  P = T = hi = lo = ans = 0;
  H = true;
  while (hi < n) {
    if (H) {
      P += pleasure[hi];
      if (half.size() < w || (--half.end())->first <= length[hi]) {
        T += ceil(length[hi] / 2.0);
        half.insert(make_pair(length[hi], hi));
      } else {
        T += length[hi];
        full.insert(make_pair(length[hi], hi));
      }
      if (half.size() > w) {
        auto it = half.end();
        it--;
        T -= ceil(it->first / 2.0);
        T += it->first;
        full.insert(*it);
        half.erase(it);
      }
    }
    if (T <= k) {
      ans = max(ans, P);
      hi++;
      H = true;
    } else {
      P -= pleasure[lo];
      auto it = half.find(make_pair(length[lo], lo));
      if (it != half.end()) {
        T -= ceil(length[lo] / 2.0);
        half.erase(it);
        if (!full.empty()) {
          t = full.begin()->first;
          T -= t;
          T += ceil(t / 2.0);
          half.insert(*full.begin());
          full.erase(full.begin());
        }
      } else {
        T -= length[lo];
        auto it = full.find(make_pair(length[lo], lo));
        full.erase(it);
      }
      H = false;
      lo++;
    }
    if (lo > hi) hi = lo;
  }
  printf("%d\n", ans);
  return 0;
}
