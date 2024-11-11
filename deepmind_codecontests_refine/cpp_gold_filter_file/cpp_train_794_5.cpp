#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
void fft(vector<complex<double> > &a, bool invert) {
  int n = (int)a.size(), k = (int)log2(n);
  for (int i = 0; i < n; i++) {
    int rev = 0;
    for (int j = 0; j < k; j++) {
      if (i & (1 << j)) {
        rev |= (1 << (k - j - 1));
      }
    }
    if (rev < i) {
      swap(a[i], a[rev]);
    }
  }
  for (int len = 2; len <= n; len *= 2) {
    double ang = 2 * pi / (double)len * (invert ? -1 : 1);
    complex<double> w_len = {cos(ang), sin(ang)};
    for (int i = 0; i < n; i += len) {
      complex<double> w = {1, 0};
      for (int j = i; j < i + len / 2; j++) {
        complex<double> u = a[j], v = a[j + len / 2] * w;
        a[j] = u + v;
        a[j + len / 2] = u - v;
        w *= w_len;
      }
    }
  }
  if (invert) {
    for (auto &x : a) {
      x /= (double)n;
    }
  }
}
vector<int> mul(vector<int> &a, const vector<int> &b) {
  int n = (1 << (int)ceil(log2((int)a.size() + (int)b.size())));
  vector<complex<double> > f(n, 0), g(n, 0);
  for (int i = 0; i < (int)a.size(); i++) {
    f[i] = {(double)a[i], 0};
  }
  for (int i = 0; i < (int)b.size(); i++) {
    g[i] = {(double)b[i], 0};
  }
  fft(f, false);
  fft(g, false);
  for (int i = 0; i < n; i++) {
    f[i] *= g[i];
  }
  fft(f, true);
  vector<int> ans((int)a.size() + (int)b.size() - 1);
  for (int i = 0; i < (int)ans.size(); i++) {
    ans[i] = (long long)round(f[i].real()) % 1009;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> freq(m + 1, 0);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    freq[x]++;
  }
  vector<vector<int> > ans(m + 1);
  for (int i = 1; i <= m; i++) {
    ans[i] = vector<int>(freq[i] + 1, 1);
  }
  function<void(int, int)> solve = [&](int l, int r) {
    if (l == r) {
      return;
    }
    int mid = (l + r) / 2;
    solve(l, mid);
    solve(mid + 1, r);
    ans[r] = mul(ans[mid], ans[r]);
  };
  solve(1, m);
  cout << ans[m][k] << '\n';
  return 0;
}
