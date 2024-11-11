#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 333;
const long long linf = 1e18 + inf;
const int LEN = 6e5 + 5;
int n, m, q, len;
char str[LEN], s[LEN];
int a[LEN], st[LEN], nd[LEN], suf[LEN], ord[LEN], lcp[LEN], w[LEN], root[LEN],
    L[LEN], R[LEN];
pair<pair<int, int>, int> C[LEN];
long long cnt[LEN];
void add(int x, char str[]) {
  int m = strlen(str);
  s[++len] = '#';
  st[x] = len + 1;
  for (int i = 0; i < m; i++) s[++len] = str[i];
  nd[x] = len;
}
int f(int x) {
  if (x == root[x]) return x;
  return root[x] = f(root[x]);
}
void merge(int x, int y) {
  x = f(x);
  y = f(y);
  if (x == y) return;
  root[y] = x;
  cnt[x] += cnt[y];
  L[x] = min(L[x], L[y]);
  R[x] = max(R[x], R[y]);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", str);
    add(i, str);
  }
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= len; i++) suf[i] = s[i];
  for (int it = 1; it < len; it *= 2) {
    for (int j = 1; j <= len; j++) {
      C[j] = make_pair(pair<int, int>(suf[j], suf[min(j + it, len + 1)]), j);
    }
    sort(C + 1, C + len + 1);
    for (int j = 1; j <= len; j++) {
      suf[C[j].second] = suf[C[j - 1].second] + (C[j].first != C[j - 1].first);
    }
  }
  for (int i = 1; i <= len; i++) ord[suf[i]] = i;
  for (int i = 1; i <= len; i++) {
  }
  int j = 0;
  for (int i = 1; i <= len; i++) {
    if (suf[i] == 1) continue;
    while (i + j <= len and ord[suf[i] - 1] + j <= len and
           s[i + j] == s[ord[suf[i] - 1] + j] and s[i + j] != '#')
      j++;
    lcp[suf[i]] = j;
    if (j) j--;
  }
  for (int i = 1; i <= len; i++) {
    assert(s[ord[i] + lcp[i]] != s[ord[i - 1] + lcp[i]] or
           s[ord[i] + lcp[i]] == '#');
  }
  for (int i = 1; i <= len; i++) {
  }
  memset(w, -1, sizeof(w));
  for (int i = 1; i <= n; i++) {
    for (int j = st[i]; j <= nd[i]; j++) {
      w[suf[j]] = i;
    }
  }
  for (int i = 1; i <= len; i++) {
    if (w[i] != -1) cnt[i] = a[w[i]];
    L[i] = R[i] = root[i] = i;
  }
  vector<pair<int, int> > vs;
  for (int i = 1; i <= len; i++) {
    vs.push_back(pair<int, int>(lcp[i], i));
  }
  sort(vs.begin(), vs.end());
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int x = suf[st[i]];
    if (nd[i] - st[i] + 1 > lcp[x] and nd[i] - st[i] + 1 > lcp[x + 1]) {
      ans = max(ans, (long long)a[i] * (nd[i] - st[i] + 1));
    }
  }
  for (int it = len - 1; it >= 0; it--) {
    int l = vs[it].first, x = vs[it].second;
    merge(x, x - 1);
    x = f(x);
    if (lcp[L[x]] < l and lcp[R[x] + 1] < l) ans = max(ans, cnt[f(x)] * l);
  }
  printf("%lld\n", ans);
  return 0;
}
