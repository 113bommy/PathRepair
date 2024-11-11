#include <bits/stdc++.h>
using namespace std;
struct LINE {
  long long a, b;
  LINE(long long a, long long b) : a(a), b(b) {}
  long long cal(long long x) { return a * x + b; }
};
struct CONVEX {
  deque<LINE> convex;
  CONVEX() { convex.clear(); }
  void clearAll() { convex.clear(); }
  bool bad(LINE a, LINE b, LINE c) {
    return (a.b - b.b) * (c.a - b.a) <= (b.b - c.b) * (b.a - a.a);
  }
  void add(LINE l) {
    while (convex.size() > 1 &&
           bad(l, convex.back(), convex[convex.size() - 2]))
      convex.pop_back();
    convex.push_back(l);
  }
  long long get(long long x) {
    int l = 0, r = convex.size() - 1;
    while (l < r) {
      int m = (l + r) >> 1;
      if (convex[m].cal(x) < convex[m + 1].cal(x))
        l = m + 1;
      else
        r = m;
    }
    return convex[l].cal(x);
  }
};
int n;
long long res, sum;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  vector<long long> a(n + 3), s(n + 3);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
    sum += a[i] * i;
  }
  CONVEX convex;
  convex.add(LINE(-n, -s[n]));
  for (int l = n - 1; l > 0; l--) {
    res = max(res, convex.get(-a[l]) - a[l] * l + s[l]);
    convex.add(LINE(-l, -s[l]));
  }
  convex.clearAll();
  convex.add(LINE(1, 0));
  for (int r = 2; r <= n; r++) {
    res = max(res, convex.get(a[r]) - a[r] * r + s[r - 1]);
    convex.add(LINE(r, -s[r - 1]));
  }
  cout << sum + res;
}
