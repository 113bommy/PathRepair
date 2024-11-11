#include <bits/stdc++.h>
using namespace std;
long long fa[500005], fb[500005];
long long n, ans, pown = 1, m;
pair<long long, long long> t[4 * 500005];
string a, b, second;
vector<int> z_function(string second) {
  int n = (int)second.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < n && second[z[i]] == second[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}
void upd(long long x) {
  if (!x) return;
  t[x].first = t[2 * x].first + t[2 * x + 1].first;
  t[x].second = t[2 * x].second + t[2 * x + 1].second;
  upd(x / 2);
}
pair<long long, long long> cnt(long long x, long long L, long long R,
                               long long l, long long r) {
  if (L > r || R < l) return make_pair(0LL, 0LL);
  if (L >= l && R <= r) return t[x];
  pair<long long, long long> k1 = cnt(2 * x, L, (L + R) / 2, l, r);
  pair<long long, long long> k2 = cnt(2 * x + 1, (L + R) / 2 + 1, R, l, r);
  return make_pair(k1.first + k2.first, k1.second + k2.second);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  cin >> a >> b >> second;
  while (pown <= n) pown *= 2;
  string c = "";
  for (int i = 0; i < m - 1; i++) {
    c += second[i];
  }
  c += "#";
  c += a;
  vector<int> za = z_function(c);
  for (int i = m; i < c.size(); i++) fa[i - m + 1] = za[i];
  c = "";
  reverse(second.begin(), second.end());
  for (int i = 0; i < m - 1; i++) c += second[i];
  reverse(b.begin(), b.end());
  c += "#";
  c += b;
  vector<int> zb = z_function(c);
  for (int i = m; i < c.size(); i++) fb[i - m + 1] = zb[i];
  reverse(fb + 1, fb + n + 1);
  for (int i = 1; i < min(n + 1, m - 1); i++) {
    long long ind = fb[i];
    if (ind) {
      t[pown + ind - 1].first++;
      t[pown + ind - 1].second += ind;
      upd((pown + ind - 1) / 2);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i + m - 2 <= n) {
      long long ind = fb[i + m - 2];
      if (ind) {
        t[pown + ind - 1].first++;
        t[pown + ind - 1].second += ind;
        upd((pown + ind - 1) / 2);
      }
    }
    if (i > 1) {
      long long ind = fb[i - 1];
      if (ind) {
        t[pown + ind - 1].first--;
        t[pown + ind - 1].second -= ind;
        upd((pown + ind - 1) / 2);
      }
    }
    pair<long long, long long> got = cnt(1, 1, pown, m - fa[i] - 1, m);
    ans += got.first * fa[i] + got.second - got.first * m + got.first;
  }
  cout << ans << '\n';
  return 0;
}
