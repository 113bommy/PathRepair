#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e6 + 5, B1 = 37, B2 = 41, M1 = 1e9 + 7, M2 = 1e9 + 21;
int n, k, m, p[MAX], sz[MAX];
char a[MAX], b[MAX], e[MAX];
struct data {
  pair<int, int> h;
  int id;
  data(pair<int, int> h, int id) : h(h), id(id) {}
  bool operator<(const data &d) const { return h < d.h; }
};
multiset<data> s;
vector<int> v[MAX];
pair<int, int> pw[MAX], inv[MAX], t[MAX];
int findst(int x) { return p[x] = (x == p[x]) ? x : findst(p[x]); }
void joinst(int a, int b) {
  a = findst(a);
  b = findst(b);
  if (a == b) return;
  if (sz[a] < sz[b]) swap(a, b);
  p[b] = a;
  sz[a] += sz[b];
}
int exp(int a, int b, int M) {
  if (b == 0) return 1;
  if (b & 1) return (a * 1LL * exp(a, b - 1, M)) % M;
  int sq = exp(a, b / 2, M);
  return (sq * 1LL * sq) % M;
}
pair<int, int> getHash(int i, int j) {
  int h1 = (0LL + t[j].first - t[i - 1].first + M1) % M1;
  h1 = (h1 * 1LL * inv[i].first) % M1;
  int h2 = (0LL + t[j].second - t[i - 1].second + M2) % M2;
  h2 = (h2 * 1LL * inv[i].second) % M2;
  return {h1, h2};
}
int main() {
  scanf("%d%d%s", &n, &k, a);
  pw[0].first = pw[0].second = inv[0].first = inv[0].second = 1;
  for (int i = 1; i <= 2 * n * k; i++) {
    pw[i].first = (pw[i - 1].first * 1LL * B1) % M1;
    pw[i].second = (pw[i - 1].second * 1LL * B2) % M2;
    inv[i].first = exp(pw[i].first, M1 - 2, M1);
    inv[i].second = exp(pw[i].second, M2 - 2, M2);
  }
  for (int i = 0; i < n * k; i++) b[i] = a[i];
  for (int i = n * k; i < 2 * n * k; i++) b[i] = a[i - n * k];
  for (int i = 0; i < 2 * n * k; i++) {
    int c = b[i] - 'a' + 1;
    t[i].first = (0LL + t[i - 1].first + c * 1LL * pw[i].first) % M1;
    t[i].second = (0LL + t[i - 1].second + c * 1LL * pw[i].second) % M2;
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%s", e);
    int l = strlen(e);
    pair<int, int> h = {0, 0};
    for (int j = 0; j < l; j++) {
      int c = e[j] - 'a' + 1;
      h.first = (0LL + h.first + c * 1LL * pw[j].first) % M1;
      h.second = (0LL + h.second + c * 1LL * pw[j].second) % M2;
    }
    s.insert(data(h, i));
  }
  for (int i = 0; i < n * k; i++) p[i] = i, sz[i] = 1;
  for (int i = 0; i < n * k; i++) joinst(i, (i + k) % (n * k));
  for (int i = 0; i < n * k; i++) v[findst(i)].push_back(i);
  for (int i = 5; i <= 5; i++) {
    if (v[i].empty()) continue;
    vector<data> q;
    vector<int> ids;
    int bad = 0;
    for (int p : v[i]) {
      auto h = getHash(p, p + k - 1);
      auto it = s.find(data(h, -1));
      int id = it->id;
      if (it == s.end()) {
        bad = 1;
        break;
      }
      s.erase(it);
      q.push_back(data(h, id));
      ids.push_back(id);
    }
    if (!bad) {
      printf("YES\n");
      for (int p : ids) printf("%d ", p + 1);
      printf("\n");
      return 0;
    }
    for (auto o : q) s.insert(o);
  }
  printf("NO\n");
  return 0;
}
