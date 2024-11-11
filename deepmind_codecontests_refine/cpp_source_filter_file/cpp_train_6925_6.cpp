#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 200333;
const int INF = 1e9 + 47;
const pair<int, int> INF_PAIR = {INF, INF};
pair<int, int> a[MAX_N];
int sz;
int d, vol, m;
pair<int, int> f[MAX_N * 4];
pair<int, int> getMin(int v, int tl, int tr, const int& l, const int& r) {
  if (tl > r || l > tr) {
    return INF_PAIR;
  }
  if (l <= tl && r >= tr) {
    return f[v];
  }
  int c = (tl + tr) / 2;
  return min(getMin(v * 2, tl, c, l, r), getMin(v * 2 + 1, c + 1, tr, l, r));
}
int nxt[MAX_N];
int n;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> d >> vol >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  a[n + 1] = {0, 0};
  a[n + 2] = {d, 0};
  n += 2;
  sort(a + 1, a + n + 1);
  sz = 1;
  while (sz < n) {
    sz *= 2;
  }
  for (int i = 1; i <= n; i++) {
    f[i + sz - 1] = {a[i].second, i};
  }
  for (int i = sz - 1; i > 0; i--) {
    f[i] = min(f[i * 2], f[i * 2 + 1]);
  }
  vector<pair<int, int>> st;
  for (int i = n; i > 0; i--) {
    while (!st.empty() && st.back().second > a[i].second) {
      st.pop_back();
    }
    if (st.empty()) {
      nxt[i] = -1;
    } else {
      nxt[i] = st.back().first;
    }
    st.push_back({i, a[i].second});
  }
  int curVol = vol, p = 1;
  long long ans = 0;
  while (true) {
    if (a[p].first + curVol >= d) {
      cout << ans << "\n";
      return 0;
    }
    if (nxt[p] == -1 || a[nxt[p]].first - a[p].first > curVol) {
      if (nxt[p] != -1 && a[nxt[p]].first - a[p].first <= vol) {
        ans += (long long)a[p].second * (a[nxt[p]].first - a[p].first - curVol);
        curVol = 0;
        p = nxt[p];
        continue;
      }
      int l = p, r = n + 1;
      while (l + 1 < r) {
        int c = (l + r) / 2;
        if (a[c].first <= a[p].first + curVol) {
          l = c;
        } else {
          r = c;
        }
      }
      if (p == l) {
        cout << "-1\n";
        return 0;
      }
      ans += (long long)a[p].second * (vol - curVol);
      pair<int, int> np = getMin(1, 1, sz, p + 1, l);
      curVol = vol - (a[np.second].first - a[p].first);
      p = np.second;
      continue;
    } else {
      curVol -= a[nxt[p]].first - a[p].first;
      p = nxt[p];
      continue;
    }
  }
  cout << "-1\n";
  return 0;
}
