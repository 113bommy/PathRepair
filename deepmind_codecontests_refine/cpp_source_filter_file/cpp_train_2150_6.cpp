#include <bits/stdc++.h>
using namespace std;
long long ans = 0;
long long max(long long a, long long b) {
  if (a > b) {
    return a;
  }
  return b;
}
void solve(vector<pair<long long, long long> > x) {
  multiset<long long> a, b;
  for (long long i = 0; i < x.size(); i++) {
    b.insert(x[i].second);
  }
  long long l = 0;
  for (long long i = 0; i <= 2000000; i++) {
    while (l < x.size() && x[l].first <= i) {
      b.erase(b.find(x[l].second));
      a.insert(x[l].second);
      l++;
    }
    long long t1 = 1e5;
    if (a.size() != 0) {
      t1 = *a.begin();
    }
    long long t2 = 1e5;
    if (b.size() != 0) {
      t2 = *b.begin();
    }
    long long t3 = -1e5;
    if (a.size() != 0) {
      t3 = *a.rbegin();
    }
    long long t4 = -1e5;
    if (b.size() != 0) {
      t4 = *b.rbegin();
    }
    ans += max(0, min(t3, t4) - max(t1, t2));
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  vector<pair<long long, long long> > a, b;
  for (long long i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    x += 1e5;
    y += 1e5;
    if ((x + y) % 2 == 0) {
      a.push_back({(x + y) / 2, (x - y + 100000) / 2});
    } else {
      b.push_back({(x + y) / 2, (x - y + 100000) / 2});
    }
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  solve(a);
  solve(b);
  cout << ans;
  return 0;
}
