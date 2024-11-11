#include <bits/stdc++.h>
using namespace std;
long long N;
long long a[400005];
long long bt[400005];
void print(int n, int mx);
void printsubroutine(int n, int mxbit);
void update(long long idx, long long val) {
  if (idx == 0) {
    exit(-2);
  }
  while (idx <= N) {
    bt[idx] += val;
    idx += idx & (-idx);
  }
}
long long prefixsum(int r) {
  long long res = 0;
  while (r) {
    res += bt[r];
    r -= r & (-r);
  }
  return res;
}
long long pointquery(int i) { return prefixsum(i); }
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  N = n - 1;
  string second;
  cin >> second;
  int l = second.length();
  second = '@' + second;
  vector<int> mp[26];
  vector<int> mp2[26];
  int position[l];
  for (int i = 1; i < l + 1; i++) {
    mp[second[i] - 'a'].push_back(i);
    mp2[second[i] - 'a'].push_back(n + 1 - i);
  }
  for (int i = 0; i < 26; i++) {
    reverse(mp[i].begin(), mp[i].end());
    for (int x = 0; x < mp[i].size(); x++) {
      position[mp[i][x]] = mp2[i][x];
    }
  }
  long long ans = 0;
  vector<pair<int, int> > vp;
  for (int i = 1; i < n + 1; i++) {
    vp.push_back({-position[i], -i});
  }
  sort(vp.begin(), vp.end());
  for (auto x : vp) {
    int val = -x.first;
    int idx = -x.second;
    ans += pointquery(idx);
    update(idx, 1);
  }
  cout << ans << '\n';
  return 0;
}
