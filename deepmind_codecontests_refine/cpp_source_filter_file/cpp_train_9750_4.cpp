#include <bits/stdc++.h>
using namespace std;
const int PI = 2 * acos(0);
int rev(int num, int lg_n) {
  int res = 0;
  for (int i = 0; i < lg_n; ++i)
    if (num & (1 << i)) res |= 1 << (lg_n - 1 - i);
  return res;
}
void fft(vector<complex<double>>& a, bool invert) {
  int n = (int)a.size();
  int lg_n = 0;
  while ((1 << lg_n) < n) ++lg_n;
  for (int i = 0; i < n; ++i)
    if (i < rev(i, lg_n)) swap(a[i], a[rev(i, lg_n)]);
  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * PI / len * (invert ? -1 : 1);
    complex<double> wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      complex<double> w(1);
      for (int j = 0; j < len / 2; ++j) {
        complex<double> u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }
  if (invert)
    for (int i = 0; i < n; ++i) a[i] /= n;
}
vector<int> mult(vector<int> a, vector<int> b) {
  int logn = 0;
  while ((1 << logn) < max(a.size(), b.size())) logn++;
  while (a.size() < (1 << logn)) a.push_back(0);
  while (b.size() < (1 << logn)) b.push_back(0);
  vector<complex<double>> A((1 << logn)), B((1 << logn));
  for (int i = 0; i < (1 << logn); ++i) {
    A[i] = a[i];
    B[i] = b[i];
  }
  fft(A, 0);
  fft(B, 0);
  for (int i = 0; i < (1 << logn); ++i) {
    A[i] *= B[i];
  }
  fft(A, 1);
  vector<int> ans((1 << logn));
  for (int i = 0; i < (1 << logn); ++i) {
    ans[i] = (int)(A[i].real() + 0.5);
  }
  return ans;
}
void dfs(int v, vector<int>& used, vector<vector<int>>& g) {
  used[v] = 1;
  for (auto u : g[v]) {
    if (!used[u]) {
      dfs(u, used, g);
    }
  }
}
void solve() {
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  int N = 'f' - 'a' + 1;
  vector<vector<vector<int>>> G(n - m + 1, vector<vector<int>>(N));
  for (char c1 = 'a'; c1 <= 'f'; ++c1) {
    for (int c2 = 'a'; c2 <= 'f'; ++c2) {
      vector<int> a(n), b(m);
      for (int i = 0; i < n; ++i) {
        a[i] = (c1 == s[i]);
      }
      for (int j = 0; j < m; ++j) {
        b[j] = (c2 == t[j]);
      }
      reverse(b.begin(), b.end());
      vector<int> res = mult(a, b);
      for (int k = m - 1; k < m - 1 + n - m + 1; ++k) {
        if (res[k]) {
          G[k - m + 1][c1 - 'a'].push_back(c2 - 'a');
          G[k - m + 1][c2 - 'a'].push_back(c1 - 'a');
        }
      }
    }
  }
  for (int p = 0; p < n - m + 1; ++p) {
    vector<int> used(N);
    int comp = 0;
    for (int i = 0; i < N; ++i) {
      if (!used[i]) {
        dfs(i, used, G[p]);
        comp++;
      }
    }
    cout << N - comp << ' ';
  }
}
int32_t main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  int tt = 1;
  while (tt--) {
    solve();
  }
}
