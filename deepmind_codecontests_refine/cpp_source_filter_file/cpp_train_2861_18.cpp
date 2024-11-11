#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5;
const long long INF = 1e15;
const long long MOD = 1000000007;
deque<pair<int, int>> d;
int f[N];
int a[8] = {36000, 3600, 0, 600, 60, 0, 10, 1};
vector<int> ans;
int main() {
  ios::sync_with_stdio(false);
  ifstream inf("input.txt");
  int n, m, t;
  cin >> n >> m >> t;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    int u = 0;
    for (int i1 = 0; i1 < 8; i1++) u += (s[i1] - 48) * a[i1];
    f[u]++;
  }
  int ans1 = 0, ok = 0;
  for (int i = 0; i < 86400; i++) {
    if (!d.empty() && i - d[0].first == t) d.pop_front();
    while (f[i]) {
      if (d.size() == m) {
        int r = d.back().second;
        ans.push_back(r);
        d.pop_back();
        d.push_back(make_pair(i, r));
      } else {
        ans1++;
        ans.push_back(ans1);
        d.push_back(make_pair(i, ans1));
        if (d.size() == m) ok = 1;
      }
      f[i]--;
    }
  }
  if (!ok)
    cout << "No solution";
  else {
    cout << ans1 << endl;
    for (int i = 0; i < n; i++) cout << ans[i] << endl;
  }
}
