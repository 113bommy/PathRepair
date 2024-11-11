#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<pair<pair<int, int>, int>, pair<int, int> > > arr;
vector<int> ans;
bool cmp(const pair<pair<pair<int, int>, int>, pair<int, int> > &a,
         const pair<pair<pair<int, int>, int>, pair<int, int> > &b) {
  if (a.first.first.first != b.first.first.first) {
    return a.first.first.first < b.first.first.first;
  }
  if (!a.second.first && b.second.first) {
    return false;
  }
  if (a.second.first && !b.second.first) {
    return true;
  }
  return a.first.first.second < b.first.first.second;
}
void solve() {
  map<int, vector<pair<int, int> > > mp;
  set<int> st;
  for (int i = 0; i < arr.size(); ++i) {
    if (arr[i].second.first) {
      st.insert(arr[i].first.first.second);
      mp[arr[i].first.first.second].push_back(
          make_pair(arr[i].second.first, arr[i].second.second));
    } else {
      if (st.lower_bound(arr[i].first.first.second) != st.end()) {
        int d = *st.lower_bound(arr[i].first.first.second);
        ans[arr[i].second.second] = mp[d][0].second + 1;
        mp[d][0].first--;
        if (mp[d][0].first == 0) {
          mp[d].erase(mp[d].begin());
        }
        if (mp[d].size() == 0) {
          st.erase(st.find(d));
        }
      } else {
        printf("NO");
        exit(0);
      }
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    arr.push_back(make_pair(make_pair(make_pair(l, r), 1), make_pair(0, i)));
  }
  ans.resize(n, -1);
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    arr.push_back(make_pair(make_pair(make_pair(l, r), 1), make_pair(k, i)));
  }
  sort(arr.begin(), arr.end(), cmp);
  solve();
  printf("YES\n");
  for (int i = 0; i < n; ++i) {
    printf("%d ", ans[i]);
  }
  return 0;
}
