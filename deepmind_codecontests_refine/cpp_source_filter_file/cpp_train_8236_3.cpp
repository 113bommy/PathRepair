#include <bits/stdc++.h>
using namespace std;
struct MaxTreeLL {
  static const long long LOW = INT_MIN;
  long long f(long long a, long long b) { return max(a, b); }
  vector<long long> s;
  int n;
  MaxTreeLL(int n = 0, long long def = 0) : s(2 * n, def), n(n) {}
  void update(int pos, long long val) {
    for (s[pos += n] = val; pos > 1; pos /= 2)
      s[pos / 2] = f(s[pos & ~1], s[pos | 1]);
  }
  long long query(int b, int e) {
    long long ra = LOW, rb = LOW;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) ra = f(ra, s[b++]);
      if (e % 2) rb = f(s[--e], rb);
    }
    return f(ra, rb);
  }
};
struct MaxTreeP {
  pair<int, int> LOW = make_pair(INT_MIN, -1);
  pair<int, int> f(pair<int, int> a, pair<int, int> b) { return max(a, b); }
  vector<pair<int, int> > s;
  int n;
  MaxTreeP(int n = 0, pair<int, int> def = make_pair(INT_MIN, -1))
      : s(2 * n, def), n(n) {}
  void update(int pos, pair<int, int> val) {
    for (s[pos += n] = val; pos > 1; pos /= 2)
      s[pos / 2] = f(s[pos & ~1], s[pos | 1]);
  }
  pair<int, int> query(int b, int e) {
    pair<int, int> ra = LOW, rb = LOW;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) ra = f(ra, s[b++]);
      if (e % 2) rb = f(s[--e], rb);
    }
    return f(ra, rb);
  }
};
struct MinTree {
  static const long long LOW = 1e18;
  long long f(long long a, long long b) { return min(a, b); }
  vector<long long> s;
  int n;
  MinTree(int n = 0, long long def = 0) : s(2 * n, def), n(n) {}
  void update(int pos, long long val) {
    for (s[pos += n] = val; pos > 1; pos /= 2)
      s[pos / 2] = f(s[pos & ~1], s[pos | 1]);
  }
  long long query(int b, int e) {
    long long ra = LOW, rb = LOW;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) ra = f(ra, s[b++]);
      if (e % 2) rb = f(s[--e], rb);
    }
    return f(ra, rb);
  }
};
MinTree minTree(300005);
MaxTreeLL maxTree(300005);
MaxTreeP diffTree(300005);
long long ans;
void rec(int l, int r) {
  if (r - l <= 1) return;
  auto bestCut = diffTree.query(l, r - 1);
  long long cutDiff = bestCut.first;
  int cut = bestCut.second;
  long long res = maxTree.query(cut + 2, r + 1);
  res -= minTree.query(l, cut + 1);
  res -= cutDiff * cutDiff;
  ans = max(ans, res);
  rec(l, cut + 1);
  rec(cut + 1, r);
}
int main() {
  ios::sync_with_stdio(0);
  int n, a;
  cin >> n >> a;
  vector<long long> d(n), g(n);
  for (int i = (0); i < int(n); ++i) {
    long long c;
    cin >> d[i] >> c;
    g[i] = a - c;
  }
  vector<long long> gsum(n + 1);
  for (int i = (0); i < int(n); ++i) {
    gsum[i + 1] = gsum[i] + g[i];
    minTree.update(i, gsum[i]);
    maxTree.update(i, gsum[i]);
    if (i < n - 1) {
      diffTree.update(i, make_pair(d[i + 1] - d[i], i));
    }
    ans = max(ans, g[i]);
  }
  minTree.update(n, gsum[n]);
  maxTree.update(n, gsum[n]);
  rec(0, n);
  cout << ans << endl;
}
