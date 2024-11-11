#include <bits/stdc++.h>
using namespace std;
void testCase() {}
int t[1000000];
int a[1000000];
long long prefsum[1000000];
map<long long, int> m;
int tbl[1000000];
int isompi[1000000];
int pienempi[1000000];
int M = 317;
int cnt[1000000];
int res[1000000];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> t[i];
  for (int i = 1; i <= n; i++) cin >> a[i];
  vector<long long> vals;
  vals.push_back(0);
  vals.push_back(k);
  vals.push_back(-k);
  prefsum[0] = 0;
  for (int i = 1; i <= n; i++) {
    if (t[i] == 1)
      prefsum[i] = a[i];
    else
      prefsum[i] = -a[i];
    if (i > 0) prefsum[i] += prefsum[i - 1];
    vals.push_back(prefsum[i]);
    vals.push_back(prefsum[i] + k);
    vals.push_back(prefsum[i] - k);
  }
  sort(vals.begin(), vals.end());
  int count = 1;
  for (int i = 0; i < vals.size(); i++) {
    if (i == 0 || vals[i - 1] != vals[i]) m[vals[i]] = ++count;
  }
  for (int i = 0; i <= n; i++) {
    tbl[i] = m[prefsum[i]];
    isompi[i] = m[prefsum[i] + k];
    pienempi[i] = m[prefsum[i] - k];
  }
  int q;
  cin >> q;
  vector<vector<int>> queries;
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    queries.push_back({l / M, r, l, i});
  }
  sort(queries.begin(), queries.end());
  long long ans = 0;
  int prevv = -1;
  int a = 0, b = 0;
  for (auto v : queries) {
    int luokka = v[0];
    int l = v[2];
    l--;
    int r = v[1];
    if (luokka == prevv) {
      if (l < a) {
        while (l < a) {
          a--;
          ans += cnt[isompi[a]];
          cnt[tbl[a]]++;
        }
      } else {
        while (l > a) {
          cnt[tbl[a]]--;
          ans -= cnt[isompi[a]];
          a++;
        }
      }
      while (b < r) {
        b++;
        ans += cnt[pienempi[b]];
        cnt[tbl[b]]++;
      }
    } else {
      for (int i = a; i <= b; i++) cnt[tbl[i]] = 0;
      ans = 0;
      a = l;
      b = r;
      for (int i = a; i <= b; i++) {
        ans += cnt[pienempi[i]];
        cnt[tbl[i]]++;
      }
    }
    res[v[3]] = ans;
    prevv = luokka;
  }
  for (int i = 0; i < q; i++) cout << res[i] << "\n";
}
