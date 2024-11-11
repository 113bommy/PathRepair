#include <bits/stdc++.h>
using namespace std;
long long n, m, mn[300005], mx[300005], a[300005], l, r, j, ans[300005], cnt,
    mp[300005];
map<long long, long long> tree;
vector<long long> v[300005];
vector<pair<long long, long long> > s;
void inc(int idx, int val) {
  for (int i = idx; i <= n; i += i & (-i)) {
    tree[i] += val;
  }
}
long long sum(int idx) {
  long long pas = 0;
  for (int i = idx; i > 0; i -= i & (-i)) {
    pas += tree[i];
  }
  return pas;
}
int main() {
  std::ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
    v[a[i]].push_back(i);
  }
  for (int i = 1; i <= m; i++) {
    if (!mp[a[i]]) v[a[i]].push_back(m + 1);
    mp[a[i]]++;
  }
  for (int i = 1; i <= 300000; i++) mp[i] = 0;
  for (int i = 1; i <= m; i++) {
    if (mp[a[i]]) continue;
    if (v[a[i]].size() >= 1) {
      l = v[a[i]][0] + 1;
      r = v[a[i]][1] - 1;
      s.push_back({r, l});
    }
    for (int j = 1; j < v[a[i]].size() - 1; j++) {
      l = v[a[i]][j] + 1;
      r = v[a[i]][j + 1] - 1;
      s.push_back({r, l});
    }
    mp[a[i]] = 1;
  }
  sort(s.begin(), s.end());
  j = 0;
  for (int i = 1; i <= m; i++) {
    if (mp[a[i]]) {
      inc(mp[a[i]], -1);
    }
    inc(i, 1);
    mp[a[i]] = i;
    while (j < s.size() && s[j].first == i) {
      r = i;
      l = s[j].second;
      ans[j] = sum(r) - sum(l - 1);
      j++;
    }
  }
  for (int i = 1; i <= 300000; i++) mp[i] = 0;
  tree.clear();
  for (int i = 1; i <= n; i++) {
    mn[i] = i;
    mx[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    mn[a[i]] = 1;
  }
  for (int i = 0; i < s.size(); i++) {
    mx[a[s[i].second - 1]] = max(mx[a[s[i].second - 1]], ans[i] + 1);
  }
  for (int i = 1; i <= m; i++) {
    if (!mp[a[i]]) inc(a[i], 1);
    mp[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    if (mp[i] == 0) {
      mx[i] = max(mx[i], i + sum(n) - sum(i));
    }
  }
  for (int i = 1; i <= 300000; i++) mp[i] = 0;
  tree.clear();
  for (int i = 1; i <= m; i++) {
    if (!mp[a[i]]) {
      cnt = sum(n) - sum(a[i]);
      mx[a[i]] = max(mx[a[i]], a[i] + cnt);
      inc(a[i], 1);
    }
    mp[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    cout << mn[i] << " " << mx[i] << endl;
  }
}
