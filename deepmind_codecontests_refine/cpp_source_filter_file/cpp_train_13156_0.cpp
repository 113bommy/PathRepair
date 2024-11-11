#include <bits/stdc++.h>
using namespace std;
int a[200001] = {0}, state[200001][2] = {0};
long long m[200001][2] = {0};
int n;
long long dfs(int x, int f, int i) {
  long result;
  if (x <= 0 || x > n) return 0;
  if (state[x][f] == i || state[x][f] == -1) return -1;
  if (state[x][f]) return m[x][f];
  state[x][f] = i;
  if (f)
    result = dfs(x - a[x], 1 - f, i);
  else
    result = dfs(x + a[x], 1 - f, i);
  if (result == -1)
    return state[x][f] = -1;
  else
    return m[x][f] = result + a[x];
}
int main() {
  cin >> n;
  for (int i = 2; i <= n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    a[1] = i;
    state[1][0] = 0;
    cout << dfs(1, 0, i) << endl;
  }
  return 0;
}
