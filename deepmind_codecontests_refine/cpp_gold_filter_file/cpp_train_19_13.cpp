#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 5;
int pre[N], si[N], num[N / 2], n, m;
bool vis[N];
char s[N];
vector<vector<int> > v(N / 2);
int findd(int x) {
  if (pre[x] == x) return x;
  pre[x] = findd(pre[x]);
  if (vis[x]) vis[pre[x]] = 1;
  return pre[x];
}
inline int id(int x) { return x > m ? x - m : x; }
int un(int a, int b) {
  int x = findd(a);
  int y = findd(b);
  if (x == y) return -1;
  int aa = id(x);
  int bb = id(y);
  if (aa < bb) {
    pre[y] = x, si[x] += si[y];
    if (vis[y]) vis[x] = 1;
    return aa;
  } else {
    pre[x] = y, si[y] += si[x];
    if (vis[x]) vis[y] = 1;
    return bb;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d", &a);
    while (a--) {
      scanf("%d", &b);
      v[b].push_back(i);
    }
  }
  for (int i = 1; i <= m; i++) {
    pre[i] = i, si[i] = 1;
    pre[i + m] = i + m, si[i + m] = 0;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') {
      if (v[i].size() == 1) {
        int a = findd(v[i][0]);
        int b = a > m ? a - m : a + m;
        vis[b] = 1;
        ans += si[a] - num[id(a)];
        num[id(a)] = si[a];
      }
      if (v[i].size() == 2) {
        int a = v[i][0], b = v[i][1];
        int sum = num[id(findd(a))] + num[id(findd(b))];
        int x = un(a, b + m);
        un(b, a + m);
        if (x != -1) {
          if (vis[x]) {
            ans += si[x + m] - sum;
            num[x] = si[x + m];
          } else if (vis[x + m]) {
            ans += si[x] - sum;
            num[x] = si[x];
          } else {
            ans += min(si[x], si[x + m]) - sum;
            num[x] = min(si[x], si[x + m]);
          }
        }
      }
    } else {
      if (v[i].size() == 1) {
        int a = findd(v[i][0] + m);
        int b = a > m ? a - m : a + m;
        vis[b] = 1;
        ans += si[a] - num[id(a)];
        num[id(a)] = si[a];
      }
      if (v[i].size() == 2) {
        int a = v[i][0], b = v[i][1];
        int sum = num[id(findd(a))] + num[id(findd(b))];
        int x = un(a, b);
        un(b + m, a + m);
        if (x != -1) {
          if (vis[x]) {
            ans += si[x + m] - sum;
            num[x] = si[x + m];
          } else if (vis[x + m]) {
            ans += si[x] - sum;
            num[x] = si[x];
          } else {
            ans += min(si[x], si[x + m]) - sum;
            num[x] = min(si[x], si[x + m]);
          }
        }
      }
    }
    printf("%d\n", ans);
  }
}
