#include <bits/stdc++.h>
using namespace std;
int n, k;
const int N = 100005;
pair<pair<long long, long long>, long long> x[N];
int main() {
  cin >> n >> k;
  for (int(i) = (0); i < (n); ++(i)) {
    long long x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x[i].first.first = x1 + x2;
    x[i].first.second = y1 + y2;
    x[i].second = i;
  }
  vector<pair<long long, int> > hor, ver;
  for (int(i) = (0); i < (n); ++(i)) {
    hor.push_back({x[i].first.first, x[i].second});
    ver.push_back({x[i].first.second, x[i].second});
  }
  sort(hor.begin(), hor.end());
  sort(ver.begin(), ver.end());
  long long ans = 1000000001 * 1ll * 1000000001 * 9;
  int kk = k + 2;
  set<int> out;
  for (int(ll) = (0); ll < (kk); ++(ll)) {
    for (int(uu) = (0); uu < (kk); ++(uu)) {
      for (int(rr) = (0); rr < (kk); ++(rr)) {
        for (int(dd) = (0); dd < (kk); ++(dd)) {
          out.clear();
          for (int(i) = (0); i < (ll); ++(i)) out.insert(hor[i].second);
          for (int(i) = (n - rr); i < (n); ++(i)) out.insert(hor[i].second);
          for (int(i) = (0); i < (dd); ++(i)) out.insert(ver[i].second);
          for (int(i) = (n - uu); i < (n); ++(i)) out.insert(ver[i].second);
          if (out.size() > k) continue;
          long long l = hor[ll].first;
          long long r = hor[n - 1 - rr].first;
          long long u = ver[n - 1 - uu].first;
          long long d = ver[dd].first;
          long long sq = max(1ll, (r - l + 1) / 2) * max(1ll, (u - d + 1) / 2);
          ans = min(ans, sq);
        }
      }
    }
  }
  if (ans == 0) ans = 1;
  cout << (ans);
  return 0;
}
