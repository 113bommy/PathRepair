#include <bits/stdc++.h>
using namespace std;
long long pre[65];
void init() {
  pre[0] = 1;
  for (int i = 1; i <= 60; i++) pre[i] = pre[i - 1] * 2;
}
long long get(string s) {
  long long res = 0;
  int k = 0;
  reverse(s.begin(), s.end());
  for (auto t : s) {
    if (t == '1') res += (1 << k);
    k++;
  }
  return res;
}
void solve() {
  int n, m;
  map<long long, int> p;
  cin >> m >> n;
  long long sum = pre[n];
  sum -= m;
  long long mid = (sum - 1) >> 1;
  while (m--) {
    string s;
    cin >> s;
    long long t = get(s);
    p[t] = 1;
    if (t <= mid) {
      while (1) {
        mid++;
        if (!p.count(mid)) break;
      }
    }
  }
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    ans.push_back(mid & 1);
    mid >>= 1;
  }
  reverse(ans.begin(), ans.end());
  for (auto k : ans) cout << k;
  cout << endl;
}
int main() {
  int T;
  cin >> T;
  init();
  while (T--) solve();
  return 0;
}
