#include <bits/stdc++.h>
using namespace std;
const int INF = int(1E9) + 7;
const long double EPS = 1E-9;
const long double PI = acos(-1.0);
const int mod = 1000000007;
const int NMAX = 500 * 1000;
int cnt[NMAX], t[NMAX], n;
int x[NMAX], szx;
int getIdx(int c) { return lower_bound(x, x + szx, c) - x; }
int sum(int r) {
  int ans = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1) ans = (ans + t[r]) % mod;
  return ans;
}
void inc(int i, int d) {
  for (; i < szx; i = (i | (i + 1))) t[i] = (t[i] + d) % mod;
}
int sum(int l, int r) {
  if (l > r) return 0;
  return (sum(r) - sum(l - 1) + 2 * mod) % mod;
}
int m;
pair<int, int> a[NMAX];
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
  return a.second < b.second;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < int(m); ++i) {
    scanf("%d %d", &a[i].first, &a[i].second);
    x[szx++] = a[i].first;
    x[szx++] = a[i].second;
    x[szx++] = a[i].second - 1;
    if (a[i].first - 1 >= 0) x[szx++] = a[i].first - 1;
  }
  x[szx++] = 0;
  sort(x, x + szx);
  szx = unique(x, x + szx) - x;
  if (x[szx - 1] != n) {
    puts("0");
    exit(0);
  }
  sort(a, a + m, cmp);
  cnt[0] = 1;
  inc(0, 1);
  for (int i = 0; i < int(m); ++i) {
    int s = a[i].first, t = a[i].second;
    int lf = getIdx(s), rg = getIdx(t - 1), pos = getIdx(t);
    int add = sum(lf, rg);
    cnt[pos] = (cnt[pos] + add) % mod;
    inc(pos, add);
  }
  cout << cnt[szx - 1] << endl;
  return 0;
}
