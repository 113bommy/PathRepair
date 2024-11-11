#include <bits/stdc++.h>
using namespace std;
const int mods = 998244353;
long long qpow(long long a, long long b) {
  long long res = 1;
  a %= mods;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mods;
    a = a * a % mods;
  }
  return res;
}
const int maxn = 1e5 + 10;
const int N = 3e5 + 10;
const int E = 3e5 + 10;
const int lim = 1e6;
int read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, m;
int a[maxn], arr[maxn];
int c[310][maxn], len;
int lowbit(int x) { return x & (-x); }
void add(int x, int p) {
  while (x <= len + 5) {
    c[p][x]++;
    x += lowbit(x);
  }
}
int query(int x, int p) {
  int res = 0;
  while (x) {
    res += c[p][x];
    x -= lowbit(x);
  }
  return res;
}
queue<int> g[maxn];
vector<int> key;
int main() {
  ios_base::sync_with_stdio(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    key.clear();
    for (int i = 0; i < n * m; i++) {
      cin >> a[i];
      key.push_back(a[i]);
    }
    sort(key.begin(), key.end());
    len = unique(key.begin(), key.end()) - key.begin();
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= len + 5; j++) {
        c[i][j] = 0;
      }
    }
    for (int i = 0; i < n * m; i++) {
      a[i] =
          lower_bound(key.begin(), key.begin() + len, a[i]) - key.begin() + 1;
      arr[i] = a[i];
    }
    sort(arr, arr + n * m);
    for (int i = 0; i < n * m; i++) {
      g[arr[i]].push(i);
    }
    long long ans = 0;
    for (int i = 0; i < n * m; i++) {
      int k = g[a[i]].front();
      g[a[i]].pop();
      k = k / m + 1;
      ans += query(a[i] - 1, k);
      add(a[i], k);
    }
    cout << ans << endl;
  }
  return 0;
}
