#include <bits/stdc++.h>
using namespace std;
int N;
long long A[10], lft[10];
int ans = 1e9;
bool leaf[10];
int num[10];
int num_prim(long long n) {
  int res = 0;
  for (auto d = 2ll; d * d <= n; ++d) {
    while (n % d == 0) {
      n /= d;
      ++res;
    }
  }
  if (n > 1) ++res;
  return res;
}
void dfs(int c, bool root) {
  if (c == N) {
    int res = root;
    for (int i = 0; i < N; ++i) {
      res += 1 + (leaf[i] && num[i] == 1 ? 0 : num[i]);
    }
    ans = min(ans, res);
    return;
  }
  if (c == 0) {
    dfs(1, true);
    dfs(1, false);
    return;
  }
  if (root) {
    dfs(c + 1, root);
  }
  for (int i = 0; i < c; ++i) {
    if (lft[i] % A[c] != 0) continue;
    lft[i] /= A[c];
    num[i] -= num[c];
    bool old = leaf[i];
    leaf[i] = false;
    dfs(c + 1, root);
    lft[i] *= A[c];
    num[i] += num[c];
    leaf[i] = old;
  }
}
int main() {
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> A[i];
  sort(A, A + N, greater<int>());
  copy(A, A + N, lft);
  for (int i = 0; i < N; ++i) num[i] = num_prim(A[i]);
  fill(leaf, leaf + N, true);
  dfs(0, false);
  cout << ans << "\n";
  return 0;
}
