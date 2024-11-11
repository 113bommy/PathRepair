#include <bits/stdc++.h>
const int B = 500;
using namespace std;
const long long inf = 1e9 + 12;
long long mod = 1e9 + 7;
const long long mxn = 7e3 + 5;
const int N = 10000005;
const double pi = 3.14159;
int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[] = {1, 0, -1, 0, -1, 1, 1, -1};
long long m, n, k, y, z;
long long a[mxn], b[mxn];
map<long long, long long> M, cnt;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  set<long long> s;
  for (int i = 1; i <= n; i++) cin >> a[i], cnt[a[i]]++, s.insert(a[i]);
  for (int i = 1; i <= n; i++) cin >> b[i], M[a[i]] += b[i];
  for (auto i : s) {
    if (cnt[i] > 1)
      for (auto j : s) {
        if (j == i) continue;
        if ((j & i) == j) cnt[j]++;
      }
  }
  long long ans = 0;
  for (auto i : s) {
    if (cnt[i] > 1) ans += M[i];
  }
  cout << ans << endl;
}
