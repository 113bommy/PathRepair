#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long MOD = 998244353;
double eps = 1e-12;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> arr(n);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int cnt = 0;
  queue<int> q;
  set<int> m;
  for (long long i = 0; i < n; i++) {
    if (cnt < k && m.find(arr[i]) == m.end()) {
      q.push(arr[i]);
      m.insert(arr[i]);
      cnt++;
    } else if (cnt == k && m.find(arr[i]) == m.end()) {
      m.erase(q.back());
      q.pop();
      q.push(arr[i]);
      m.insert(arr[i]);
    }
  }
  cout << cnt << "\n";
  vector<int> ans(q.size());
  int i = 0;
  while (!q.empty()) {
    ans[i++] = q.front();
    q.pop();
  }
  for (int i = ans.size() - 1; i >= 0; i--) {
    cout << ans[i] << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  for (int it = 1; it <= t; it++) {
    solve();
  }
  return 0;
}
