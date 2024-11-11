#include <bits/stdc++.h>
using namespace std;
template <typename T, typename S>
inline bool REMIN(T& a, const S& b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T, typename S>
inline bool REMAX(T& a, const S& b) {
  return a < b ? a = b, 1 : 0;
}
bool compare2(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first <= b.first) return true;
  return false;
}
bool compare1(pair<pair<long long, long long>, long long> p1,
              pair<pair<long long, long long>, long long> p2) {
  if (p1.first.first <= p2.first.first) return true;
  return false;
}
int main() {
  vector<pair<long long, long long> > k[200050];
  int n, d;
  cin >> n >> d;
  vector<pair<pair<long long, long long>, long long> > v;
  int maxi = -1;
  for (int(i) = int(1); (i) <= int(n); ++(i)) {
    long long a, b, c;
    cin >> a >> b >> c;
    k[b - a + 1].push_back(make_pair(a, c));
    v.push_back(make_pair(make_pair(a, b), c));
    maxi = max((long long)maxi, b - a + 1);
  }
  sort(v.begin(), v.end());
  for (int(i) = int(1); (i) <= int(maxi); ++(i)) {
    sort(k[i].begin(), k[i].end());
    if (k[i].size() > 0) {
      long long mincost = k[i][k[i].size() - 1].second;
      for (int j = k[i].size() - 2; j >= 0; j--) {
        k[i][j].second = min(k[i][j].second, mincost);
        mincost = min(mincost, k[i][j].second);
      }
    }
  }
  bool check = false;
  long long ans = 1000000000006;
  for (int i = 0; i < v.size(); i++) {
    if (v[i].first.second - v[i].first.first + 1 >= d)
      continue;
    else {
      long long search = d - (v[i].first.second - v[i].first.first + 1);
      if (k[search].size() == 0)
        continue;
      else {
        long long tempans = 0;
        tempans = tempans + v[i].second;
        int f = lower_bound(k[search].begin(), k[search].end(),
                            make_pair(v[i].first.second + 1, 0), compare2) -
                k[search].begin();
        if (f != k[search].size()) {
          tempans += k[search][f].second;
          check = true;
          ans = min(ans, tempans);
        }
      }
    }
  }
  if (!check)
    cout << "-1\n";
  else
    cout << ans << "\n";
}
