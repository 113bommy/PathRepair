#include <bits/stdc++.h>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long>> pq1, pq2;
long long power(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    res *= a;
    b--;
  }
  return res;
}
long long n, m, l, h, mi, x, y, arr[200005], arr1[200005], st[200005] = {0},
                                                           tmp[200005] = {0};
vector<pair<long long, long long>> v;
vector<long long> w[200005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i < n + 1; ++i) {
    cin >> arr[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    v.push_back({x, y});
  }
  sort(v.begin(), v.end());
  l = 0;
  h = 200005;
  long long ans = -1;
  while (l <= h) {
    mi = (l + h) / 2;
    long long flag = -1;
    for (int j = 0; j < m; ++j) {
      long long a = v[j].first;
      long long b = v[j].second;
      if (a > mi)
        break;
      else {
        flag = j;
      }
    }
    long long tot = 0;
    for (int i = 1; i < n + 1; ++i) {
      arr1[i] = arr[i];
      tot += arr[i];
    }
    for (int j = flag; j >= 0; --j) {
      long long a = v[j].first;
      long long b = v[j].second;
      if (st[b] == 0) {
        w[a].push_back(b);
        st[b]++;
      }
    }
    long long cnt = 0;
    for (int i = 1; i < mi + 1; ++i) {
      cnt++;
      for (int j = 0; j < w[i].size(); ++j) {
        long long c = w[i][j];
        if (arr1[c] > 0) {
          long long fl = min(cnt, arr1[c]);
          arr1[c] -= fl;
          cnt -= fl;
          tot -= fl;
        }
      }
    }
    if (cnt >= 2 * tot) {
      ans = mi;
      h = mi - 1;
    } else {
      l = mi + 1;
    }
    for (long long i = 0; i <= 200005; i++) {
      w[i].clear();
      st[i] = 0;
    }
  }
  cout << ans << endl;
  return 0;
}
