#include <bits/stdc++.h>
using namespace std;
const int N = 1e9;
int pl, pr, vl, vr;
int k;
vector<int> v;
long long cnt;
int get(int msk, int x) {
  int res = 0;
  for (int i = x - 1; i >= 0; --i) {
    if (msk >> i & 1)
      res = res * 10 + 7;
    else
      res = res * 10 + 4;
  }
  return res;
}
pair<int, int> intersect(int x, int y, int a, int b) {
  int p = max(x, a);
  int q = min(y, b);
  return make_pair(p, q);
}
long long cnttimes(int ll, int lr, int rl, int rr) {
  long long res = 0;
  int x = max(ll, pl);
  int y = min(lr, pr);
  int b = max(rl, vl);
  int e = min(rr, vr);
  if (y >= x && e >= b) res += 1ll * (y - x + 1) * (e - b + 1);
  int nb = max(ll, vl);
  int ne = min(lr, vr);
  int nx = max(rl, pl);
  int ny = min(rr, pr);
  pair<int, int> t1 = intersect(x, y, nx, ny);
  pair<int, int> t2 = intersect(b, e, nb, ne);
  if (ny >= nx && ne >= nb) {
    res += 1ll * (ny - nx + 1) * (ne - nb + 1);
    if (t1.second >= t1.first && t2.second >= t2.first)
      res -= 1ll * (t1.second - t1.first + 1) * (t2.second - t2.first + 1);
  }
  return res;
}
int main() {
  scanf("%d%d%d%d%d", &pl, &pr, &vl, &vr, &k);
  for (int j = 1; j <= 9; ++j) {
    for (int i = 0; i < (1 << j); ++i) {
      v.push_back(get(i, j));
    }
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); ++i) {
    if (i + k > v.size()) break;
    int ll = i ? v[i - 1] + 1 : 0;
    int lr = v[i];
    int rl = v[i + k - 1];
    int rr = (i + k == v.size()) ? N : v[i + k] - 1;
    cnt += cnttimes(ll, lr, rl, rr);
  }
  printf("%.12f\n", 1.0 * cnt / (pr - pl + 1) / (vr - vl + 1));
  return 0;
}
