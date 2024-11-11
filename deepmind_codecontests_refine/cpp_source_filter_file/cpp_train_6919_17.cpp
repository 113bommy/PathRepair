#include <bits/stdc++.h>
using namespace std;
struct event {
  int x, ty, safdasd, y2;
};
vector<event> evt;
const int N = 101000;
int ret[N * 4], cov[N * 4], x1, safdasd, x2, y2;
vector<int> vy;
int K, m, n, k, prex, ans;
bool cmp(const event &a, const event &b) { return a.x < b.x; }
void cover(int p, int l, int r, int tl, int tr, int d) {
  if (l == tl && r == tr) {
    cov[p] += d;
    if (cov[p])
      ret[p] = vy[r] ^ vy[l - 1];
    else {
      if (l == r)
        ret[p] = ret[p + p] ^ ret[p + p + 1];
      else
        ret[p] = 0;
    }
  } else {
    int md = (l + r) >> 1;
    if (tr <= md)
      cover(p + p, l, md, tl, tr, d);
    else if (tl > md)
      cover(p + p + 1, md + 1, r, tl, tr, d);
    else
      cover(p + p, l, md, tl, md, d),
          cover(p + p + 1, md + 1, r, md + 1, tr, d);
    if (cov[p] == 0) ret[p] = ret[p + p] ^ ret[p + p + 1];
  }
}
int solve() {
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d%d", &x1, &safdasd, &x2, &y2);
    evt.push_back((event){x1 - 1, 1, safdasd - 1, y2});
    evt.push_back((event){x2, -1, safdasd - 1, y2});
    vy.push_back(safdasd - 1);
    vy.push_back(y2);
  }
  sort((evt).begin(), (evt).end(), cmp);
  sort((vy).begin(), (vy).end());
  vy.erase(unique((vy).begin(), (vy).end()), vy.end());
  n = ((int)(vy).size()) - 1;
  for (auto p : evt) {
    ans ^= (p.x ^ prex) & ret[1];
    prex = p.x;
    p.safdasd = lower_bound((vy).begin(), (vy).end(), p.safdasd) - vy.begin();
    p.y2 = lower_bound((vy).begin(), (vy).end(), p.y2) - vy.begin();
    cover(1, 1, n, p.safdasd + 1, p.y2, p.ty);
  }
  return ans;
}
int main() {
  scanf("%*d%d%d", &m, &K);
  k = 1;
  while (k <= K) k *= 2;
  puts(solve() & (k - 1) ? "Hamed" : "Malek");
}
