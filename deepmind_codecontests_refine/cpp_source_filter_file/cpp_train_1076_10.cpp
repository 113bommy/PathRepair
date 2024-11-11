#include <bits/stdc++.h>
const double pi = acos(-1.0);
const double eps = 1e-9;
using namespace std;
struct SuffArray {
  int n;
  vector<vector<int>> classes;
  vector<int> cnt, p, pn, cn, c, rank;
  vector<int> v;
  SuffArray(vector<int> vec = {})
      : n(vec.size()),
        p(n),
        cnt(max(100001, n)),
        c(n),
        pn(n),
        cn(n),
        rank(n),
        v(vec) {}
  vector<int> Build_Suff() {
    int mn = 0;
    for (int i = 0; i < n; i++) mn = min(mn, v[i]);
    for (int i = 0; i < n; i++) {
      c[i] = cn[i] = v[i] - mn + 1;
      p[i] = pn[i] = i;
    }
    for (int step = 1; step <= 2 * n; step *= 2) {
      fill(cnt.begin(), cnt.end(), 0);
      for (int i = 0; i < n; i++) ++cnt[c[pn[i]]];
      for (int i = 1; i < max(n, 100001); i++) cnt[i] += cnt[i - 1];
      for (int i = n - 1; i >= 0; i--) p[--cnt[c[pn[i]]]] = pn[i];
      cn[p[0]] = 0;
      for (int i = 1; i < n; i++) {
        int mid1 = (p[i] + step / 2) % n;
        int mid2 = (p[i - 1] + step / 2) % n;
        cn[p[i]] = cn[p[i - 1]];
        if (c[p[i]] != c[p[i - 1]] || c[mid1] != c[mid2]) cn[p[i]]++;
      }
      classes.push_back(cn);
      swap(c, cn);
      for (int i = 0; i < n; i++) pn[i] = (p[i] + n - step) % n;
    }
    for (int i = 0; i < n; i++) rank[p[i]] = i;
    return p;
  }
  int Get_Lcp(int i, int j) {
    if (i == j) return n - i - 1;
    int ans = 0;
    for (int step = classes.size() - 1; step >= 0; step--) {
      if (classes[step][i] == classes[step][j]) {
        i = (i + (1 << step)) % n;
        j = (j + (1 << step)) % n;
        ans += (1 << step);
      }
    }
    return min(ans, n);
    return min(ans, n);
  }
} vec_array;
const int N = 1e5 + 10;
int n, cntId;
unordered_map<int, int> id, id1;
vector<int> where[N];
void solve() {
  cin >> n;
  vector<int> v(n), u(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  u = v;
  sort((u).begin(), (u).end());
  for (int i = 0; i < u.size(); i++) {
    if (!id.count(u[i])) {
      id[u[i]] = ++cntId;
    }
  }
  for (auto x : id) {
    id1[x.second] = x.first;
  }
  for (int& x : v) {
    x = id[x];
  }
  for (int i = 0; i < n; i++) {
    where[v[i]].push_back(i);
  }
  v.push_back(0);
  vec_array = SuffArray(v);
  vec_array.Build_Suff();
  vector<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    for (int j : where[v[i]]) {
      if (j <= i) {
        continue;
      }
      q.push_back({j - i, i});
    }
  }
  sort((q).begin(), (q).end());
  int lastId = 0;
  for (auto otr : q) {
    if (otr.second < lastId) {
      continue;
    }
    if (vec_array.Get_Lcp(otr.second, otr.second + otr.first) == otr.first) {
      lastId = otr.second + otr.first;
      continue;
    }
  }
  cout << n - lastId << endl;
  for (int i = lastId; i < n; i++) {
    cout << id1[v[i]] << " ";
  }
}
int main() {
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed), cout.precision(7);
  int step = 1;
  for (int i = 1; i <= step; i++) {
    solve();
  }
}
