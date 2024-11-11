#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
vector<int> v_col[2];
bool vis[100005];
int ans[100005];
int degree[100005];
void dfs(int nom, int col) {
  vis[nom] = true;
  v_col[col].push_back(nom);
  int sz = v[nom].size();
  int i;
  for (i = 0; i < sz; i++) {
    if (!vis[v[nom][i]]) {
      dfs(v[nom][i], 1 - col);
    }
  }
}
int main() {
  int n, m, k;
  scanf("%d%d", &n, &m);
  k = n / 3;
  int i;
  for (i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    v[a].push_back(b);
    v[b].push_back(a);
    degree[a]++;
    degree[b]++;
  }
  for (i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i, 0);
    }
  }
  bool ok = false;
  if (v_col[0].size() % 3 == 0) {
    ok = true;
  } else {
    if (v_col[0].size() % 3 == 2) {
      swap(v_col[0], v_col[1]);
    }
    int sz = v_col[0].size();
    for (i = 0; i < sz; i++) {
      int nom = v_col[0][i];
      if (degree[nom] <= (int)v_col[1].size() - 2) {
        int j;
        ans[nom] = k;
        sort(v[nom].begin(), v[nom].end());
        sort(v_col[1].begin(), v_col[1].end());
        int ind = 0;
        int ost = 2;
        for (j = 0; ost && j < (int)v_col[1].size(); j++) {
          while (ind < (int)v[nom].size() && v[nom][ind] < v_col[1][j]) {
            ind++;
          }
          if (ind >= (int)v[nom].size() || v[nom][ind] != v_col[1][j]) {
            ans[v_col[1][j]] = k;
            ost--;
          }
        }
        k--;
        ok = true;
        break;
      }
    }
    if (!ok) {
      sz = v_col[1].size();
      int found = 0;
      sort(v_col[0].begin(), v_col[0].end());
      for (i = 0; i < sz && found < 2; i++) {
        int nom = v_col[1][i];
        if (degree[nom] <= (int)v_col[0].size() - 2) {
          int j;
          ans[nom] = k;
          sort(v[nom].begin(), v[nom].end());
          int ind = 0;
          int ost = 2;
          for (j = 0; ost && j < v_col[0].size(); j++) {
            while (ind < (int)v[nom].size() && v[nom][ind] < v_col[0][j]) {
              ind++;
            }
            if (ind >= (int)v[nom].size() || v[nom][ind] != v_col[0][j]) {
              ans[v_col[0][j]] = k;
              ost--;
            }
          }
          k--;
          found++;
        }
      }
      ok = (found == 2);
    }
  }
  if (!ok)
    printf("NO\n");
  else {
    printf("YES\n");
    int cur_ind = 0;
    int sz = v_col[0].size();
    for (i = 0; i < sz; i++) {
      int nom = v_col[0][i];
      if (!ans[nom]) {
        ans[nom] = (cur_ind / 3) + 1;
        cur_ind++;
      }
    }
    sz = v_col[1].size();
    for (i = 0; i < sz; i++) {
      int nom = v_col[1][i];
      if (!ans[nom]) {
        ans[nom] = (cur_ind / 3) + 1;
        cur_ind++;
      }
    }
    for (i = 1; i <= n; i++) {
      printf("%d", ans[i]);
      if (i < n) printf(" ");
    }
    printf("\n");
  }
  return 0;
}
