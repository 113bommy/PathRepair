#include <bits/stdc++.h>
using namespace std;
const int N = 300000;
int n, cq, m, a[N + 9];
struct question {
  int l, r, id;
  question(int L = 0, int R = 0, int Id = 0) : l(L), r(R), id(Id) {}
} q[N + 9];
void into() {
  scanf("%d%d%d", &n, &cq, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= cq; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    q[i] = question(l, r, i);
  }
}
int b[N + 9];
void Get_b() {
  static int q[N + 9];
  int hd = 0, tl = 0;
  for (int i = 1; i <= n; ++i) {
    for (; hd <= tl && a[i] <= a[q[tl]]; --tl)
      ;
    q[++tl] = i;
    for (; hd <= tl && q[hd] < i - m; ++hd)
      ;
    b[i] = a[q[hd]];
  }
}
vector<int> sta[N + 9], cnt[N + 9];
vector<long long> suf[N + 9];
long long sum[N + 9], ans[N + 9];
void Get_ans() {
  sort(q + 1, q + cq + 1,
       [&](const question &a, const question &b) { return a.l > b.l; });
  for (int i = n, j = 1; i >= 1; --i) {
    int o = i % m;
    for (; j <= cq && q[j].l == i; ++j) {
      ans[q[j].id] = a[i];
      if (sta[o].empty()) continue;
      if (q[j].r < q[j].l + m) continue;
      int p =
          lower_bound(sta[o].begin(), sta[o].end(), q[j].r, greater<int>()) -
          sta[o].begin();
      ans[q[j].id] += sum[o] - suf[o][p] +
                      1LL * ((q[j].r - sta[o][p]) / m + 1) * b[sta[o][p]];
    }
    int c = 1;
    for (; !sta[o].empty() && b[i] < b[sta[o].back()];) {
      c += cnt[o].back();
      sum[o] -= cnt[o].back() * b[sta[o].back()];
      sta[o].pop_back();
      cnt[o].pop_back();
      suf[o].pop_back();
    }
    sum[o] += 1LL * c * b[i];
    sta[o].push_back(i);
    cnt[o].push_back(c);
    suf[o].push_back((suf[o].empty() ? 0 : suf[o].back()) + 1LL * c * b[i]);
  }
}
void work() {
  Get_b();
  Get_ans();
}
void outo() {
  for (int i = 1; i <= cq; ++i) printf("%lld\n", ans[i]);
}
int main() {
  int T = 1;
  for (; T--;) {
    into();
    work();
    outo();
  }
  return 0;
}
