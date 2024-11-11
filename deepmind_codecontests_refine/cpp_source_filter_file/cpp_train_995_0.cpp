#include <bits/stdc++.h>
using namespace std;
void print(int a) { printf("%d", a); }
void print(pair<int, int> a) { printf("(%d,%d)", a.first, a.second); }
template <class T, class U>
void print(pair<T, U> p) {
  printf("(");
  print(p.first);
  printf(",");
  print(p.second);
  printf(")");
}
template <class T>
void print(vector<T> v) {
  printf("{ ");
  for (T e : v) {
    print(e);
    printf(" ");
  }
  printf("}");
}
int add(int a, int b, int mod) { return ((a += b) >= mod) ? a - mod : a; }
void adding(int& a, int b, int mod) { a = add(a, b, mod); }
int mul(int a, int b, int mod) { return a * 1ll * b % mod; }
int mod[2] = {1000000009, 1000000007};
pair<int, int> operator+(const pair<int, int>& A, const pair<int, int>& B) {
  return pair<int, int>(add(A.first, B.first, mod[0]),
                        add(A.second, B.second, mod[1]));
}
pair<int, int> operator*(const pair<int, int>& A, const pair<int, int>& B) {
  return pair<int, int>(mul(A.first, B.first, mod[0]),
                        mul(A.second, B.second, mod[1]));
}
const int N = 200005;
pair<int, int> pw[N];
pair<int, int> dp[N];
int COUNT[N];
vector<int> g[N];
int n;
map<pair<int, int>, int> mp;
void dfs(int u, int p) {
  if (u != p) {
    g[u].erase(find((g[u]).begin(), (g[u]).end(), p));
  }
  COUNT[u] = 1;
  dp[u] = pair<int, int>(1, 1);
  for (int e : g[u]) {
    dfs(e, u);
    COUNT[u] += COUNT[e];
  }
  sort((g[u]).begin(), (g[u]).end(),
       [&](int a, int b) { return dp[a] < dp[b]; });
  for (int e : g[u]) {
    dp[u] = (dp[u] * pw[2 * COUNT[e]]) + dp[e];
  }
  dp[u] = dp[u] + dp[u];
  mp[dp[u]]++;
}
pair<int, int> ans(1, 1);
int res[N];
void modify(pair<int, int> hash, int v) {
  int& first = mp[hash];
  first += v;
  if (first == 0) mp.erase(mp.find(hash));
}
pair<int, int> make_tree(pair<int, int> hash, int len) {
  pair<int, int> h = pw[2 * len] + hash;
  return h + h;
}
void play(int u, pair<int, int> phash) {
  vector<pair<pair<int, int>, int>> hash;
  for (int i = (0); i <= ((int)(g[u]).size() - 1); ++i) {
    int e = g[u][i];
    hash.emplace_back(dp[e], e);
  }
  hash.emplace_back(phash, -1);
  for (int i = ((int)(hash).size() - 1); i >= (1); --i) {
    if (hash[i] < hash[i - 1]) swap(hash[i], hash[i - 1]);
  }
  int sz = (int)(hash).size();
  vector<pair<int, int>> L(sz), R(sz);
  vector<int> sum(sz);
  for (int i = (0); i <= (sz - 1); ++i) {
    L[i] = hash[i].first;
    if (hash[i].second != -1)
      sum[i] = COUNT[hash[i].second];
    else
      sum[i] = n - COUNT[u];
    if (i > 0) L[i] = (L[i - 1] * pw[sum[i]]) + L[i], sum[i] += sum[i - 1];
  }
  for (int i = (sz - 1); i >= (0); --i) {
    R[i] = hash[i].first;
    if (i < (int)(hash).size() - 1)
      R[i] = (R[i] * pw[2 * (sum.back() - sum[i])]) + R[i + 1];
  }
  pair<int, int> h = make_tree(L.back(), sum.back());
  modify(h, 1);
  ans = max(ans, pair<int, int>((int)(mp).size(), u));
  res[u] = (int)(mp).size();
  modify(h, -1);
  for (int i = (0); i <= (sz - 1); ++i) {
    int e = hash[i].second;
    if (e == -1) continue;
    pair<int, int> nw(0, 0);
    if (i > 0) nw = L[i - 1];
    if (i < sz - 1) nw = (nw * pw[2 * (sum.back() - sum[i])]) + R[i + 1];
    nw = make_tree(nw, sum.back() - COUNT[e]);
    modify(nw, 1);
    modify(dp[e], -1);
    play(e, nw);
    modify(dp[e], 1);
    modify(nw, -1);
  }
}
int main() {
  pw[0] = {1, 1};
  for (int i = (1); i <= (200000); ++i) pw[i] = pw[i - 1] + pw[i - 1];
  scanf("%d", &n);
  for (int i = (1); i <= (n - 1); ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  dfs(1, 1);
  int sav = (int)(mp).size();
  modify(dp[1], -1);
  play(1, pair<int, int>(0, 0));
  modify(dp[1], 1);
  printf("%d", ans.second);
  return 0;
}
