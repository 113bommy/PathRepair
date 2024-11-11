#include <bits/stdc++.h>
std::mt19937_64 rng(
    std::chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
class convexHull {
 public:
  vector<pair<long long, long long> > lines;
  static bool intersect(pair<long long, long long> p1,
                        pair<long long, long long> p2,
                        pair<long long, long long> p3) {
    return (long double)(p1.second - p2.second) /
               (long double)(p2.first - p1.first) >
           (long double)(p1.second - p3.second) /
               (long double)(p3.first - p1.first);
  }
  void addLine(pair<long long, long long> newLine) {
    while (!lines.empty() and lines.back().first == newLine.first and
           lines.back().second <= newLine.second)
      lines.pop_back();
    while (
        (long long)lines.size() > 1LL and
        intersect(lines[(long long)lines.size() - 2LL], lines.back(), newLine))
      lines.pop_back();
    if (lines.empty() or lines.back().first != newLine.first)
      lines.push_back(newLine);
  }
  long long getMax(long long valx) {
    long long L = 0, R = (long long)lines.size() - 1, mid;
    long long maxi = LLONG_MIN;
    while (L <= R) {
      mid = (L + R) / 2;
      maxi = max(maxi, lines[mid].first * valx + lines[mid].second);
      if (mid + 1 <= R and
          lines[mid].first * valx + lines[mid].second >
              lines[mid + 1].first * valx + lines[mid + 1].second)
        R = mid;
      else if (mid + 1 <= R)
        L = mid + 1;
      else
        break;
    }
    return maxi;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> suf(n + 2, 0), v(n + 1, 0), pre(n + 2, 0);
    for (long long i = 1; i <= n; i++) cin >> v[i];
    for (long long i = n; i >= 1; i--) suf[i] += suf[i + 1] + v[i];
    long long ans = 0, tmp = 0;
    for (long long i = 1; i <= n; i++) tmp += v[i] * i;
    convexHull hull;
    ans = tmp;
    hull.addLine({-1, suf[1]});
    for (long long i = 2; i <= n; i++) {
      long long pp = hull.getMax(-1 * v[i]);
      pp = tmp - v[i] * (i + 1) + pp - suf[i + 1];
      ans = max(ans, pp);
      hull.addLine({-i, suf[i]});
    }
    convexHull hull2;
    for (long long i = 1; i <= n; i++) pre[i] += pre[i - 1] + v[i];
    hull2.addLine({n, -1 * pre[n]});
    for (long long i = n - 1; i >= 1; i--) {
      long long pp = hull2.getMax(v[i]);
      pp = tmp - v[i] * i + pp + pre[i];
      ans = max(ans, pp);
      hull2.addLine({i, -1 * pre[i]});
    }
    cout << ans;
  }
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
  return 0;
}
