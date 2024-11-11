#include <bits/stdc++.h>
using namespace std;
long long GCD(long long a, long long b) { return (b == 0) ? a : GCD(b, a % b); }
long long LCM(long long a, long long b) {
  long long temp = GCD(a, b);
  return temp ? (a / temp * b) : 0;
}
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
long long oo = 1e18;
long long const M = 1e9 + 7, N = 2e5 + 7;
long long n, sum, m;
int fa[150001], fb[150001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  vector<int> va[100], vb[100];
  vector<pair<int, int> > ans;
  for (int i = 0; i < n; i++) {
    if (a[i] == '?')
      va['?'].push_back(i + 1);
    else
      va[a[i] - 'a'].push_back(i + 1);
  }
  for (int i = 0; i < n; i++) {
    if (b[i] == '?')
      vb['?'].push_back(i + 1);
    else
      vb[b[i] - 'a'].push_back(i + 1);
  }
  for (int j = 0; j < 26; j++) {
    int l = min(va[j].size(), vb[j].size());
    for (int i = 0; i < l; i++) {
      ans.push_back(make_pair(va[j][i], vb[j][i]));
      fa[va[j][i]] = 1;
      fb[vb[j][i]] = 1;
    }
  }
  int l = 0, r = 0;
  int w = 0, k = '?', qa = va['?'].size(), qb = vb['?'].size();
  for (int i = 0; i < n; i++) {
    if (a[i] == '?') continue;
    if (fa[i + 1] == 0 && l < qb) {
      ans.push_back(make_pair(i + 1, vb[k][l]));
      l++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (b[i] == '?') continue;
    if (fb[i + 1] == 0 && r < qa) {
      ans.push_back(make_pair(va[k][r], i + 1));
      r++;
    }
  }
  int l1 = qa - l, l2 = qb - r;
  for (int i = 0; i < min(l1, l2); i++)
    ans.push_back(make_pair(va[k][l++], vb[k][r++]));
  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << '\n';
  }
  return 0;
}
