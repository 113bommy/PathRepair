#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9, SIZE = 1e5 * 2;
vector<long long> vec;
long long dp[100][SIZE], tree[SIZE * 8], pushing[SIZE * 8], prevPos[SIZE],
    last[SIZE];
void push(int v) {
  tree[v] += pushing[v];
  pushing[v * 2 + 1] += pushing[v];
  pushing[v * 2 + 2] += pushing[v];
  pushing[v] = 0;
}
void build(int v, int l, int r, int k) {
  if (l == r - 1) {
    tree[v] = dp[k][l];
  } else {
    int mid = (l + r) / 2;
    build(v * 2 + 1, l, mid, k);
    build(v * 2 + 2, mid, r, k);
    tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);
  }
}
void upd(int v, int l, int r, int askl, int askr) {
  push(v);
  if (l >= askr || r <= askl) return;
  if (l >= askl && r <= askr) {
    pushing[v]++;
    push(v);
    return;
  }
  int mid = (l + r) / 2;
  upd(v * 2 + 1, l, mid, askl, askr);
  upd(v * 2 + 2, mid, r, askl, askr);
  tree[v] = max(tree[v * 2 + 1], tree[v * 2 + 2]);
}
long long get(int v, int l, int r, int askl, int askr) {
  push(v);
  if (l >= askr || r <= askl) return 0;
  if (l >= askl && r <= askr) {
    return tree[v];
  }
  int mid = (l + r) / 2;
  return max(get(v * 2 + 1, l, mid, askl, askr),
             get(v * 2 + 2, mid, r, askl, askr));
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  ;
  long long n, k;
  cin >> n >> k;
  vec.resize(n);
  for (int i = 0; i < n; i++) cin >> vec[i];
  set<long long> vals;
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    last[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    vals.insert(vec[i]);
    dp[0][i] = vals.size();
    prevPos[i] = last[vec[i]];
    last[vec[i]] = i;
    ans = max(ans, dp[0][i]);
  }
  for (int j = 1; j < k; j++) {
    for (int i = 0; i < SIZE; i++) {
      tree[i] = 0;
      pushing[i] = 0;
    }
    build(0, 0, n, j - 1);
    for (int i = 0; i < n; i++) {
      upd(0, 0, n, prevPos[i], i);
      dp[j][i] = max(dp[j - 1][i], get(0, 0, n, 0, i));
      ans = max(ans, dp[j][i]);
    }
    cout << "";
  }
  cout << dp[k - 1][n - 1];
  return 0;
}
