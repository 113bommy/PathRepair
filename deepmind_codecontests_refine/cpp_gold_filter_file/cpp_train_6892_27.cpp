#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-11;
template <typename T, typename S>
vector<T>& operator<<(vector<T>& a, S b) {
  a.push_back(b);
  return a;
}
template <typename T>
void operator>>(vector<T>& a, int b) {
  while (b--)
    if (!a.empty()) a.pop_back();
}
bool isprime(int n) {
  if (n < 2) return false;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return false;
  return true;
}
long long b_pow(long long x, long long n) {
  return n ? b_pow(x * x, n / 2) * (n % 2 ? x : 1) : 1ll;
}
string itos(int n) {
  stringstream ss;
  ss << n;
  return ss.str();
}
int main() {
  ios_base::sync_with_stdio(false);
  long long t1, t2, x1, x2, t0;
  cin >> t1 >> t2 >> x1 >> x2 >> t0;
  long long ax, ay, swp = 0;
  if (t1 > t2) {
    swap(x1, x2);
    swap(t1, t2);
    swp = 1;
  }
  double DIFF = (1 << 25);
  for (long long i = 0; i <= x1; i++) {
    double l = 0, r = x2;
    bool f = true;
    for (int _ = 0; _ < 24; _++) {
      double m = (l + r) / 2.0;
      if (i + m < EPS) {
        f = false;
        break;
      }
      double x = (m * t2 + i * t1) / (i + m);
      if (x > t0)
        r = m;
      else
        l = m;
    }
    if (!f) continue;
    for (int p = -4; p < 4; p++) {
      long long L = (long long)(l + 0.5) - p;
      if (L < 0 || L > x2 || (L == 0 && i == 0)) continue;
      if ((L * t2 + i * t1) >= t0 * (i + L)) {
        double d = (1.0 * L * t2 + i * t1) / (i + L) - t0;
        if (d <= DIFF + EPS) {
          if (fabs(d - DIFF) < EPS) {
            if (ax + ay <= i + L) {
              ax = i;
              ay = L;
              DIFF = d;
            }
          } else {
            ax = i;
            ay = L;
            DIFF = d;
          }
        }
      }
    }
  }
  if (swp == 0)
    cout << ax << " " << ay << endl;
  else
    cout << ay << " " << ax << endl;
}
