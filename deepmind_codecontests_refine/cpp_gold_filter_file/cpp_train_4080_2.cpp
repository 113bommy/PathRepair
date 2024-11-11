#include <bits/stdc++.h>
using namespace std;
int n, k;
map<int, int> m;
string s;
long long ans;
bool flag;
void solve() {
  cin >> n;
  cin >> k;
  vector<int> a(n);
  int maxi = 0;
  for (auto i = 0; i < n; i++) cin >> a[i];
  ;
  for (auto i = 0; i < n; i++) {
    maxi = max(maxi, a[i]);
    m[a[i]]++;
    if (m[a[i]] >= k) {
      cout << 0;
      return;
    }
  }
  long long ans = INT_MAX;
  for (auto x = 1; x < 200000; x++) {
    queue<int> q;
    q.push(x);
    long long an = 0;
    int mul = 0;
    int K = 0;
    while (!q.empty() && K < k) {
      int N = q.size();
      while (N-- && K < k) {
        int y = q.front();
        q.pop();
        int count = m[y];
        if ((y * 2 - 1) < maxi) {
          q.push(y * 2);
          q.push(y * 2 + 1);
        }
        if (count > (k - K)) count = (k - K);
        an += count * mul;
        K += count;
      }
      mul++;
    }
    if (K == k) ans = min(an, ans);
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
