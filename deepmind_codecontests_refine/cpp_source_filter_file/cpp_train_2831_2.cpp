#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const long long MD = 1e9 + 7;
const double pi = acos(-1);
struct segmentTree {
  int tl = 1, tr = (1ll << 19);
  segmentTree* left = nullptr;
  segmentTree* right = nullptr;
  int val = 0;
  int push = 0;
  segmentTree(int tl, int tr) : tl(tl), tr(tr) {}
  segmentTree() = default;
  void createSons() {
    int tm = (tl + tr) / 2;
    if (!left) {
      left = new segmentTree(tl, tm);
    }
    if (!right) {
      right = new segmentTree(tm + 1, tr);
    }
  }
  void doPush() {
    createSons();
    if (push) {
      left->push += push;
      right->push += push;
      val += push;
      push = 0;
    }
  }
  void update(int l, int r, int val) {
    doPush();
    if (l > r) {
      return;
    }
    if (tl == l && r == tr) {
      push += val;
      doPush();
      return;
    }
    createSons();
    int tm = (tl + tr) / 2;
    left->update(l, min(r, tm), val);
    right->update(max(tm + 1, l), r, val);
    this->val = max(left->val, right->val);
  }
  int get(int l, int r) {
    doPush();
    if (l > r) {
      return 0;
    }
    if (l == tl && tr == r) {
      return val;
    }
    int tm = (tl + tr) / 2;
    return max(left->get(l, min(r, tm)), right->get(max(tm + 1, l), r));
  }
};
ostream& operator<<(ostream& stream, const vector<int>& v) {
  for (auto i : v) {
    stream << i << " ";
  }
  return stream;
}
pair<int, int> operator+=(pair<int, int>& a, const pair<int, int>& b) {
  a.first += b.first;
  a.second += b.second;
  return a;
};
int sqr(int a) { return a * a % MD; }
int binpow(int a, int b) {
  if (b == 0) {
    return 1;
  }
  if (b % 2 == 0) {
    return sqr(binpow(a, b / 2));
  }
  return a * binpow(a, b - 1) % MD;
}
int fact(int a) {
  int res = 1;
  for (int i = 2; i <= a; i++) {
    res *= i;
    res %= MD;
  }
  return res;
}
int dp[(1ll << 20)];
int cnt[30][30];
int n, m;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  string st;
  cin >> st;
  for (int i = 0; i < (int)st.size() - 1; i++) {
    cnt[st[i] - 'a'][st[i + 1] - 'a']++;
    cnt[st[i + 1] - 'a'][st[i] - 'a']++;
  }
  for (int mask = 0; mask < (1 << 20); mask++) {
    dp[mask] = INF;
  }
  dp[0] = 0;
  for (int mask = 0; mask < (1 << 20); mask++) {
    if (dp[mask] == INF) {
      continue;
    }
    vector<int> zeros;
    for (int j = 0; j < m; j++) {
      if (mask & (1 << j)) {
      } else {
        zeros.push_back(j);
      }
    }
    for (auto& let : zeros) {
      int toAdd = 0;
      for (int j = 0; j < m; j++) {
        if (j == let) {
          continue;
        }
        if (mask & (1 << j)) {
          toAdd += cnt[j][let];
        } else {
          toAdd -= cnt[j][let];
        }
      }
      toAdd *= 20 - zeros.size();
      int newMask = mask | (1 << let);
      dp[newMask] = min(dp[newMask], dp[mask] + toAdd);
    }
  }
  cout << dp[(1 << m) - 1] << "\n";
}
