#include <bits/stdc++.h>
using namespace std;
bool ans;
int H, W;
vector<bool> used;
vector<int> mrr;
vector<string> S;
bool same(int l, int r) {
  for (int k = 0; k < H; ++k) {
    if (S[k][l] != S[mrr[k]][r]) return false;
  }
  return true;
}
void solve() {
  int isOdd = W % 2;
  used = vector<bool>(W, false);
  for (int i = 0; i < W; ++i) {
    for (int j = i + 1; j < W; ++j) {
      if (used[i] || used[j]) continue;
      if (same(i, j)) used[i] = used[j] = true;
    }
  }
  for (int i = 0; i < W; ++i) {
    if (used[i]) continue;
    if (!isOdd || !same(i, i)) return;
    used[i] = true;
    isOdd = 0;
  }
  ans = true;
}
void dfs(int n, int isOdd) {
  if (ans) return;
  if (n >= H - 1) {
    solve();
    return;
  }
  if (mrr[n] != -1) {
    dfs(n + 1, isOdd);
    return;
  }
  if (isOdd) {
    mrr[n] = n;
    dfs(n + 1, 0);
  }
  for (int i = n + 1; i < H; ++i) {
    if (mrr[i] == -1) {
      mrr[n] = i;
      mrr[i] = n;
      dfs(n + 1, isOdd);
      mrr[i] = -1;
    }
  }
  mrr[n] = -1;
}
int main() {
  cin >> H >> W;
  S = vector<string>(H);
  for (int i = 0; i < H; ++i) cin >> S[i];
  mrr = vector<int>(H, -1);
  dfs(0, H % 2);
  cout << ((ans) ? "YES" : "NO") << endl;
  return 0;
}
