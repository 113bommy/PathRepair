#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;
const int N = 2e5 + 30;
struct SuffixArray {
  vector<int> sa, lcp;
  SuffixArray(const vector<int> &xx, int lim = 100030) {
    int n = ((int)(xx).size()) + 1, k = 0, a, b;
    vector<int> x((xx).begin(), (xx).end() + 1), y(n), ws(max(n, lim)), rank(n);
    x.back() = 0;
    sa = lcp = y, iota((sa).begin(), (sa).end(), 0);
    for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
      p = j, iota((y).begin(), (y).end(), n - j);
      for (int i = (0); i < (n); ++i)
        if (sa[i] >= j) y[p++] = sa[i] - j;
      fill((ws).begin(), (ws).end(), 0);
      for (int i = (0); i < (n); ++i) ws[x[i]]++;
      for (int i = (1); i < (lim); ++i) ws[i] += ws[i - 1];
      for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
      swap(x, y), p = 1, x[sa[0]] = 0;
      for (int i = (1); i < (n); ++i)
        a = sa[i - 1], b = sa[i],
        x[b] = (y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
    }
    for (int i = (1); i < (n); ++i) rank[sa[i]] = i;
    for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
      for (k &&k--, j = sa[rank[i] - 1]; xx[i + k] == xx[j + k]; k++)
        ;
  }
};
int n, K, L[N], id[N], cnt[N], D[N], top, near[N], lz[N << 2];
ll ans[N];
void dolz(int id, int l, int r) {
  if (l == r || !lz[id]) return;
  if (l != r)
    lz[id << 1] = max(lz[id << 1], lz[id]),
             lz[(id << 1) | 1] = max(lz[(id << 1) | 1], lz[id]);
  lz[id] = 0;
}
void update(int id, int l, int r, int L, int R, int v) {
  dolz(id, l, r);
  if (l > R || r < L) return;
  if (L <= l && r <= R) {
    lz[id] = max(lz[id], v);
    dolz(id, l, r);
    return;
  }
  int m = (l + r) >> 1;
  update(id << 1, l, m, L, R, v);
  update((id << 1) | 1, m + 1, r, L, R, v);
}
void cal(int id, int l, int r) {
  dolz(id, l, r);
  if (l == r) {
    cnt[l] = lz[id];
    return;
  }
  int m = (l + r) >> 1;
  cal(id << 1, l, m);
  cal((id << 1) | 1, m + 1, r);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> K;
  vector<int> tem;
  int nn = 26;
  string t;
  for (int i = (1); i <= (n); ++i) {
    string s;
    cin >> s;
    for (int j = (0); j < (((int)(s).size())); ++j) {
      id[((int)(tem).size())] = i;
      tem.emplace_back((s[j] - 'a') + 1);
    }
    if (i < n) tem.emplace_back(nn + 1), nn++;
    if (K == 1) ans[i] = ((int)(s).size()) * 1LL * (((int)(s).size()) + 1) / 2;
    t += s + '#';
  }
  if (K == 1) {
    for (int i = (1); i <= (n); ++i) cout << ans[i] << ' ';
    return 0;
  }
  SuffixArray SA(tem);
  nn = ((int)(tem).size());
  int l = 1, numd = 0;
  for (int i = (1); i <= (nn); ++i)
    if (id[SA.sa[i]]) {
      if (++cnt[id[SA.sa[i]]] == 1) numd++;
      while (l < i && (!id[SA.sa[l]] || numd > K ||
                       (numd == K && id[SA.sa[l]] && cnt[id[SA.sa[l]]] > 1))) {
        if (id[SA.sa[l]] && --cnt[id[SA.sa[l]]] == 0) numd--;
        l++;
      }
      if (numd == K) near[i] = l;
    }
  D[0] = 0;
  for (int i = (1); i <= (nn); ++i) {
    while (top && SA.lcp[D[top]] >= SA.lcp[i]) top--;
    L[i] = D[top] + 1;
    D[++top] = i;
  }
  D[0] = nn + 1;
  top = 0;
  for (int i = (nn); i >= (1); --i) {
    while (top && SA.lcp[D[top]] >= SA.lcp[i]) top--;
    int r = D[top] - 1;
    if (near[r] >= L[i] - 1) update(1, 1, nn, max(1, L[i] - 1), r, SA.lcp[i]);
    D[++top] = i;
  }
  cal(1, 1, nn);
  for (int i = (1); i <= (nn); ++i) ans[id[SA.sa[i]]] += cnt[i];
  for (int i = (1); i <= (n); ++i) cout << ans[i] << ' ';
  return 0;
}
