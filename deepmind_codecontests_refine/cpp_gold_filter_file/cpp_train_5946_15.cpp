#include <bits/stdc++.h>
using namespace std;
int n;
long long A[300005];
long long dp[300005];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i < n + 1; i++) {
    cin >> A[i];
  }
  int q;
  cin >> q;
  vector<pair<pair<int, int>, int> > vp;
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    vp.push_back(make_pair(make_pair(b, a), i));
  }
  vector<pair<int, long long> > lazy;
  sort(vp.begin(), vp.end());
  int t = sqrt(n);
  int lb = 0;
  for (auto x : vp) {
    int b = x.first.first;
    int a = x.first.second;
    int index = x.second;
    if (b > t) {
      long long ans = 0;
      for (int i = a; i <= n; i += b) ans += A[i];
      lazy.push_back(make_pair(index, ans));
    } else {
      if (lb != b) {
        for (int i = 1; i < n + 1; i++) dp[i] = 0;
        for (int i = n; i > 0; i--) {
          if (i + b <= n)
            dp[i] = A[i] + dp[i + b];
          else
            dp[i] = A[i];
        }
        lb = b;
      }
      lazy.push_back(make_pair(index, dp[a]));
    }
  }
  sort(lazy.begin(), lazy.end());
  for (auto x : lazy) cout << x.second << '\n';
}
