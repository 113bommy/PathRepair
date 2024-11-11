#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const double PI = acos(-1);
int lg_n;
int rev[maxn * 20];
vector<complex<double> > polies[maxn];
int reverse(int num, int lll) { return rev[num]; }
void fft(vector<complex<double> >& a, bool invert) {
  int n = a.size();
  for (int i = 0; i < n; i++) {
    if (i < reverse(i, lg_n)) swap(a[i], a[reverse(i, lg_n)]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * PI / len * (invert ? -1 : 1);
    complex<double> wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      complex<double> w(1);
      for (int j = 0; j < len / 2; j++) {
        complex<double> u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }
  if (invert) {
    for (complex<double>& x : a) x /= n;
  }
}
void multiply(int u, int v) {
  int n = 1;
  while (n < max((int)polies[u].size(), (int)polies[v].size())) {
    n <<= 1;
  }
  n <<= 1;
  lg_n = 0;
  while ((1 << lg_n) < n) lg_n++;
  for (int i = 0; i < n; ++i) {
    rev[i] = 0;
    for (int j = 0; j < lg_n; ++j)
      if (i & (1 << j)) rev[i] |= 1 << (lg_n - 1 - j);
  }
  polies[u].resize(n);
  polies[v].resize(n);
  fft(polies[u], false), fft(polies[v], false);
  for (int i = 0; i <= n - 1; ++i) {
    polies[u][i] *= polies[v][i];
  }
  fft(polies[u], true);
  for (int i = 0; i <= n - 1; ++i) {
    long long a = round(polies[u][i].real());
    polies[u][i] = a % 1009;
  }
}
int cnt[maxn];
priority_queue<pair<int, int> > pq;
int n, m, k;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  for (int i = 1; i <= m; ++i) {
    if (cnt[i]) {
      polies[i].resize(cnt[i] + 1);
      fill(polies[i].begin(), polies[i].end(), 1);
      pq.push({-cnt[i] - 1, i});
    }
  }
  while (pq.size() > 1) {
    int u = pq.top().second;
    pq.pop();
    int v = pq.top().second;
    pq.pop();
    multiply(u, v);
    pq.push({-((int)polies[u].size()), u});
  }
  int ans = round(polies[pq.top().second][k].real());
  cout << ans << endl;
}
