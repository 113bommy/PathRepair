#include <bits/stdc++.h>
using namespace std;
long long mintoremove(long long l, long long r, vector<long long> &a,
                      long long x, long long k, long long y) {
  long long leftbound = (l > 0 ? a[l - 1] : 0);
  long long rightbound = (r < a.size() - 1 ? a[r + 1] : 0);
  bool solution = false;
  long long mincost = -1;
  long long maxrm = *max_element(a.begin() + l, a.begin() + r + 1);
  if (leftbound > maxrm || rightbound > maxrm) {
    solution = true;
    mincost = (r - l + 1) * y;
  }
  long long size = (r - l + 1);
  long long j = size / k;
  if (size < k) {
    return mincost;
  }
  long long minkcost = min(x, k * y);
  long long cost = minkcost * j + ((size % k) * y) - minkcost + x;
  if (mincost == -1) {
    mincost = cost;
  }
  mincost = min(mincost, cost);
  return mincost;
}
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  long long n, m;
  cin >> n >> m;
  long long x, k, y;
  cin >> x >> k >> y;
  vector<long long> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  if (m > n) {
    cout << "-1\n";
    return 0;
  }
  if (n == m) {
    if (a == b) {
      cout << "0\n";
    } else {
      cout << "-1\n";
    }
    return 0;
  }
  vector<pair<long long, long long> > segments;
  int j = 0;
  bool subsegment = false;
  long long l = 0;
  bool segm = false;
  for (int i = 0; i < n; i++) {
    if (j < b.size() && a[i] == b[j]) {
      if (segm) {
        segments.push_back({l, i - 1});
        segm = false;
      }
      j++;
      if (j == b.size()) {
        subsegment = true;
      }
    } else {
      if (!segm) {
        l = i;
        segm = true;
      }
    }
  }
  if (segm) {
    segments.push_back({l, a.size() - 1});
  }
  if (!subsegment) {
    cout << "-1\n";
    return 0;
  }
  long long res = 0;
  for (int s = 0; s < segments.size(); s++) {
    long long cost =
        mintoremove(segments[s].first, segments[s].second, a, x, k, y);
    if (cost == -1) {
      cout << "-1\n";
      return 0;
    }
    res += cost;
  }
  cout << res << "\n";
  return 0;
}
