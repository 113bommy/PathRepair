#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
const int Inf = 100000;
const int mod = 1000000007;
const double Pi = acos(-1);
void Fastio() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
void FFT(vector<cd> &A, bool invert) {
  int n = A.size();
  for (int i = 1, j = 0; i < n; i++) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;
    if (i < j) {
      swap(A[i], A[j]);
    }
  }
  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * Pi / len * (invert ? -1 : 1);
    cd wlen(cos(ang), sin(ang));
    for (int i = 0; i < n; i += len) {
      cd w(1, 0);
      for (int j = 0; j < len / 2; j++) {
        cd u = A[i + j], v = A[i + j + len / 2] * w;
        A[i + j] = u + v;
        A[i + j + len / 2] = u - v;
        w *= wlen;
      }
    }
  }
  if (invert) {
    for (auto &x : A) {
      x /= n;
    }
  }
}
int n, m, k;
int cnt[200005];
string s, t;
string gen = "ATGC";
void Solve(char x) {
  vector<cd> A(524288, cd(0, 0)), B(524288, cd(0, 0));
  for (int i = 0; i < m; i++) {
    if (t[i] == x) {
      B[i] = cd(1, 0);
    }
  }
  int prv = -mod;
  for (int i = 0; i < n; i++) {
    if (s[i] == x) {
      prv = i;
    }
    if (i - prv <= k) {
      A[i] = cd(1, 0);
    }
  }
  prv = 1e9;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == x) {
      prv = i;
    }
    if (prv - i <= k) {
      A[i] = cd(1, 0);
    }
  }
  FFT(A, false);
  FFT(B, false);
  for (int i = 0; i < 524288; i++) {
    A[i] *= B[i];
  }
  FFT(A, true);
  for (int i = m - 1; i < n; i++) {
    cnt[i - m + 1] += (int)(A[i].real() + 0.5);
  }
}
int main() {
  cin >> n >> m >> k >> s >> t;
  reverse(t.begin(), t.end());
  for (auto x : gen) {
    Solve(x);
  }
  int ans = 0;
  for (int i = 0; i < n - m + 1; i++) {
    if (cnt[i] == m) {
      ans++;
    }
  }
  cout << ans;
}
