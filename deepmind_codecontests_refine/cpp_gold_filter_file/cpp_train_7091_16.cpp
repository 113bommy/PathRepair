#include <bits/stdc++.h>
using namespace std;
const int MOD = 12345;
const int maxm = 1010;
map<int, vector<int> > mp;
map<vector<int>, int> inv_mp;
long long n;
int m;
vector<int> b[26], b_size;
int a[maxm], a_size;
int E;
vector<int> c[26], c_size;
pair<string, int> d[maxm];
int belong[maxm];
int cnt[26];
int dfs_click;
void inc(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
struct Matrix {
  int mp[130][130];
  int size;
  Matrix(int s) {
    size = s;
    zero();
  }
  void zero() {
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++) mp[i][j] = 0;
  }
  void one() {
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++) mp[i][j] = i == j;
  }
  Matrix operator*(const Matrix &A) const {
    Matrix ans(A.size);
    ans.zero();
    for (int i = 0; i < size; i++)
      for (int j = 0; j < size; j++)
        for (int k = 0; k < size; k++)
          inc(ans.mp[i][j], mp[i][k] * A.mp[k][j] % MOD);
    return ans;
  }
};
Matrix pow_mod(Matrix a, long long b) {
  Matrix ans(a.size);
  ans.one();
  while (b) {
    if (b & 1) ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}
void dfs(int cur, vector<int> v) {
  if (cur == a_size) {
    mp[dfs_click] = v;
    inv_mp[v] = dfs_click++;
    return;
  }
  for (int i = 0; i < a[cur]; i++) {
    vector<int> vv = v;
    vv.push_back(i);
    dfs(cur + 1, vv);
  }
}
int getN(int u, int k) {
  vector<int> v = mp[u];
  for (int i : c[k]) {
    v[i]++;
    v[i] %= a[i];
  }
  assert(inv_mp.find(v) != inv_mp.end());
  return inv_mp[v];
}
int solve() {
  for (int i = 0; i < m; i++) b[d[i].first[0] - 'A'].push_back(d[i].second);
  for (int i = 0; i < 26; i++) {
    int s = (int)b[i].size();
    if (!s)
      continue;
    else {
      for (int j : b[i]) {
        belong[a_size] = E;
        c[E].push_back(a_size);
        a[a_size++] = j;
      }
      E++;
    }
  }
  dfs(0, vector<int>());
  Matrix ans(dfs_click);
  for (int u = 0; u < dfs_click; u++) {
    for (int j = 0; j < E; j++) {
      int v = getN(u, j);
      inc(ans.mp[u][v], 1);
    }
  }
  ans = pow_mod(ans, n);
  int res = 0;
  for (int i = 0; i < dfs_click; i++) {
    memset(cnt, 0, sizeof(cnt));
    assert(mp.find(i) != mp.end());
    vector<int> v = mp[i];
    for (int j = 0; j < a_size; j++) {
      if (v[j]) continue;
      cnt[belong[j]]++;
    }
    int num = 0;
    for (int j = 0; j < 26; j++)
      if (cnt[j]) num++;
    if (num == E) inc(res, ans.mp[0][i]);
  }
  return res;
}
int main() {
  scanf("%I64d %d", &n, &m);
  for (int i = 0; i < m; i++) cin >> d[i].first >> d[i].second;
  printf("%d\n", solve());
  return 0;
}
