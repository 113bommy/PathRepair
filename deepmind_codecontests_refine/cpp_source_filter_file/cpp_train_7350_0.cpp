#include <bits/stdc++.h>
using namespace std;
struct seg {
  int h, l, r, op;
  seg(int _h, int _l, int _r, int _op) : h(_h), l(_l), r(_r), op(_op) {}
  bool operator<(const seg& A) const { return h < A.h; }
};
int N, M, K, L, R, U, D, x[505], y[505], cnt[505];
vector<seg> v;
vector<int> MP;
inline int Get(int x) {
  return lower_bound((MP).begin(), (MP).end(), x) - MP.begin();
}
inline void update(int i, int j) {
  for (int k = 0; k < (MP.size() - 1); k++) {
    if (cnt[k] <= 0) {
      U = max(U, MP[k + 1] - 1);
      D = min(D, MP[k]);
      L = min(L, v[i].h);
      R = max(R, v[j].h - 1);
    }
  }
}
inline int check(int t) {
  L = 1e9 + 10, R = -1, U = -1, D = 1e9 + 10;
  memset(cnt, 0, sizeof cnt);
  v.clear();
  MP.clear();
  MP.push_back(1), MP.push_back(M + 1);
  v.push_back(seg(1, 1, 1, 1));
  v.push_back(seg(N + 1, 1, 1, 1));
  for (int i = 0; i < (K); i++) {
    int tl = max(1, y[i] - t), tr = min(y[i] + t + 1, M + 1);
    v.push_back(seg(min(x[i] + t + 1, N + 1), tl, tr, -1));
    v.push_back(seg(max(1, x[i] - t), tl, tr, 1));
    MP.push_back(max(1, y[i] - t));
    MP.push_back(min(y[i] + t + 1, M + 1));
  }
  sort((MP).begin(), (MP).end());
  sort((v).begin(), (v).end());
  MP.erase(unique((MP).begin(), (MP).end()), MP.end());
  for (int i = 0, j = 0; i < v.size(); i = j) {
    while (j < v.size() && v[i].h == v[j].h) {
      int l = Get(v[j].l), r = Get(v[j].r);
      for (int k = l; k < r; k++) cnt[k] += v[j].op;
      j++;
    }
    if (v[i].h <= N) update(i, j);
  }
  return R - L <= 2 * t && U - D <= 2 * t;
}
int main() {
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 0; i < (K); i++) scanf("%d%d", &x[i], &y[i]);
  int l = -1, r = 1e9 + 10;
  while (l + 1 < r) {
    int m = (l + r) >> 1;
    if (check(m))
      r = m;
    else
      l = m;
  }
  printf("%d\n", r);
  return 0;
}
