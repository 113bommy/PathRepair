#include <bits/stdc++.h>
using namespace std;
struct bit {
  long long n;
  vector<long long> arr;
  bit(long long _n) : n(_n) { arr.assign(n + 5, 0); }
  void add(long long x) {
    while (x <= n) arr[x]++, x += x & -x;
  }
  long long get(long long x) {
    long long re = 0;
    while (x) re += arr[x], x -= x & -x;
    return re;
  }
};
unordered_map<long long, long long> ans[200005];
long long x[200005], y[200005], z[200005], t[200005];
vector<long long> pt[200005];
vector<long long> p[200005];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, q;
  cin >> n >> q;
  for (long long i = 1; i <= n; i++) {
    long long x, y = i;
    cin >> x;
    pt[x].emplace_back(y);
  }
  for (long long i = 1; i <= q; i++) {
    cin >> y[i] >> x[i] >> t[i] >> z[i];
    x[i]--;
    y[i]--;
    p[x[i]].emplace_back(y[i]);
    p[x[i]].emplace_back(t[i]);
    p[x[i]].emplace_back(n);
    p[z[i]].emplace_back(y[i]);
    p[z[i]].emplace_back(t[i]);
    p[z[i]].emplace_back(n);
    p[n].emplace_back(y[i]);
    p[n].emplace_back(t[i]);
    p[n].emplace_back(n);
  }
  bit v = bit(n);
  for (long long i = 1; i <= n; i++) {
    for (auto id : pt[i]) v.add(id);
    for (auto range : p[i]) ans[i][range] = v.get(range);
  }
  for (long long T = 1; T <= q; T++) {
    vector<vector<long long> > p(4, vector<long long>(4));
    vector<long long> idx = {0, x[T], z[T], n};
    vector<long long> idy = {0, y[T], t[T], n};
    for (long long i = 1; i <= 3; i++)
      for (long long j = 1; j <= 3; j++) {
        p[i][j] = ans[idx[i]][idy[j]];
      }
    for (long long i = 3; i >= 1; i--)
      for (long long j = 3; j >= 1; j--)
        p[i][j] = p[i][j] - p[i - 1][j] - p[i][j - 1] + p[i - 1][j - 1];
    long long temp1 = p[1][1] + p[1][2] + p[1][3],
              temp2 = p[1][1] + p[2][1] + p[3][1],
              temp3 = p[3][1] + p[3][2] + p[3][3],
              temp4 = p[1][3] + p[2][3] + p[3][3];
    long long t1 = p[1][1], t2 = p[1][3], t3 = p[3][1], t4 = p[3][3];
    long long re = temp1 * (temp1 - 1) / 2 + temp2 * (temp2 - 1) / 2 +
                   temp3 * (temp3 - 1) / 2 + temp4 * (temp4 - 1) / 2;
    re -= t1 * (t1 - 1) / 2 + t2 * (t2 - 1) / 2 + t3 * (t3 - 1) / 2 +
          t4 * (t4 - 1) / 2;
    cout << n * (n - 1) / 2 - re << endl;
  }
}
