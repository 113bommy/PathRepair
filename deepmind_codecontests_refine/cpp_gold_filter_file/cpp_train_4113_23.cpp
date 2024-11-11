#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  long long m, n, b, c, d, i, j, k, x, y, z, l, q, r;
  string s, s1, s2, s3, s4;
  long long cnt = 0, sum = 0;
  cin >> n;
  ;
  vector<pair<long long, pair<long long, long long> > > v;
  for (long long i = 1; i <= 2 * n - 1; i++) {
    for (j = 0; j < i; j++) cin >> x, v.push_back({x, {i + 1, j + 1}});
  }
  sort((v).begin(), (v).end());
  reverse((v).begin(), (v).end());
  bool vis[2 * n + 100];
  memset(vis, 0, sizeof(vis));
  vector<pair<long long, long long> > ans;
  for (long long i = 0; i < v.size(); i++) {
    long long one = v[i].second.first;
    long long two = v[i].second.second;
    if (vis[one] == 0 and vis[two] == 0)
      ans.push_back({one, two}), ans.push_back({two, one}), vis[one] = 1,
                                                            vis[two] = 1;
  }
  sort((ans).begin(), (ans).end());
  for (long long i = 0; i < ans.size(); i++) {
    cout << ans[i].second << " ";
  }
  cout << endl;
  ;
  return 0;
}
