#include <bits/stdc++.h>
using namespace std;
const int MX = 200005;
int gcd(int a, int b) {
  while (b) {
    int c = a % b;
    a = b;
    b = c;
  }
  return a;
}
int p[MX];
int solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  sort(p, p + n);
  reverse(p, p + n);
  int x, a, y, b;
  cin >> x >> a >> y >> b;
  long long k;
  cin >> k;
  if (x < y) {
    swap(x, y);
    swap(a, b);
  }
  int c = a * 1LL * b / (long long)gcd(a, b);
  int L = 1, R = n;
  int ans = -1;
  while (L <= R) {
    int M = (L + R) / 2;
    long long g = 0;
    int t = 0;
    for (int i = 0; i < M / c; i++) {
      g += p[t++] / 100LL * (x + y);
    }
    for (int i = 0; i < M / a - M / c; i++) {
      g += p[t++] / 100LL * x;
    }
    for (int i = 0; i < M / b - M / c; i++) {
      g += p[t++] / 100LL * y;
    }
    if (g >= k) {
      ans = M;
      R = M - 1;
    } else {
      L = M + 1;
    }
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    cout << solve() << "\n";
  }
}
