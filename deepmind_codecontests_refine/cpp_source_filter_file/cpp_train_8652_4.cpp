#include <bits/stdc++.h>
using namespace std;
int n, k, v;
map<int, int> mp;
vector<int> a;
bool can(int mid) {
  int rem = 0;
  for (int i = 0; i < a.size(); i++) {
    if (mp[a[i]] >= mid) {
      rem += mp[a[i]] / mid;
    }
  }
  return rem >= k;
}
bool cmp(int s, int f) { return mp[s] > mp[f]; }
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> v;
    mp[v]++;
  }
  for (auto i : mp) {
    a.push_back(i.first);
  }
  sort(a.begin(), a.end(), cmp);
  int l, r, ans;
  l = 1, r = n;
  while (l < r) {
    int mid = (l + r) / 2;
    if (can(mid)) {
      l = mid + 1;
      ans = mid;
    } else {
      r = mid;
    }
  }
  n = a.size();
  for (int i = 0; i < n; i++) {
    if (k - mp[a[i]] / ans >= 0) {
      for (int j = 0; j < mp[a[i]] / ans; j++) cout << a[i] << " ";
      k -= mp[a[i]] / ans;
    } else {
      for (int j = 0; j < k; j++) cout << a[i] << " ";
      break;
    }
  }
}
