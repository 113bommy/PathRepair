#include <bits/stdc++.h>
using namespace std;
struct Q {
  int l, r, idx;
  Q(int _l = 0, int _r = 0, int _idx = 0) : l(_l), r(_r), idx(_idx) {}
};
const int BSIZE = 350;
int n, m, k;
int p[100005];
int cnt[1 << 20];
long long ans[100005];
long long res;
vector<vector<Q>> v;
bool cmp(const Q& a, const Q& b) { return a.r < b.r; }
void add(int x) {
  res += cnt[x ^ k];
  cnt[x]++;
}
void del(int x) {
  cnt[x]--;
  res -= cnt[x ^ k];
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &p[i]);
    p[i] ^= p[i - 1];
  }
  v = vector<vector<Q>>(n / BSIZE + 2);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x;
    ++y;
    v[x / BSIZE].push_back(Q(x, y, i));
  }
  for (int i = 0; i < v.size(); ++i) sort(v[i].begin(), v[i].end(), cmp);
  for (int i = 0; i < v.size(); ++i) {
    int l = i * BSIZE;
    int r = i * BSIZE;
    for (int j = 0; j < v[i].size(); ++j) {
      Q q = v[i][j];
      while (r < q.r) {
        add(p[r]);
        ++r;
      }
      while (l < q.l) {
        del(p[l]);
        ++l;
      }
      while (l > q.l) {
        --l;
        add(p[l]);
      }
      ans[q.idx] = res;
    }
    while (l < r) del(p[l++]);
  }
  for (int i = 0; i < m; ++i) cout << ans[i] << '\n';
}
