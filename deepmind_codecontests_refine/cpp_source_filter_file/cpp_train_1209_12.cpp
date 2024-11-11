#include <bits/stdc++.h>
using namespace std;
vector<int> mul(vector<int> const& a, vector<int> const& b) {
  vector<int> c;
  size_t k = 0, z = 0;
  while (k < a.size() && z < b.size()) {
    if (a[k] < b[z]) {
      c.push_back(a[k]);
      k++;
    } else {
      c.push_back(b[z]);
      z++;
    }
  }
  while (k < a.size()) {
    c.push_back(a[k]);
    k++;
  }
  while (z < b.size()) {
    c.push_back(b[z]);
    z++;
  }
  return c;
}
struct SegmentTree {
  SegmentTree(int n, const vector<vector<int>>& a) {
    v.resize(2 * n + 1, inf);
    build(1, 0, n - 1, a);
  }
  void build(int u, int l, int r, const vector<vector<int>>& a) {
    if (l == r) {
      if (r < (int)a.size()) v[u] = a[l];
      return;
    }
    int m = (l + r) / 2;
    build(u * 2, l, m, a);
    build(u * 2 + 1, m + 1, r, a);
    v[u] = mul(v[u * 2], v[u * 2 + 1]);
  }
  vector<int> get(int u, int L, int R, int l, int r) {
    if (L > r || R < l) return inf;
    if (L >= l && R <= r) {
      return v[u];
    }
    int m = (L + R) / 2;
    return mul(get(u * 2, L, m, l, r), get(u * 2 + 1, m + 1, R, l, r));
  }
  vector<int> inf;
  vector<vector<int>> v;
};
unsigned int a, b;
unsigned int cur = 0;
unsigned int nextRand17() {
  cur = cur * a + b;
  return cur >> 15;
}
unsigned int nextRand24() {
  cur = cur * a + b;
  return cur >> 8;
}
const int P = 450;
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  int la = a.first.first / P;
  int lb = b.first.first / P;
  if (lb != la) {
    return la < lb;
  }
  return a.first.second < b.first.second;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  vector<pair<pair<int, int>, int>> q;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    q.push_back(make_pair(make_pair(a, b), i));
  }
  sort(q.begin(), q.end(), cmp);
  vector<int> ans(m);
  vector<int> tmp(1e6 + 10);
  int l = 0, r = 0;
  tmp[v[0]]++;
  long long sum = v[0];
  for (int i = 0; i < m; ++i) {
    int l1 = q[i].first.first;
    int r1 = q[i].first.second;
    if (r < r1) {
      for (; r < r1;) {
        r++;
        sum -= ((long long)tmp[v[r]] * tmp[v[r]] * (long long)v[r]);
        tmp[v[r]]++;
        sum += ((long long)tmp[v[r]] * tmp[v[r]] * (long long)v[r]);
      }
    } else {
      for (; r > r1;) {
        sum -= ((long long)tmp[v[r]] * tmp[v[r]] * (long long)v[r]);
        tmp[v[r]]--;
        sum += ((long long)tmp[v[r]] * tmp[v[r]] * (long long)v[r]);
        r--;
      }
    }
    if (l < l1) {
      for (; l < l1;) {
        sum -= ((long long)tmp[v[l]] * tmp[v[l]] * (long long)v[l]);
        tmp[v[l]]--;
        sum += ((long long)tmp[v[l]] * tmp[v[l]] * (long long)v[l]);
        l++;
      }
    } else {
      for (; l > l1;) {
        l--;
        sum -= ((long long)tmp[v[l]] * tmp[v[l]] * (long long)v[l]);
        tmp[v[l]]++;
        sum += ((long long)tmp[v[l]] * tmp[v[l]] * (long long)v[l]);
      }
    }
    ans[q[i].second] = sum;
  }
  for (size_t i = 0; i < ans.size(); ++i) {
    cout << ans[i] << "\n";
  }
  return 0;
}
