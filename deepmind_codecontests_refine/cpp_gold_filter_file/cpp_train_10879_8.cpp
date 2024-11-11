#include <bits/stdc++.h>
using namespace std;
const int N = 2e6;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;
int n;
long long l, k;
int a[N];
long long cnt[N];
map<int, int> convert;
void compress() {
  vector<int> v(a + 1, a + 1 + n);
  sort(v.begin(), v.end());
  int cl = 1;
  convert[v[0]] = 1;
  for (int i = int(1); i <= int(v.size() - 1); ++i) {
    if (v[i] == v[i - 1]) continue;
    convert[v[i]] = ++cl;
  }
  for (int i = int(1); i <= int(n); ++i) a[i] = convert[a[i]];
}
long long d[N], p[2][N];
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> l >> k;
  long long times = l / n;
  for (int i = int(1); i <= int(n); ++i) cin >> a[i];
  compress();
  for (int i = int(1); i <= int(n); ++i) ++cnt[a[i]];
  long long ans = 0;
  for (int i = int(0); i <= int(n); ++i) p[0][i] = 1;
  for (int len = int(1); len <= int(k); ++len) {
    for (int i = int(0); i <= int(n); ++i) d[i] = 0;
    int x = (len & 1);
    for (int i = int(1); i <= int(l % n); ++i) ans = (ans + p[x ^ 1][a[i]]) % B;
    if (len == times + 1) break;
    for (int i = int(1); i <= int(n); ++i) {
      d[i] = (p[x ^ 1][i] * cnt[i]) % B;
      ans = (ans + (d[i] * ((times - len + 1) % B)) % B) % B;
      p[x][i] = (p[x][i - 1] + d[i]) % B;
    }
    for (int i = int(0); i <= int(n); ++i) p[x ^ 1][i] = 0;
  }
  cout << ans << "\n";
  return 0;
}
