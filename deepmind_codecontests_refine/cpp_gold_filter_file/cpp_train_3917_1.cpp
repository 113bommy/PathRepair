#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
vector<int> al[200009];
bool vis[200009];
bool ded[200009];
int main() {
  int n;
  scanf("%d", &n);
  ;
  long long ans = 1;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    ;
    int b;
    scanf("%d", &b);
    ;
    ;
    a--;
    b--;
    if (a == b) ded[a] = 1;
    al[a].push_back(b);
    al[b].push_back(a);
  }
  for (int i = 0; i < n * 2; i++) {
    if (al[i].size() == 0 || vis[i]) continue;
    bool bad = 0;
    vis[i] = 1;
    queue<int> q;
    q.push(i);
    int nedges = 0;
    int nnodes = 0;
    while (q.size()) {
      int p = q.front();
      nnodes++;
      nedges += al[p].size();
      if (ded[p]) bad = 1;
      q.pop();
      for (int e : al[p]) {
        if (!vis[e]) {
          vis[e] = 1;
          q.push(e);
        }
      }
    }
    if (bad) {
    } else if (nedges == nnodes * 2) {
      ans = ans * 2 % MOD;
    } else {
      ans = ans * nnodes % MOD;
    }
  }
  cout << ans << endl;
}
