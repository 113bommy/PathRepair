#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<long long> v[N];
long long pre[N], ans[N], val[N], level[N];
bool p = 1;
void dfs1(long long node, long long par) {
  level[node] = level[par] + 1;
  for (auto it : v[node]) {
    if (it != par) dfs1(it, node);
  }
}
void dfs2(long long node, long long par) {
  if (level[node] % 2 == 0) {
    ans[node] = 1e15;
    for (auto it : v[node]) {
      if (it != par) {
        ans[node] = min(ans[node], val[it] - pre[node]);
      }
    }
    if (v[node].size() == 1) ans[node] = 0;
  } else {
    if (node == 1)
      ans[node] = val[node];
    else {
      ans[node] = val[node] - pre[par] - ans[par];
    }
  }
  for (auto it : v[node]) {
    if (it != par) {
      if (level[it] % 2) {
        if (val[it] < pre[node]) {
          p = 0;
          return;
        }
      } else
        pre[it] = val[node];
      dfs2(it, node);
    }
  }
}
int main() {
  long long node;
  scanf("%lld", &node);
  ;
  for (long long i = 2; i <= node; i++) {
    long long z;
    scanf("%lld", &z);
    ;
    v[i].push_back(z);
    v[z].push_back(i);
  }
  for (long long i = 1; i <= node; i++) scanf("%lld", &val[i]);
  ;
  dfs1(1, 0);
  dfs2(1, 0);
  long long hell = 0;
  if (p == 0) {
    cout << (-1) << "\n";
    return 0;
  }
  for (long long i = 1; i <= node; i++) hell = hell + ans[i];
  cout << hell << "\n";
}
