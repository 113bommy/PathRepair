#include <bits/stdc++.h>
const double eps = (1e-10);
using namespace std;
int dcmp(long double a, long double b) {
  return fabsl(a - b) <= eps ? 0 : (a > b) ? 1 : -1;
}
int getBit(int num, int idx) { return ((num >> idx) & 1) == 1; }
int setBit1(int num, int idx) { return num | (1 << idx); }
long long setBit0(long long num, int idx) { return num & ~(1ll << idx); }
long long flipBit(long long num, int idx) { return num ^ (1ll << idx); }
void M() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int countNumBit1(int mask) {
  int ret = 0;
  while (mask) {
    mask &= (mask - 1);
    ++ret;
  }
  return ret;
}
int k, n, fl, vis[10], ok;
long long ans[10];
long long MOD = 1000000007;
vector<vector<int> > v(10);
void dfs(int no) {
  if (no == 1 && fl) {
    ok = 1;
    return;
  }
  if (vis[no]) return;
  vis[no] = 1;
  fl = 1;
  for (int i = 0; i < ((int)(v[no]).size()); i++) {
    dfs(v[no][i]);
  }
}
bool check() {
  for (int i = 1; i <= k; i++) {
    memset(vis, 0, sizeof(vis));
    fl = 0;
    ok = 0;
    dfs(i);
    if (ok == 0) {
      return 0;
    }
  }
  return 1;
}
long long solve(int id) {
  if (id == k) {
    if (check()) return 1;
    return 0;
  }
  long long ans = 0;
  for (int i = 1; i <= k; i++) {
    v[id].push_back(i);
    v[i].push_back(id);
    ans = (ans + solve(id + 1)) % MOD;
    v[id].pop_back();
    v[i].pop_back();
  }
  return ans;
}
int main() {
  cin >> n >> k;
  ans[1] = 1;
  ans[2] = 2;
  ans[3] = 9;
  ans[4] = 64;
  ans[5] = 625;
  ans[6] = 7776;
  ans[7] = 117649;
  ans[8] = 2097152;
  int s = n - k;
  long long S = 1;
  for (int i = 1; i <= s; i++) S = (S * s) % MOD;
  cout << (S * ans[8]) % MOD << endl;
}
