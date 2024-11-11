#include <bits/stdc++.h>
const double PI = 3.1415926535897932384626433;
const int KL = 1e6;
using namespace std;
const long long MOD = 998244353;
int mul(int x, int y) { return x * 1LL * y % MOD; }
int add(int x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
  return x;
}
int sub(int x, int y) {
  x -= y;
  if (x < 0) x += MOD;
  return x;
}
int pow(int u, int v) {
  if (v == 0) return 1;
  int ret = pow(u, v / 2);
  ret = mul(ret, ret);
  if (v % 2 == 1) ret = mul(ret, u);
  return ret;
}
int fact[KL + 10], invi[KL + 10], inv[KL + 10];
void init() {
  fact[0] = invi[0] = invi[1] = inv[0] = 1;
  for (int i = 1; i < KL; i++) fact[i] = mul(fact[i], i);
  for (int i = 2; i < KL; i++) invi[i] = mul(invi[MOD % i], MOD - MOD / i);
  for (int i = 1; i < KL; i++) inv[i] = mul(inv[i - 1], invi[i]);
}
int C(int u, int v) {
  if (u < v) return 0;
  return mul(fact[u], mul(inv[v], inv[u - v]));
}
int k, A, h, pw[KL], place[KL];
vector<pair<int, int>> res[2][2];
void solve(int mask, int pos) {
  vector<int> vec;
  if (pos == 0)
    for (int i = 1; i <= pw[k - 1]; i++) vec.push_back(i);
  else
    for (int i = pw[k - 1] + 1; i <= pw[k]; i++) vec.push_back(i);
  int ret = 0, cnt = 0;
  while (1) {
    if (vec.size() == 1) {
      place[vec[0]] = 2;
      int ad = mul(A, vec[0]);
      res[pos][0].push_back({add(ad, ret), mask});
      ad = mul(ad, A);
      res[pos][1].push_back({add(ad, ret), mask});
      break;
    }
    vector<int> nw;
    for (int j = 1; j < vec.size(); j += 2) {
      if ((mask & pw[cnt])) {
        nw.push_back(vec[j - 1]);
        int ad = mul(vec[j], pow(A, (int)vec.size() + 1));
        ret = add(ret, ad);
        place[vec[j]] = vec.size() + 1;
      } else {
        nw.push_back(vec[j]);
        int ad = mul(vec[j - 1], pow(A, (int)vec.size() + 1));
        ret = add(ret, ad);
        place[vec[j - 1]] = vec.size() + 1;
      }
      cnt++;
    }
    vec.clear();
    for (auto v : nw) vec.push_back(v);
  }
}
map<int, int> mp;
bool fnd(int i, int j) {
  mp.clear();
  int pos = 1;
  for (auto v : res[0][i]) {
    mp[v.first] = pos;
    pos++;
  }
  int pos1 = 0, pos2 = 1;
  for (auto v : res[1][j]) {
    int rem = sub(h, v.first);
    pos1 = mp[rem];
    if (pos1 > 0) break;
    pos2++;
  }
  if (pos1 == 0) return false;
  int mask1 = res[0][i][pos1 - 1].second;
  int mask2 = res[1][j][pos2 - 1].second;
  solve(mask1, 0);
  solve(mask2, 0);
  if (i == 0) {
    for (int id = 1; id <= pw[k - 1]; id++)
      if (place[id] == 2) place[id] = 1;
  } else {
    for (int id = pw[k - 1] + 1; id <= pw[k]; id++)
      if (place[id] == 2) place[id] = 1;
  }
  for (int id = 1; id <= pw[k]; id++) printf("%d ", place[id]);
  printf("\n");
  return 1;
}
int main() {
  pw[0] = 1;
  for (int i = 1; i <= 17; i++) pw[i] = mul(pw[i - 1], 2);
  scanf("%d", &k);
  scanf("%d", &A);
  scanf("%d", &h);
  for (int mask = 0; mask < pw[pw[k - 1] - 1]; mask++) {
    solve(mask, 0);
    solve(mask, 1);
  }
  if (fnd(1, 0)) return 0;
  if (fnd(0, 1)) return 0;
  puts("-1");
  return 0;
}
