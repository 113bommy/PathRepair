#include <bits/stdc++.h>
using namespace std;
int n;
int p[200001];
int b[200001];
int ans;
int oddCheck;
int color[200001];
void dfs(int node, int curColor) {
  color[node] = curColor;
  if (!color[p[node]]) dfs(p[node], curColor);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> p[i];
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    oddCheck += b[i];
  }
  if (oddCheck % 2 == 0) ans++;
  int curColor = 1;
  for (int i = 1; i <= n; i++) {
    if (!color[i]) {
      dfs(i, curColor);
      curColor++;
    }
  }
  curColor--;
  if (curColor != 1) ans += curColor;
  cout << ans << endl;
}
