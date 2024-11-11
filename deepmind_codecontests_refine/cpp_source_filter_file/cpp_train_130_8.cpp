#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 69;
const int MX = 5e5 + 5;
const int LG = (int)log2(MX);
const long long mod = 1e9 + 7;
const int BLOCK = 450;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
vector<int> v, cnt;
vector<int> q, inv;
int val = 0;
void reset() {
  q.assign(n + 1, 0);
  inv.assign(n + 1, 0);
  val = 0;
}
void push(int nw) {
  inv[q[nw]]--;
  q[nw]++;
  inv[q[nw]]++;
  if (q[nw] > val) val = q[nw];
}
void pop(int nw) {
  inv[q[nw]]--;
  q[nw]--;
  inv[q[nw]]++;
  if (inv[val] == 0) val--;
}
bool check() { return inv[val] >= 2; }
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  v.resize(n + 1), cnt.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    cnt[v[i]]++;
  }
  vector<int> modus;
  int cntmx = 0;
  for (int i = 1; i <= n; i++) {
    if (cntmx < cnt[i]) {
      cntmx = cnt[i];
      modus.clear();
    }
    if (cntmx == cnt[i]) {
      modus.push_back(i);
    }
  }
  if (modus.size() > 1) {
    cout << n << "\n";
    return 0;
  }
  int fi = modus[0];
  if (cnt[fi] == n) {
    cout << 0 << "\n";
    return 0;
  }
  int ans = 0;
  for (int i = 1; i <= BLOCK; i++) {
    reset();
    int lf = 1;
    for (int rg = 1; rg <= n; rg++) {
      push(v[rg]);
      for (; val > i; lf++) pop(v[lf]);
      if (check()) ans = max(ans, rg - lf + 1);
    }
  }
  for (int sc = 1; sc <= n; sc++) {
    if (sc != fi || cnt[sc] < BLOCK) continue;
    vector<int> presum(2 * n + 5, -1);
    presum[n + 2] = 0;
    int sm = 0;
    for (int i = 1; i <= n; i++) {
      if (v[i] == fi)
        sm++;
      else if (v[i] == sc)
        sm--;
      if (presum[sm + n + 2] == -1) presum[sm + n + 2] = i;
      ans = max(ans, i - presum[sm + n + 2]);
    }
  }
  cout << ans << "\n";
  return 0;
}
