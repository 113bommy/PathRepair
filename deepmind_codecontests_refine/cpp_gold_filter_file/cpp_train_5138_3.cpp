#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 1, 0, 0, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0, 0, 0};
const long long inf = 100000007;
const double eps = 0.000000009;
long long mod = 1000000007;
map<char, int> m;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long k1, a1, x1, y1, m1;
  cin >> k1 >> a1 >> x1 >> y1 >> m1;
  long long k2, a2, x2, y2, m2;
  cin >> k2 >> a2 >> x2 >> y2 >> m2;
  long long a[k1], b[k2];
  a[0] = a1;
  b[0] = a2;
  for (int i = 1; i < k1; i++) {
    a[i] = (a[i - 1] * x1 + y1) % m1;
  }
  for (int i = 1; i < k2; i++) {
    b[i] = (b[i - 1] * x2 + y2) % m2;
  }
  vector<pair<long long, long long> > sol;
  long long p1 = 0, p2 = 0;
  while (p1 < k1 && p2 < k2) {
    if (a[p1] < b[p2]) {
      if (sol.size() == 0) {
        sol.push_back(make_pair(a[p1], 1));
        p1++;
        continue;
      }
      if (a[p1] >= sol[sol.size() - 1].first ||
          (sol.size() > 0 && b[p2] < sol[sol.size() - 1].first)) {
        sol.push_back(make_pair(a[p1], 1));
        p1++;
      } else {
        sol.push_back(make_pair(b[p2], 2));
        p2++;
      }
    } else {
      if (sol.size() == 0) {
        sol.push_back(make_pair(b[p2], 2));
        p2++;
        continue;
      }
      if (b[p2] >= sol[sol.size() - 1].first ||
          ((sol.size() > 0) && a[p1] < sol[sol.size() - 1].first)) {
        sol.push_back(make_pair(b[p2], 2));
        p2++;
      } else {
        sol.push_back(make_pair(a[p1], 1));
        p1++;
      }
    }
  }
  while (p1 < k1) {
    sol.push_back(make_pair(a[p1], 1));
    p1++;
  }
  while (p2 < k2) {
    sol.push_back(make_pair(b[p2], 2));
    p2++;
  }
  long long ans = 0;
  for (int i = 1; i < k1 + k2; i++) {
    if (sol[i - 1].first > sol[i].first) {
      ans++;
    }
  }
  cout << ans << endl;
  for (int i = 0; i < k1 + k2; i++)
    cout << sol[i].first << " " << sol[i].second << endl;
  return 0;
}
