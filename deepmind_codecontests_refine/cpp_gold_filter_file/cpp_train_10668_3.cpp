#include <bits/stdc++.h>
using namespace std;
map<long long, int> cnt[2][26];
int bs[(1 << 13)];
long long sum[(1 << 13)];
long long sumfact[(1 << 13)];
long long prefact[19];
void solve(int id, vector<int> s) {
  int sz = s.size();
  sum[0] = sumfact[0] = 0;
  for (int mask = 1; mask < (1 << sz); mask++) {
    int j = (mask & 1 ? 0 : bs[mask >> 1] + 1);
    bs[mask] = j;
    sum[mask] = sum[mask - (1 << j)] + s[j];
    if (cnt[id][0].find(sum[mask]) == cnt[id][0].end())
      cnt[id][0][sum[mask]] = 0;
    cnt[id][0][sum[mask]]++;
  }
  for (int mask = 1; mask < (1 << sz); mask++) {
    int submask = mask;
    while (submask > 0) {
      int j = (submask & 1 ? 0 : bs[submask >> 1] + 1);
      if (s[j] >= 19) {
        submask = mask & (submask - 1);
        continue;
      }
      sumfact[submask] = sumfact[submask - (1 << j)] + prefact[s[j]];
      long long vlr = sumfact[submask] + sum[mask ^ submask];
      int k = __builtin_popcount(submask);
      if (cnt[id][k].find(vlr) == cnt[id][k].end()) cnt[id][k][vlr] = 0;
      cnt[id][k][vlr]++;
      submask = mask & (submask - 1);
    }
  }
}
int main() {
  prefact[0] = 1;
  for (long long i = 1; i < 19; i++) {
    prefact[i] = i * prefact[i - 1];
  }
  int n, k;
  long long s;
  cin >> n >> k >> s;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  solve(0, vector<int>(a.begin(), a.begin() + n / 2));
  solve(1, vector<int>(a.begin() + n / 2, a.end()));
  long long ans = 0;
  for (int i = 0; i <= k; i++) {
    for (map<long long, int>::iterator it = cnt[0][i].begin();
         it != cnt[0][i].end(); it++) {
      long long cs = s - it->first;
      if (cs == 0) {
        ans += it->second;
        continue;
      }
      for (int j = 0; j <= k - i; j++) {
        if (cnt[1][j].find(cs) != cnt[1][j].end()) {
          ans += cnt[1][j][cs] * ((long long)it->second);
        }
      }
    }
  }
  for (int i = 0; i <= k; i++) {
    if (cnt[1][i].find(s) != cnt[1][i].end()) ans += cnt[1][i][s];
  }
  cout << ans << endl;
  return 0;
}
