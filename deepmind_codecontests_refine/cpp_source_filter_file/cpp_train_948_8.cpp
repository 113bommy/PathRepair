#include <bits/stdc++.h>
using namespace std;
long long n, m, last[100005], need[100005], ss[100005];
vector<pair<pair<long long, long long>, long long> > ans;
pair<long long, long long> size_[100005];
set<long long> ls;
vector<long long> vr[100005];
int main() {
  long long tot = 0;
  scanf("%lld %lld", &n, &m);
  for (int i = 1; i < n + 1; i++) {
    long long x, y;
    scanf("%lld", &x);
    for (int j = 0; j < x; j++) {
      scanf("%lld", &y);
      vr[y].push_back(i);
    }
    ss[i] = x;
    size_[i] = make_pair(x, i);
    tot += x;
  }
  long long ones = tot % n;
  sort(size_ + 1, size_ + 1 + n, greater<pair<long long, long long> >());
  for (int i = 1; i < n + 1; i++) {
    long long idx = size_[i].second, val = size_[i].first;
    need[idx] = tot / n + (i <= ones);
  }
  for (int i = 1; i < n + 1; i++)
    if (ss[i] < need[i]) ls.insert(i);
  for (int i = 1; i < m + 1; i++) {
    vector<long long> temp, ers;
    for (auto itr = vr[i].begin(); itr != vr[i].end(); itr++) {
      long long idx = *itr;
      if (ss[idx] > need[i]) {
        temp.push_back(idx);
      }
      last[idx] = i;
    }
    for (auto itr = ls.begin(); (itr != ls.end()) && temp.size(); itr++) {
      long long idx = *itr;
      if (last[idx] != i) {
        ss[idx]++;
        ss[*temp.rbegin()]--;
        if (ss[idx] == need[idx]) ers.push_back(idx);
        ans.push_back(make_pair(make_pair(*temp.rbegin(), idx), i));
        temp.pop_back();
      }
    }
    while (ers.size()) {
      ls.erase(*ers.rbegin());
      ers.pop_back();
    }
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i].first.first << " " << ans[i].first.second << " "
         << ans[i].second << "\n";
}
