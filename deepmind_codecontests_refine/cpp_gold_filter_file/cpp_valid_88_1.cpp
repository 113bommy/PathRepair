#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
bool cmp2(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first < b.first) return true;
  if (a.first == b.first) {
    if (a.second > b.second) {
      return true;
    }
  }
  return false;
}
bool cmp1(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first < b.first) return true;
  if (a.first == b.first) {
    if (a.second < b.second) {
      return true;
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long a, b, c, t, d, n, ans, e, i, x, temp, s, k, temp2, m, j;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<pair<long long, long long>> arr;
    temp = n * m;
    for (i = 0; i < temp; i++) {
      cin >> x;
      arr.push_back({x, i + 1});
    }
    sort(arr.begin(), arr.end());
    vector<vector<pair<long long, long long>>> mat(n);
    map<long long, pair<long long, long long>> mp;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        mat[i].push_back({arr[(i * m) + j].first, arr[(i * m) + j].second});
      }
    }
    for (i = 0; i < m; i++) {
      vector<pair<long long, long long>> temp2;
      for (j = 0; j < n; j++) {
        temp2.push_back({mat[j][i].first, mat[j][i].second});
      }
      sort(temp2.begin(), temp2.end(), cmp1);
      for (j = 0; j < n; j++) {
        mat[j][i] = temp2[j];
      }
    }
    for (i = 0; i < n; i++) sort(mat[i].begin(), mat[i].end(), cmp2);
    vector<set<long long>> v;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        mp[mat[i][j].second] = make_pair(i + 1, j + 1);
      }
    }
    for (i = 0; i < n; i++) {
      set<long long> ss;
      ss.insert(0);
      v.push_back(ss);
    }
    ans = 0;
    pair<long long, long long> h;
    for (auto k : mp) {
      h = k.second;
      auto l = v[h.first - 1].lower_bound(h.second);
      if (l != v[h.first - 1].end()) {
        j = distance(v[h.first - 1].begin(), l);
        j--;
        ans += j;
      } else {
        j = v[h.first - 1].size() - 1;
        ans += j;
      }
      v[h.first - 1].insert(h.second);
    }
    cout << ans << "\n";
  }
  return 0;
}
