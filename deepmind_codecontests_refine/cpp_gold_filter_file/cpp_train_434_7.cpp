#include <bits/stdc++.h>
using namespace std;
const int MOD = (119 << 23) + 1, root = 3;
const long double PI = 4 * atan((long double)1);
int size(int s) { return s > 1 ? 32 - __builtin_clz(s - 1) : 0; }
int sum(int a, const int &b) {
  if ((a += b) >= MOD) a -= MOD;
  return a;
}
int sub(int a, const int &b) {
  if ((a -= b) < 0) a += MOD;
  return a;
}
int mult(int a, const int &b) { return (1LL * a * b) % MOD; }
int binpow(long long x, long long p) {
  int ans;
  for (ans = 1; p; p >>= 1) {
    if (p & 1LL) ans = mult(ans, x);
    x = mult(x, x);
  }
  return ans;
}
void genRoots(vector<complex<double>> &roots) {
  int n = int(roots.size());
  long double ang = 2 * PI / n;
  for (int i = 0; i < n; ++i)
    roots[i] = complex<double>(cos(ang * i), sin(ang * i));
}
void genRoots(vector<int> &roots) {
  int n = int(roots.size());
  int r = binpow(root, (MOD - 1) / n);
  roots[0] = 1;
  for (int i = 1; i < n; ++i) roots[i] = mult(roots[i - 1], r);
}
void Fft(vector<int> &a, const vector<int> &roots, bool inv = 0) {
  int n = int(a.size());
  for (int i = 1, j = 0; i < n; ++i) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int len = 2; len <= n; len <<= 1)
    for (int i = 0; i < n; i += len)
      for (int j = 0; j < len / 2; ++j) {
        int ind = n / len * j;
        if (inv && ind) ind = n - ind;
        int u = a[i + j], v = mult(a[i + j + len / 2], roots[ind]);
        a[i + j] = sum(u, v), a[i + j + len / 2] = sub(u, v);
      }
  if (inv) {
    int i = binpow(n, MOD - 2);
    for (int &x : a) x = mult(x, i);
  }
}
vector<int> Mult(vector<int> a, vector<int> b) {
  if (!min(int(a.size()), int(b.size()))) return {};
  int s = int(a.size()) + int(b.size()) - 1, n = 1 << size(s);
  vector<int> roots(n);
  genRoots(roots);
  a.resize(n);
  Fft(a, roots);
  b.resize(n);
  Fft(b, roots);
  for (int i = 0; i < n; ++i) a[i] = mult(a[i], b[i]);
  Fft(a, roots, true);
  a.resize(s);
  return a;
}
int main() {
  int n, x;
  scanf("%d", &n);
  map<int, int> mapa;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    mapa[x]++;
  }
  priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>,
                 greater<pair<int, vector<int>>>>
      pq;
  for (pair<int, int> par : mapa) {
    vector<int> vec(par.second + 1, 1);
    pq.push(make_pair(par.second + 1, vec));
  }
  while (int(pq.size()) > 1) {
    pair<int, vector<int>> x = pq.top();
    pq.pop();
    pair<int, vector<int>> y = pq.top();
    pq.pop();
    x.second = Mult(x.second, y.second);
    pq.push(make_pair(int(x.second.size()), x.second));
  }
  vector<int> ans = pq.top().second;
  cout << ans[n / 2] << endl;
  return 0;
}
