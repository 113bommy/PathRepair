#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
const long long MOD = 998244353;
const long long INF = 0x7f7f7f7f7f7f7f7f;
const int INFi = 0x7f7f7f7f;
const long long MAXN = 1e+5 + 7;
vector<long long> adj[MAXN];
long long visit[MAXN] = {};
int dx8[] = {0, 1, 1, 1, 0, -1, -1, -1}, dy8[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dx4[] = {0, 1, 0, -1}, dy4[] = {1, 0, -1, 0};
int t = 1;
long long n, m;
long long a[500], b[500];
vector<pair<long long, long long> > v;
vector<long long> ans1;
void MAIN() {
  cin >> n >> m;
  long long ans = -1;
  long long min2 = 1e+18, max2 = -1e+18;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    min2 = min(min2, a[i]);
    max2 = max(max2, a[i]);
  }
  ans = max2 - min2;
  for (long long i = 0; i < m; i++) {
    long long x, y;
    cin >> x >> y;
    v.push_back({x - 1, y - 1});
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) b[j] = a[j];
    long long count1 = 1;
    vector<long long> v1;
    for (auto it : v) {
      if (it.first <= i && i <= it.second) {
        v1.push_back(count1);
        for (long long j = it.first; j <= it.second; j++) b[j]--;
      }
      count1++;
    }
    long long max1 = -100;
    for (long long j = 0; j < n; j++) max1 = max(max1, b[j]);
    if (ans < max1 - b[i]) {
      ans = max1 - b[i];
      ans1 = v1;
    }
  }
  if (ans == max2 - min2) {
    cout << 0 << endl << 0;
    return;
  }
  cout << ans << endl << ans1.size() << endl;
  for (auto it : ans1) cout << it << " ";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed;
  cout << setprecision(10);
  ;
  mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
  ;
  while (t--) {
    MAIN();
  }
}
