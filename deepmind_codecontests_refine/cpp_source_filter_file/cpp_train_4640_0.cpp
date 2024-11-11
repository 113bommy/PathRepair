#include <bits/stdc++.h>
using namespace std;
int n, k, s, t;
vector<int> dst;
bool check(int m) {
  int cur = 0;
  for (int i = 0; i < dst.size(); i++) {
    if (dst[i] > m) {
      return false;
    } else {
      int tmp = m - dst[i];
      cur += min(dst[i], tmp);
      cur += max(0, dst[i] - tmp) * 2;
    }
  }
  return (cur <= t);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k >> s >> t;
  int c[n], v[n];
  for (int i = 0; i < n; i++) {
    cin >> c[i] >> v[i];
  }
  int g[k];
  for (int i = 0; i < k; i++) {
    cin >> g[i];
  }
  int mx = 0;
  sort(g, g + k);
  dst.push_back(g[0]);
  for (int i = 1; i < k; i++) {
    dst.push_back((g[i] - g[i - 1]));
    mx = max(mx, g[i] - g[i - 1]);
  }
  dst.push_back((s - g[k - 1]));
  sort((dst).begin(), (dst).end());
  int l = 0, r = 1e9 + 1;
  int rr = 1e9;
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      rr = min(rr, mid);
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  int ans = -1, m_c = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] >= rr) {
      if (ans == -1) {
        ans = i;
        m_c = c[i];
      } else if (c[i] < m_c) {
        m_c = c[i];
        ans = i;
      }
    }
  }
  if (ans == -1) {
    cout << -1;
  } else {
    cout << m_c;
  }
  return 0;
}
