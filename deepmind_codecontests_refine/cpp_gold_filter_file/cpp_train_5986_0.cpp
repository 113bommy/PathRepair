#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  while (b) {
    int q = a;
    a = b;
    b = q % b;
  }
  return a;
}
struct point {
  long long x, y;
  point operator-(point a) { return {x - a.x, y - a.y}; }
  long long operator*(point a) { return x * a.y - y * a.x; }
  int get() { return gcd(abs(x), abs(y)) - 1; }
};
const int MAXN = 120000;
point arr[MAXN * 2];
long double go[MAXN];
int gg[MAXN * 2];
long long cc;
int n;
void init() {
  for (int i = 0; i < n; ++i) {
    long long now = 2 - 1;
    for (int j = i + 1; j < i + n - 1 && j < i + 100; ++j) {
      now += abs((arr[j] - arr[i]) * (arr[j - 1] - arr[i]));
      now -= gg[j - 1] + 1;
      long long nn = now;
      nn += (arr[j] - arr[i]).get();
      nn /= 2;
      go[j - i] += nn;
    }
  }
}
void solve1() {
  long double ans = cc;
  long double all = 1;
  for (int i = 0; i < n; ++i) all *= 2;
  all -= 1 + n + (long long)n * (n - 1) / 2;
  long double fr = 1;
  for (int i = n - 2; i >= 2; --i) {
    fr *= 2;
    if (go[i] < 1e-6) continue;
    ans -= go[i] * ((fr - 1) / all);
  }
  cout.setf(ios::fixed);
  cout.precision(20);
  cout << ans << "\n";
}
void solve2() {
  long double ans = cc;
  for (int i = 1; i <= 100; ++i) {
    for (int j = 0; j < i + 1; ++j) {
      go[i] /= 2;
      if (go[i] < 1e-6) go[i] = 0;
    }
  }
  for (int i = n - 2; i >= 2; --i) {
    if (go[i] < 1e-6) continue;
    ans -= go[i];
  }
  cout.setf(ios::fixed);
  cout.precision(20);
  cout << ans << "\n";
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%lld%lld", &arr[i].x, &arr[i].y);
  for (int i = 0; i < n; ++i) arr[i + n] = arr[i];
  for (int i = 0; i < n; ++i) cc += arr[i] * arr[i + 1];
  cc = abs(cc);
  cc += 2;
  for (int i = 0; i < n; ++i) {
    cc -= (arr[i] - arr[i + 1]).get() + 1;
  }
  for (int i = 0; i < 2 * n - 1; ++i) gg[i] = (arr[i + 1] - arr[i]).get();
  cc /= 2;
  init();
  if (n < 50)
    solve1();
  else
    solve2();
  return 0;
}
