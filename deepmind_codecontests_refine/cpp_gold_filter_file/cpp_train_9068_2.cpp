#include <bits/stdc++.h>
using namespace std;
struct line {
  long long m, b;
  line(long long m, long long b) : m(m), b(b) {}
  long double inter(line c) {
    long double numer = b - c.b;
    long double denom = c.m - m;
    return numer / denom;
  }
  long long eval(long long x) { return x * m + b; }
};
struct rect {
  long long w, h, a;
  rect(long long w, long long h, long long a) : w(w), h(h), a(a) {}
  bool operator<(rect b) const { return w < b.w; }
};
vector<line> lines;
int pnt = 0;
void add(line a) {
  int sz = lines.size();
  while (sz > 1 and
         lines[sz - 1].inter(lines[sz - 2]) < lines[sz - 1].inter(a)) {
    sz--;
    lines.pop_back();
  }
  pnt = min(pnt, sz);
  lines.push_back(a);
}
long long qry(long long x) {
  int sz = lines.size();
  while (pnt < sz - 1 and x <= lines[pnt].inter(lines[pnt + 1])) {
    pnt++;
  }
  return lines[pnt].eval(x);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<rect> rects(n, rect(0, 0, 0));
  for (int i = 0; i < n; i++) {
    cin >> rects[i].w >> rects[i].h >> rects[i].a;
  }
  sort(rects.begin(), rects.end());
  vector<long long> dp(n, 0);
  dp[0] = rects[0].w * rects[0].h - rects[0].a;
  dp[0] = max(0ll, dp[0]);
  long long ans = max(0ll, dp[0]);
  add(line(-rects[0].w, dp[0]));
  for (int i = 1; i < n; i++) {
    long long val = qry(rects[i].h);
    dp[i] = rects[i].h * rects[i].w - rects[i].a;
    if (val > 0) dp[i] += val;
    dp[i] = max(dp[i - 1], dp[i]);
    add(line(-rects[i].w, dp[i]));
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
}
