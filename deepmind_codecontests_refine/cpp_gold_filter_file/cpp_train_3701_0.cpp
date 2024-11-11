#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int in[N];
int tt = 0;
int mark[N];
vector<int> inds;
void dfs(int a) {
  mark[a] = tt;
  if (mark[in[a]] == tt) {
    inds.push_back(a);
    return;
  }
  if (mark[in[a]]) return;
  dfs(in[a]);
  return;
}
int ans[N];
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  bool p = 0;
  int ind = 0;
  for (int i = 1; i <= n; i++) {
    cin >> in[i];
    if (in[i] == i) {
      p = 1;
      ind = i;
    }
    ans[i] = in[i];
  }
  for (int i = 1; i <= n; i++) {
    tt++;
    if (!mark[i]) dfs(i);
  }
  int k = inds.size();
  if (p) {
    cout << k - 1 << endl;
    for (int i = 0; i < k; i++)
      if (inds[i] != ind) ans[inds[i]] = ind;
  } else {
    cout << k << endl;
    ans[inds[0]] = inds[0];
    for (int i = 1; i < k; i++) ans[inds[i]] = inds[0];
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  return 0;
}
