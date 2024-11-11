#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using cd = complex<double>;
ll base = 1000;
void fft(vector<cd>& a, bool inv) {
  int n = a.size();
  int bits = __builtin_ctz(n);
  for (int i = 0; i < n; ++i) {
    int x = 0;
    for (int j = 0; j < bits; ++j) x = (x << 1) | (i >> j & 1);
    if (i > x) swap(a[i], a[x]);
  }
  for (int m = 2; m <= n; m *= 2) {
    auto alpha = (inv ? -2 : 2) * 3.14159265358979323846 / m;
    auto w = exp(cd(0, alpha));
    for (int k = 0; k < n; k += m) {
      cd x = 1;
      for (int i = 0; i < m / 2; ++i) {
        auto u = a[k + i];
        auto v = a[k + i + m / 2] * x;
        a[k + i] = u + v;
        a[k + i + m / 2] = u - v;
        x *= w;
      }
    }
  }
  if (inv)
    for (auto& x : a) x /= n;
}
void int_mul(vector<ll>& a, ll v) {
  ll carry = 0;
  for (int i = 0; i < a.size() || carry; ++i) {
    if (i >= a.size()) a.emplace_back(0ll);
    a[i] = a[i] * v + carry;
    carry = a[i] / base;
    a[i] %= base;
  }
}
void shrink(vector<ll>& a) {
  while (a.size() > 1 && a.back() == 0) a.pop_back();
}
void normalize(vector<ll>& a) {
  ll carry = 0;
  for (int i = 0; i < a.size() || carry; ++i) {
    if (i >= a.size()) a.emplace_back(0);
    carry += a[i];
    a[i] = carry % base;
    carry -= a[i];
    carry /= base;
  }
  shrink(a);
}
void sqr(vector<ll>& a) {
  int n = a.size();
  int m = 1;
  while (m < n + n) m *= 2;
  vector<cd> b(m);
  for (int i = 0; i < n; ++i) b[i] = a[i];
  fft(b, false);
  for (auto& x : b) x *= x;
  fft(b, true);
  a.resize(b.size());
  for (int i = 0; i < b.size(); ++i) a[i] = b[i].real() + 0.5;
  normalize(a);
}
vector<ll> bp(int e) {
  if (e == 0) return vector<ll>{1};
  auto v = bp(e / 2);
  sqr(v);
  if (e & 1) int_mul(v, 3);
  return v;
}
int compare(vector<ll> const& a, vector<ll> const& b) {
  if (a.size() != b.size()) return a.size() < b.size() ? -1 : 1;
  for (int i = int(a.size()) - 1; i >= 0; --i)
    if (a[i] != b[i]) return a[i] < b[i] ? -1 : 1;
  return 0;
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  string number;
  cin >> number;
  vector<ll> num;
  int n = number.size();
  int x = 3;
  num.reserve((n + x - 1) / x);
  reverse(number.begin(), number.end());
  for (int i = 0; i < n; i += x) {
    auto s = number.substr(i, x);
    reverse(s.begin(), s.end());
    num.emplace_back(stoll(s));
  }
  int log3 = n / log10(3);
  int start = max(0, log3 - 3);
  int last = 5;
  auto A = bp(start);
  shrink(A);
  auto B = A;
  int_mul(B, 2);
  auto C = B;
  int_mul(C, 2);
  int ans = 3 * 10 * 1000 * 1000;
  for (int p = 0; p < last; ++p) {
    int v = 3 * (start + p);
    if (v < ans && compare(A, num) >= 0) {
      ans = min(ans, v);
      break;
    } else if (v + 3 < ans) {
      int_mul(A, 3);
    } else {
      break;
    }
  }
  for (int p = 0; p < last; ++p) {
    int v = 2 + 3 * (start + p);
    if (v < ans && compare(B, num) >= 0) {
      ans = min(ans, v);
      break;
    } else if (v + 3 < ans) {
      int_mul(B, 3);
    } else {
      break;
    }
  }
  for (int p = 0; p < last; ++p) {
    int v = 4 + 3 * (start + p);
    if (v < ans && compare(C, num) >= 0) {
      ans = min(ans, v);
      break;
    } else if (v + 3 < ans) {
      int_mul(C, 3);
    } else {
      break;
    }
  }
  cout << max(1, ans);
}
