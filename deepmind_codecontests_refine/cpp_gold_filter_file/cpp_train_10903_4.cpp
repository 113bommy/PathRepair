#include <bits/stdc++.h>
using namespace std;
int n, x;
string s;
long double ans, crt;
long double _pow(long double a, int b) {
  if (b == 0) return 0;
  if (b == 1) return a;
  if (b % 2 == 0)
    return _pow(a + a, b / 2);
  else
    return _pow(a + a, b / 2) + a;
}
long double get(int nr) {
  int a = nr / 3;
  nr %= 3;
  if (nr == 1) a--, nr += 3;
  long double ans = _pow(log10(3.0), a);
  if (nr > 0) ans += log10(nr);
  return ans;
}
struct cd {
  long double A, B;
  cd(long double a, long double b) {
    A = a;
    B = b;
  }
  cd(long double a) {
    A = a;
    B = 0;
  }
  cd() {
    A = 0;
    B = 0;
  }
  long double real() { return A; }
  cd operator*(const cd &oth) const {
    return cd(A * oth.A - B * oth.B, A * oth.B + B * oth.A);
  }
  bool operator*=(const cd &oth) {
    long double a = A * oth.A - B * oth.B;
    long double b = A * oth.B + B * oth.A;
    A = a;
    B = b;
  }
  cd operator+(const cd &oth) const { return cd(A + oth.A, B + oth.B); }
  cd operator-(const cd &oth) const { return cd(A - oth.A, B - oth.B); }
  bool operator/=(const long double &oth) { A /= oth; }
};
vector<int> B, C;
int m, t;
const long double pi = acos(-1);
int rev(int x, int lg) {
  int ans = 0;
  for (int i = 0; i < lg; i++)
    if (x & (1 << i)) ans += (1 << (lg - i - 1));
  return ans;
}
void FFT(vector<cd> &A, bool inv) {
  int sz = A.size();
  int lg = log2(sz) + 0.0000001;
  for (int i = 0; i < sz; i++)
    if (i < rev(i, lg)) swap(A[i], A[rev(i, lg)]);
  for (int len = 2; len <= sz; len <<= 1) {
    long double ang = 2 * pi / len * (inv ? -1 : 1);
    cd d(cos(ang), sin(ang));
    for (int i = 0; i < sz; i += len) {
      cd w(1, 0);
      for (int j = 0; j < len / 2; j++) {
        cd u = A[i + j], v = w * A[i + j + len / 2];
        A[i + j] = u + v;
        A[i + j + len / 2] = u - v;
        w *= d;
      }
    }
  }
  for (int i = 0; i < sz && inv; i++) A[i] /= sz;
}
vector<cd> _C, _A, _B;
vector<int> mult(vector<int> A, vector<int> B) {
  _A.clear();
  _B.clear();
  _C.clear();
  int lg = max(A.size(), B.size()) * 2, sz = 1;
  while (sz < lg) sz *= 2;
  _A.resize(sz);
  _B.resize(sz);
  for (int i = 0; i < A.size(); i++) _A[i] = cd(A[i]);
  for (int i = 0; i < B.size(); i++) _B[i] = cd(B[i]);
  _C.resize(_A.size());
  FFT(_A, 0);
  FFT(_B, 0);
  for (int i = 0; i < _A.size(); i++) _C[i] = _A[i] * _B[i];
  FFT(_C, 1);
  vector<int> ans;
  long long T = 0;
  for (int i = 0; i < _C.size(); i++) {
    T += (_C[i].real() + 0.5);
    ans.push_back(T % ((int)1e4));
    T /= ((int)1e4);
  }
  while (T != 0) {
    ans.push_back(T % ((int)1e4));
    T /= ((int)1e4);
  }
  while (!ans.empty() && ans.back() == 0) ans.pop_back();
  if (ans.empty()) ans.push_back(0);
  return ans;
}
void BigPow(vector<int> A, int b) {
  if (b % 2 == 1) C = mult(C, vector<int>(A));
  if (b <= 1) return;
  BigPow(mult(vector<int>(A), vector<int>(A)), b / 2);
}
int cmp(vector<int> A, vector<int> B) {
  if (A.size() < B.size())
    return -1;
  else if (A.size() > B.size())
    return 1;
  for (int i = A.size() - 1; i >= 0; i--) {
    if (A[i] < B[i])
      return -1;
    else if (A[i] > B[i])
      return 1;
  }
  return 0;
}
bool OK(int nr) {
  int a = nr / 3;
  nr %= 3;
  if (nr == 1) a--, nr += 3;
  vector<int> A = {3};
  C = {1};
  BigPow(A, a);
  if (nr != 0) C = mult(C, {nr});
  if (cmp(C, B) < 0) return false;
  return true;
}
int main() {
  cin >> s;
  if (s == "1" || s == "0") {
    cout << 1;
    return 0;
  }
  if (s == "2") {
    cout << 2;
    return 0;
  }
  n = s.size();
  for (int i = 0; i < min(9, n); i++) {
    x = x * 10 + s[i] - '0';
  }
  ans = log10(x);
  if (n > 9) {
    n -= 9;
    ans += n;
  }
  int st = 0, dr = 1e9, mid;
  while (st <= dr) {
    mid = (st + dr) / 2;
    crt = get(mid);
    if (crt > ans - 0.000000000001) {
      dr = mid - 1;
    } else {
      st = mid + 1;
    }
  }
  for (int i = s.size() - 1; i >= 0; i -= 4) {
    long long crt = 0;
    for (int j = max(i - 4, -1) + 1; j <= i; j++) {
      crt = crt * 10 + s[j] - '0';
    }
    B.push_back(crt);
  }
  if (!OK(st)) {
    st++;
  }
  cout << st << '\n';
  return 0;
}
