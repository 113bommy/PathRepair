#include <bits/stdc++.h>
const long long INF = 2 * 1e9;
const long long MOD = 1000000007;
using namespace std;
void solve() {
  long long n, k, m;
  cin >> n >> k >> m;
  vector<long long> a(n);
  vector<pair<long long, long long> > c;
  long long x;
  cin >> x;
  c.push_back({x, 1});
  long long cnt = 0;
  for (long long i = 1; i < n; i++) {
    long long x;
    cin >> x;
    if (c.size() == 0) {
      c.push_back({x, 1});
      continue;
    }
    if (x == c.back().first) {
      c[(long long)(c).size() - 1].second++;
      cnt += c[(long long)(c).size() - 1].second / k * k;
      c[(long long)(c).size() - 1].second %= k;
      if (c[(long long)(c).size() - 1].second == 0) c.pop_back();
    } else {
      c.push_back({x, 1});
    }
  }
  if ((long long)(c).size() == 0) {
    cout << 0 << '\n';
    return;
  }
  long long i = 0, j = (long long)(c).size() - 1;
  auto tmp = c;
  long long cnt1 = 0;
  while (1) {
    if (tmp[i].first == tmp[j].first) {
      if (i == j) break;
      cnt1 += (tmp[i].second + tmp[j].second) / k * k;
      if ((tmp[i].second + tmp[j].second) % k == 0) {
        i++;
        j--;
      } else
        break;
    } else {
      break;
    }
  }
  long long ans = 0;
  if (i == j && tmp[i].first == tmp[j].first) {
    long long cur = tmp[i].second * m;
    long long cnt2 = (cur / k) * k;
    cur %= k;
    ans += cnt * m + cnt1 * (m - 1) + cnt2;
    if (cur == 0) {
      i--;
      j++;
      while (i >= 0 && j < tmp.size()) {
        if (tmp[i].first == tmp[j].first) {
          ans += (tmp[i].second + tmp[j].second) / k * k;
          if ((tmp[i].second + tmp[j].second) % k == 0) {
            i--;
            j++;
          } else
            break;
        } else
          break;
      }
    }
  } else {
    ans += cnt * m + (cnt1) * (m - 1);
  }
  cout << n * m - ans << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.fixed;
  cout.precision(12);
  solve();
  return 0;
}
