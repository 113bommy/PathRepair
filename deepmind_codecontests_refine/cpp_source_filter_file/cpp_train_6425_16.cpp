#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> a[12], b[12];
bool bothSame(long long i, long long j) {
  if (a[i].first == b[j].first && a[i].second == b[j].second)
    return true;
  else
    return false;
}
bool bothDifferent(long long i, long long j) {
  if (a[i].first != b[j].first && a[i].first != b[j].second &&
      a[i].second != b[j].first && a[i].second != b[j].second)
    return true;
  else
    return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m;
  cin >> n >> m;
  long long x, y;
  long long f[10] = {0};
  for (long long i = 0; i < n; i++) {
    cin >> x >> y;
    if (x > y) swap(x, y);
    a[i].first = x;
    a[i].second = y;
  }
  for (long long i = 0; i < m; i++) {
    cin >> x >> y;
    if (x > y) swap(x, y);
    b[i].first = x;
    b[i].second = y;
  }
  set<long long> s1[n], s2[m];
  long long c;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (bothSame(i, j) || bothDifferent(i, j)) continue;
      if (a[i].first == b[j].first || a[i].first == b[j].second ||
          a[i].second == b[j].first || a[i].second == b[j].second) {
        if (a[i].first == b[j].first || a[i].first == b[j].second)
          c = a[i].first;
        if (a[i].second == b[j].first || a[i].second == b[j].second)
          c = a[i].second;
        s1[i].insert(c);
        s2[j].insert(c);
        f[c]++;
      }
    }
  }
  long long cnt = 0;
  for (long long i = 0; i < 10; i++)
    if (f[i] > 0) cnt++;
  if (cnt == 1) {
    cout << c;
    return 0;
  }
  long long a1 = 0, b1 = 0;
  for (long long i = 0; i < n; i++)
    if (s1[i].size() > 1) a1++;
  for (long long i = 0; i < n; i++)
    if (s2[i].size() > 1) b1++;
  if (!a1 && !b1)
    cout << 0;
  else
    cout << -1;
  return 0;
}
