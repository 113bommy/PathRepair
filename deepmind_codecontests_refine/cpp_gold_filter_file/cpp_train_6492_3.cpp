#include <bits/stdc++.h>
using namespace std;
const int sz = 1e5 + 5;
vector<int> c[sz];
int a[sz];
int main() {
  int n;
  int m;
  scanf("%d", &n);
  ;
  scanf("%d", &m);
  ;
  for (int i = 0; i < m; i++) {
    int u;
    int v;
    scanf("%d", &u);
    ;
    scanf("%d", &v);
    ;
    c[u].push_back(v);
    c[v].push_back(u);
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    ;
    if (!a[i]) q.push(i);
  }
  vector<int> ans;
  while (!q.empty()) {
    int counter = q.front();
    q.pop();
    ans.push_back(counter);
    for (int i = 0; i < (int)c[counter].size(); i++) {
      int connected = c[counter][i];
      a[connected]--;
      if (!a[connected]) q.push(connected);
    }
  }
  printf("%d", (int)ans.size());
  ;
  puts("");
  ;
  for (int i = 0; i < (int)ans.size(); i++) {
    printf("%d", ans[i]);
    ;
    printf(" ");
    ;
  }
  puts("");
  ;
}
