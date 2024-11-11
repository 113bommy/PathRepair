#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX / 4, SINF = 0x3f;
const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
const int maxn = 3e5 + 10;
int mo_num = 1e9 + 7;
int n, t, case_of_T;
long long f[33][3], ans, m;
long long st[maxn << 4][3], cnt = 0;
unordered_map<int, vector<int> > h;
void Insert(int x, int pos) {
  int now = 0;
  for (int i = 30; i >= 0; i--) {
    int val = 1LL * x >> i * 1LL & 1LL;
    if (!st[now][val]) st[now][val] = ++cnt;
    h[now = st[now][val]].push_back(pos);
  }
}
void deal(int now, int pos) {
  int z = st[now][0], y = st[now][1];
  if (!h[z].empty() && !h[y].empty()) {
    sort(h[z].begin(), h[z].end());
    sort(h[y].begin(), h[y].end());
    long long zuo = 0, you = 0, sz = h[z].size(), sy = h[y].size();
    long long num = 0;
    while (zuo < sz && you < sy) {
      if (h[z][zuo] > h[y][you])
        you++, num += 1LL * sz - 1LL * zuo;
      else
        zuo++;
    }
    f[pos][0] += 1LL * num;
    f[pos][1] += 1LL * sz * sy - 1LL * num;
  }
  if (z && pos) deal(z, pos - 1);
  if (y && pos) deal(y, pos - 1);
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    Insert(x, i);
  }
  deal(0, 30);
  for (int i = 30; i >= 0; i--) {
    if (f[i][0] <= f[i][1]) {
      ans += 1LL * f[i][0];
    } else {
      ans += 1LL * f[i][1];
      m |= (1LL << i);
    }
  }
  cout << ans << " " << m << '\n';
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) solve();
  return 0;
}
