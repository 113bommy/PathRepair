#include <bits/stdc++.h>
using namespace std;
const int N = int(3e5) + 1;
bool comp(pair<int, int> p1, pair<int, int> p2) {
  if (p1.second != p2.second)
    return p1.second < p2.second;
  else
    return p1.first < p2.first;
}
int sum(int a, int b) { return (a + b) % (int)998244353; }
int mul(int a, int b) { return (a * 1LL * b) % (int)998244353; }
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  int fact[300001];
  fact[0] = 1;
  for (int i = 1; i < N; ++i) fact[i] = mul(i, fact[i - 1]);
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back(make_pair(a, b));
  }
  int ans = 0;
  vector<pair<int, int>> vv(v.begin(), v.end());
  ans = 0;
  for (int c = 0; c < 2; c++) {
    sort(v.begin(), v.end());
    int tmp = 1;
    int l = 0;
    while (l < n) {
      int r = l + 1;
      while (r < n && v[l].first == v[r].first) ++r;
      tmp = mul(tmp, fact[r - l]);
      l = r;
    }
    ans = (ans + tmp) % (int)998244353;
    for (int k = 0; k < n; k++) swap(v[k].first, v[k].second);
  }
  vector<int> a, b;
  for (int i = 0; i < n; i++) {
    a.push_back(v[i].first);
    b.push_back(v[i].second);
  }
  if (is_sorted(a.begin(), a.end()) && is_sorted(b.begin(), b.end())) {
    int tmp = 1;
    for (int i = 0; i < n; i++) {
      int len = 1;
      while (i + 1 < n && v[i] == v[i + 1]) {
        len++;
        i++;
      }
      tmp = tmp * fact[len] % (int)998244353;
    }
    ans = (ans + (int)998244353 - tmp) % (int)998244353;
  }
  cout << (fact[n] - ans + (int)998244353) % (int)998244353;
  return 0;
}
