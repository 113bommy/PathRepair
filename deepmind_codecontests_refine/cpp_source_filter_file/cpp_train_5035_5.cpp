#include <bits/stdc++.h>
using namespace std;
class PQtree {
 public:
  int siz[2010], sizr[2010], typ[2010];
  char *s;
  int n, nodecnt;
  bool fail;
  vector<int> con[2010];
  inline int state(int x) {
    if (!sizr[x]) return 0;
    if (sizr[x] == siz[x]) return 2;
    return 1;
  }
  void init(int N) {
    n = N;
    nodecnt = n + 1;
    for (int i = 1; i <= n; i++) con[n + 1].push_back(i);
  }
  void dfs(int np) {
    siz[np] = (np <= n);
    sizr[np] = (np <= n) ? (s[np] == '1') : 0;
    for (int &x : con[np]) {
      dfs(x);
      siz[np] += siz[x];
      sizr[np] += sizr[x];
    }
  }
  void getans(int np, vector<int> &ret) {
    if (np <= n) ret.push_back(np);
    for (int &x : con[np]) getans(x, ret);
  }
  int mergep(const vector<int> &v) {
    if (!v.size()) return 0;
    if (v.size() == 1) return v[0];
    int p = ++nodecnt;
    con[p] = v;
    return p;
  }
  void addedge(int s, int e) {
    if (e) con[s].push_back(e);
  }
  void merge(int a, int b) {
    con[a].insert(con[a].end(), con[b].begin(), con[b].end());
  }
  int solve(int np, int t) {
    if (fail) return 0;
    vector<int> v[3];
    for (int &x : con[np]) v[state(x)].push_back(x);
    if (v[1].size() > 2 || (t > 0 && v[1].size() > 1)) {
      fail = 1;
      return 0;
    }
    if (t == 0 && v[1].size() == 1 && v[2].size() == 0)
      return solve(v[1][0], 0);
    if (typ[np] == 0) {
      int P = mergep(v[2]);
      if (!t) {
        con[np] = v[0];
        if (!v[1].size())
          addedge(np, P);
        else {
          int p1 = solve(v[1][0], 1);
          addedge(p1, P);
          if (v[1].size() > 1) merge(p1, solve(v[1][1], 2));
          addedge(np, p1);
        }
      } else {
        typ[np] = 1;
        con[np].clear();
        addedge(np, mergep(v[0]));
        if (v[1].size()) merge(np, solve(v[1][0], 1));
        addedge(np, P);
        if (t == 2) reverse(con[np].begin(), con[np].end());
      }
      return np;
    } else {
      if (state(con[np][0]) == 2 && state(con[np].back()) == 0)
        reverse(con[np].begin(), con[np].end());
      vector<int> tmp;
      int cnt = 0;
      for (int &x : con[np]) {
        int S = state(x);
        if (S == 1) {
          int p;
          if (cnt == 0)
            cnt++, p = solve(x, 1);
          else if (cnt == 1)
            cnt++, p = solve(x, 2);
          else {
            fail = 1;
            return 0;
          }
          for (int &x : con[p]) tmp.push_back(x);
        } else if (S == 2) {
          tmp.push_back(x);
          if (cnt == 0)
            cnt++;
          else if (cnt == 2) {
            fail = 1;
            return 0;
          }
        } else {
          tmp.push_back(x);
          if (cnt == 1) cnt++;
        }
      }
      if (t && cnt == 2) {
        fail = 1;
        return 0;
      }
      con[np] = tmp;
      if (t == 2) reverse(con[np].begin(), con[np].end());
      return np;
    }
  }
  void regulate(char *S) {
    s = S;
    dfs(n + 1);
    solve(n + 1, 0);
  }
} T;
int n;
char s[1010][1010];
vector<int> ans;
int main() {
  scanf("%d", &n);
  T.init(n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1);
    T.regulate(s[i]);
  }
  if (T.fail)
    puts("NO");
  else {
    puts("YES");
    T.getans(n + 1, ans);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) putchar(s[i][ans[j - 1]]);
      puts("");
    }
  }
  return 0;
}
