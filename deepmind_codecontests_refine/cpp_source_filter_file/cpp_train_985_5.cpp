#include <bits/stdc++.h>
using namespace std;
struct H {
  long long a, b;
  H(long long a = 1, long long b = 1) : a(a), b(b) {}
  H operator*(long long x) { return H(a * x, b * x % 1000000007); }
  H operator*(H h) { return H(a * h.a, b * h.b % 1000000007); }
  H operator+(H h) { return H(a + h.a, b + h.b % 1000000007); }
  H operator-(H h) { return H(a - h.a, (b - h.b + 1000000007) % 1000000007); }
  bool operator==(H h) { return a == h.a && b == h.b; }
};
int n;
string s;
H p[2 * 1000010], h[2 * 1000010];
int pre[1000010], suf[1000010];
int pmn[1000010], smx[1000010];
H get(int a, int len) {
  H res = h[a + len - 1];
  if (a > 0) res = res - h[a - 1];
  return res;
}
bool equal(int a, int b, int len) {
  if (a < b) swap(a, b);
  H ha = get(a, len);
  H hb = get(b, len) * p[a - b];
  return ha == hb;
}
bool test(int a, int b) {
  int lo = 0, hi = n + 1, mid;
  while (hi - lo > 1) {
    mid = (lo + hi) / 2;
    if (equal(a, b, mid))
      lo = mid;
    else
      hi = mid;
  }
  if (lo == n) return 0;
  return s[a + lo] < s[b + lo];
}
int main() {
  ios::sync_with_stdio(0);
  p[0] = H();
  for (int i = 1; i < 2 * 1000010; i++) p[i] = p[i - 1] * 37;
  cin >> s;
  n = s.size();
  for (int i = 0; i < n; i++) pre[i] = suf[i] = s[i] == '(' ? 1 : -1;
  for (int i = 1; i < n; i++) pre[i] += pre[i - 1];
  for (int i = n - 2; i >= 0; i--) suf[i] += suf[i + 1];
  pmn[0] = 1000010;
  for (int i = 1; i < n; i++) {
    pmn[i] = min(pmn[i - 1], pre[i - 1] + pre[n - 1]);
  }
  for (int i = n - 1, x = 1000010; i >= 0; i--) {
    x = min(x, pre[i]);
    pmn[i] = min(pmn[i], x);
  }
  smx[n] = -1000010;
  for (int i = n - 1; i >= 0; i--) {
    smx[i] = max(smx[i + 1], suf[i] + suf[0]);
  }
  for (int i = 1, x = -1000010; i < n; i++) {
    x = max(x, suf[i - 1]);
    smx[i] = max(smx[i], x);
  }
  for (int i = 1; i < n; i++) pmn[i] -= pre[i - 1];
  for (int i = n - 1; i >= 0; i--) smx[i] -= suf[i];
  s = s + s;
  for (int i = 0; i < n + n; i++) {
    h[i] = p[i] * (s[i] - '(');
    if (i > 0) h[i] = h[i] + h[i - 1];
  }
  int a = -1;
  for (int i = 0; i < n; i++) {
    if (suf[0] >= 0 && pmn[i] < 0) continue;
    if (suf[0] <= 0 && smx[i] > 0) continue;
    if (a < 0 || test(i, a)) a = i;
  }
  for (int i = 0; i < -suf[0]; i++) cout << '(';
  for (int i = 0; i < n; i++) cout << s[a + i];
  for (int i = 0; i < suf[0]; i++) cout << ')';
  cout << '\n';
}
