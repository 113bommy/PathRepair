#include <bits/stdc++.h>
using namespace std;
int ans[200001], T, N, arr[200001];
bool chk[200001];
int dfs(int n, int depth) {
  if (chk[n]) return depth;
  chk[n] = 1;
  return ans[n] = dfs(arr[n], depth + 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  while (T--) {
    cin >> N;
    for (int i = 1; i <= N; i++) chk[i] = 0;
    for (int i = 1; i <= N; i++) {
      cin >> arr[i];
    }
    for (int i = 1; i <= N; i++) {
      if (chk[i]) continue;
      dfs(i, 0);
    }
    for (int i = 1; i <= N; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
}
