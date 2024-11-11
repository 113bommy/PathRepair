#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
const double PI = acos(-1);
void fft(vector<cd>& a, bool invert) {
  int n = a.size();
  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;
    if (i < j) swap(a[i], a[j]);
  }
  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * PI / len * (invert ? -1 : 1);
    cd wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      cd w(1);
      for (int j = 0; j < len / 2; j++) {
        cd u = a[i + j], v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }
  if (invert) {
    for (cd& x : a) x /= n;
  }
}
vector<int> multiply(vector<int> const& a, vector<int> const& b) {
  vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
  int n = 1;
  while (n < a.size() + b.size()) n <<= 1;
  fa.resize(n);
  fb.resize(n);
  fft(fa, false);
  fft(fb, false);
  for (int i = 0; i < n; i++) fa[i] *= fb[i];
  fft(fa, true);
  vector<int> result(n);
  for (int i = 0; i < n; i++) result[i] = round(fa[i].real());
  return result;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, x, y, k = 200001;
  cin >> n >> x >> y;
  vector<int> a(n + 1), ca(k + 1, 0), cb(k + 1, 0);
  for (auto& i : a) {
    cin >> i;
    ca[i] = 1;
    cb[k - i] = 1;
  }
  auto cr = multiply(ca, cb);
  vector<int> ds(x + 1, 0);
  for (int i = 0; i <= x; i++) {
    ds[i] = cr[i + k];
  }
  ds[0] = 0;
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l;
    cin >> l;
    int j = sqrt(l);
    int ans = -1;
    while (j >= 1) {
      if (l % j == 0) {
        int xl1 = (j >> 1) - y;
        int xl2 = (l / j >> 1) - y;
        if (!(j & 1) and 0 <= xl1 and xl1 <= x and ds[xl1]) {
          ans = max(ans, j);
        }
        if (!(l / j & 1) and 0 <= xl2 and xl2 <= x and ds[xl2]) {
          ans = max(ans, l / j);
        }
      }
      --j;
    }
    cout << ans << " ";
  }
  cout << "\n";
  return 0;
}
