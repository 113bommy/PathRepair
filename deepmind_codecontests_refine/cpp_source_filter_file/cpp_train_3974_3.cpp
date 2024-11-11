#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 5e5 + 42;
int ans[MAXN];
int pos[MAXN];
int cnt[MAXN];
int suf[MAXN];
vector<pair<int, int> > query[MAXN];
int fw[MAXN];
void upd(int p, int v) {
  for (; p < MAXN; p += p & -p) {
    fw[p] += v;
  }
}
int sum(int p) {
  int r = 0;
  for (; p > 0; p -= p & -p) {
    r += fw[p];
  }
  return r;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N, M, Q;
  cin >> N >> M >> Q;
  for (int i = 0; i < N; i++) {
    int p;
    cin >> p;
    cnt[p]++;
  }
  vector<pair<int, int> > ord;
  ord.reserve(M);
  for (int i = 1; i <= M; i++) {
    ord.emplace_back(cnt[i], i);
  }
  sort(ord.begin(), ord.end());
  for (int i = 0; i < M; i++) {
    tie(cnt[i], pos[i]) = ord[i];
  }
  for (int i = M - 1; i >= 0; i--) {
    suf[i] = suf[i + 1] + cnt[i];
  }
  for (int i = 0; i < Q; i++) {
    long long k;
    cin >> k;
    long long l = 0, r = 1e18;
    while (r - l > 1) {
      long long m = (l + r) / 2;
      int p = upper_bound(cnt, cnt + M, m) - cnt;
      if (m * p + suf[p] < k)
        l = m;
      else
        r = m;
    }
    int p = upper_bound(cnt, cnt + M, l) - cnt;
    query[p].emplace_back(k - l * p - suf[p], i);
  }
  for (int i = 0; i < M; i++) {
    upd(pos[i], 1);
    for (auto [k, x] : query[i + 1]) {
      int l = 0, r = M;
      while (r - l > 1) {
        int m = (l + r) / 2;
        if (sum(m) < k)
          l = m;
        else
          r = m;
      }
      ans[x] = r;
    }
  }
  for (int i = 0; i < Q; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
