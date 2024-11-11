#include <bits/stdc++.h>
using namespace std;
vector<int> first[1010];
long long n, m, c[1010][1010], second = 0, t[1010], k[1010], bs = 0, bt = 0;
double d[1010], h[1010];
pair<int, int> p[1010];
bool r[1010];
void read(void) {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> k[i];
    first[i].resize(k[i]);
    for (int j = 0, x; j < k[i]; ++j) {
      cin >> x;
      first[i][j] = x;
      p[second++] = make_pair(x, i);
    }
    sort(first[i].begin(), first[i].end());
  }
  sort(p, p + second);
}
void pre(void) {
  for (int i = 0; i < 1010; ++i) c[i][0] = 1;
  for (int i = 1; i < 1010; ++i)
    for (int j = 1; j <= i; ++j) {
      c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
      if (c[i][j] > 1000000000000000000LL) c[i][j] = 1000000000000000000LL;
    }
}
void make(void) {
  int l = p[second - n].first;
  for (int i = second - 1; i >= second - n && p[i].first > l; --i)
    t[p[i].second]++;
  for (int i = 0; i < second; ++i)
    if (p[i].first == l) r[p[i].second] = 1;
  for (int i = second - 1; i >= second - n; --i)
    if (p[i].first == l) bt++;
}
void kill(void) {
  h[0] = 1.0;
  for (int i = 0; i < m; ++i) {
    for (int j = t[i]; j <= n; ++j) d[j] = h[j - t[i]] / c[k[i]][t[i]];
    if (r[i]) {
      for (int j = t[i] + 1; j <= n; ++j)
        d[j] += (h[j - t[i] - 1] / c[k[i]][t[i] + 1]);
      bs++;
      if (bs > bt)
        for (int j = 0; j <= n; ++j) d[j] *= (1.0 - bt / bs);
    }
    for (int j = 0; j <= n; ++j) h[j] = d[j], d[j] = 0;
  }
  cout.precision(11);
  cout << fixed << h[n] << "\n";
}
int main() {
  pre();
  read();
  make();
  kill();
  return 0;
}
