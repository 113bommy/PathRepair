#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1000000000")
static long long m1[1000000], m2[2500], m3[1000000];
static vector<vector<long long> > li;
static map<long long, long long> wh;
long long gmi(long long x, long long l, long long r) {
  if (wh.find(x) == wh.end()) return (long long)1000000007;
  x = wh[x];
  if (li[x][li[x].size() - 1] < l) return (long long)1000000007;
  long long y =
      li[x][lower_bound(li[x].begin(), li[x].end(), l) - li[x].begin()];
  if (y >= r) return (long long)1000000007;
  return y;
}
long long gma(long long x, long long l, long long r) {
  if (wh.find(x) == wh.end()) return -(long long)1000000007;
  x = wh[x];
  if (li[x][0] >= r) return -(long long)1000000007;
  long long y =
      li[x][lower_bound(li[x].begin(), li[x].end(), r) - li[x].begin() - 1];
  if (y < l) return -(long long)1000000007;
  return y;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; ++i) cin >> m1[i];
  vector<long long> vc, vc1, vc2, vc3, tm;
  long long a, b, c, d;
  for (int tt = 0; tt < q; ++tt) {
    if (tt % 2000 == 0) {
      memset(m3, 0, sizeof(m3));
      for (int i = 0; i < vc.size(); ++i) {
        m3[vc[i]] += vc2[i];
        m3[vc1[i]] -= vc2[i];
      }
      vc.clear();
      vc1.clear();
      vc2.clear();
      vc3.clear();
      for (int i = 0; i < n; ++i) {
        m1[i] += m3[i];
        m3[i + 1] += m3[i];
      }
      li.clear();
      wh.clear();
      a = 0;
      for (int i = 0; i < n; ++i) {
        if (wh.find(m1[i]) == wh.end()) {
          wh[m1[i]] = a;
          ++a;
        }
      }
      li.resize(a);
      for (int i = 0; i < n; ++i) li[wh[m1[i]]].push_back(i);
      vc3.push_back(0);
      vc3.push_back(n);
    }
    cin >> a;
    if (a == 1) {
      cin >> b >> c >> d;
      vc.push_back(b - 1);
      vc1.push_back(c);
      vc3.push_back(b - 1);
      vc3.push_back(c);
      vc2.push_back(d);
    } else {
      cin >> a;
      memset(m2, 0, sizeof(m2));
      sort(vc3.begin(), vc3.end());
      for (int i = 0; i < vc.size(); ++i) {
        m2[lower_bound(vc3.begin(), vc3.end(), vc[i]) - vc3.begin()] += vc2[i];
        m2[lower_bound(vc3.begin(), vc3.end(), vc1[i]) - vc3.begin()] -= vc2[i];
      }
      b = (long long)1000000007, c = -(long long)1000000007;
      for (int i = 0; i + 1 < vc3.size(); ++i) {
        b = min(b, gmi(a - m2[i], vc3[i], vc3[i + 1]));
        c = max(c, gma(a - m2[i], vc3[i], vc3[i + 1]));
        m2[i + 1] += m2[i];
      }
      cout << max(c - b, -1ll) << '\n';
    }
  }
  return 0;
}
