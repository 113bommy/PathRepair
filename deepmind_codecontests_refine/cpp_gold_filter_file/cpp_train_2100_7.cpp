#include <bits/stdc++.h>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
vector<int> v[500001];
vector<vector<int>> v2(101), g2(101);
vector<pair<int, int>> vi[100001];
set<int> s[1000007];
int dp[100001], vis[100001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m;
  cin >> n >> m;
  vector<pair<long long, long long>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  vector<pair<long long, long long>> pr(m);
  for (int i = 0; i < m; i++) cin >> pr[i].first >> pr[i].second;
  sort(pr.begin(), pr.end());
  long long dp[n];
  long long j = 0, s = 0;
  for (int i = 0; i < n; i++) {
    while (a[i].first >= pr[j].first && j < m) {
      s += pr[j].second;
      j++;
    }
    dp[a[i].second] = s;
  }
  for (int i = 0; i < n; i++) cout << dp[i] << " ";
  return 0;
}
