#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 6e5 + 42;
int fw[N], mn[N / 2], mx[N / 2];
void upd(int pos, int x) {
  for (; pos > 0; pos -= (pos & -pos)) fw[pos] += x;
}
int get(int pos) {
  int res = 0;
  for (; pos < N; pos += (pos & -pos)) res += fw[pos];
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n = 0, m = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    mn[i] = i;
    mx[i] = i;
  }
  vector<int> a(m);
  for (auto& x : a) {
    cin >> x;
    x--;
    mn[x] = 0;
  }
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    pos[i] = n - i;
    upd(i + 1, 1);
  }
  for (int i = 0; i < m; i++) {
    mx[a[i]] = max(mx[a[i]], get(pos[a[i]] + 1));
    upd(pos[a[i]], -1);
    pos[a[i]] = i + n + 1;
    upd(pos[a[i]], 1);
  }
  for (int i = 0; i < n; i++) {
    mx[i] = max(mx[i], get(pos[i] + 1));
  }
  for (int i = 0; i < n; i++) cout << mn[i] + 1 << ' ' << mx[i] + 1 << '\n';
  return 0;
}
