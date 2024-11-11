#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 11;
int a[N];
vector<pair<long long, long long> > v[N];
vector<bool> dp[N];
vector<int> pr[N];
inline bool good(long long x, long long y) {
  if (x >= y) return false;
  long long p = y - x;
  long long c = x + p;
  long long d = sqrt(c);
  if (d * d == c) return true;
  return false;
}
inline long long get(long long x, long long y) { return y - x; }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n / 2; i++) {
    cin >> a[i];
    for (int p = 1; p <= (int)sqrt(a[i]); p++)
      if (a[i] % p == 0) {
        int t1 = p;
        int t2 = a[i] / p;
        if ((t2 + t1) % 2 == 0 && (t2 - t1) % 2 == 0 && t2 - t1 > 0)
          v[i].push_back(make_pair((t2 - t1) / 2, (t2 + t1) / 2));
      }
    for (int j = 0; j < v[i].size(); j++) {
      v[i][j].first = v[i][j].first * v[i][j].first;
      v[i][j].second = v[i][j].second * v[i][j].second;
    }
  }
  for (int j = 0; j < v[1].size(); j++) {
    dp[1].push_back(1);
    pr[1].push_back(0);
  }
  for (int i = 2; i <= n / 2; i++) {
    for (int j = 0; j < v[i].size(); j++) {
      int x = 0, prr = 0;
      for (int t = 0; t < v[i - 1].size(); t++)
        if (dp[i - 1][t] == 1 && good(v[i - 1][t].second, v[i][j].first)) {
          x = 1;
          prr = t;
          break;
        }
      dp[i].push_back(x);
      pr[i].push_back(prr);
    }
  }
  int xx = -1;
  for (int j = 0; j < v[n / 2].size(); j++)
    if (dp[n / 2][j] == 1) {
      xx = j;
      break;
    }
  if (xx == -1) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  vector<long long> ans;
  for (int i = n / 2; i >= 1; i--) {
    ans.push_back(a[i]);
    if (i == 1) {
      ans.push_back(v[i][xx].first);
      break;
    }
    long long c2 = v[i][xx].first;
    int prr = pr[i][xx];
    long long c1 = v[i - 1][prr].second;
    ans.push_back(get(c1, c2));
    xx = prr;
  }
  for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
  cout << endl;
}
