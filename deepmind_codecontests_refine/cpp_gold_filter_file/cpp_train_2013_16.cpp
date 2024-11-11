#include <bits/stdc++.h>
using namespace std;
int n, m;
int kolCol[3];
int used[100000];
int ans[100000];
vector<vector<int> > gr;
vector<vector<int> > vis;
void dfs(int v, int col) {
  used[v] = col;
  kolCol[col]++;
  for (int i = 0; i < gr[v].size(); i++) {
    int v1 = gr[v][i];
    if (!used[v1]) dfs(v1, 3 - col);
  }
}
void paint() {
  int ansind = 0;
  for (int col = 1; col <= 2; col++)
    for (int i = 0; i < n; i++)
      if (used[i] == col) {
        ans[i] = ansind / 3 + 1;
        ansind++;
      }
}
void writeAns() {
  printf("YES\n");
  for (int i = 0; i < n; i++)
    if (i + 1 < n)
      printf("%d ", ans[i]);
    else
      printf("%d\n", ans[i]);
}
int main() {
  scanf("%d%d", &n, &m);
  gr.assign(n, vector<int>(0));
  for (int i = 0; i < m; i++) {
    int v1, v2;
    scanf("%d%d", &v1, &v2);
    v1--;
    v2--;
    gr[v1].push_back(v2);
    gr[v2].push_back(v1);
  }
  kolCol[1] = 0;
  kolCol[2] = 0;
  for (int i = 0; i < n; i++)
    if (!used[i]) dfs(i, 1);
  if (kolCol[1] % 3 == 0) {
    paint();
    writeAns();
    return 0;
  }
  if (kolCol[1] % 3 == 2) {
    for (int i = 0; i < n; i++) used[i] = 3 - used[i];
    int t = kolCol[1];
    kolCol[1] = kolCol[2];
    kolCol[2] = t;
  }
  vector<int> d1(0), d2(0);
  for (int i = 0; i < n; i++)
    if (used[i] == 1)
      d1.push_back(i);
    else
      d2.push_back(i);
  for (int i = 0; i < n; i++)
    if (used[i] == 1 && gr[i].size() + 2 <= kolCol[2]) {
      int ind = 0;
      vector<int> used1(n, 0);
      for (int j = 0; j < gr[i].size(); j++) used1[gr[i][j]] = 1;
      ans[i] = n / 3;
      used[i] = 0;
      ind = 0;
      for (int j = 0; j < n && ind < 2; j++)
        if (used[j] == 2 && used1[j] == 0) {
          used[j] = 0;
          ind++;
          ans[j] = n / 3;
        }
      paint();
      writeAns();
      return 0;
    }
  if (kolCol[1] < 4 || kolCol[2] < 2) {
    printf("NO\n");
    return 0;
  }
  vis.assign(n, vector<int>(0));
  vector<int> used1(n, 0);
  int used1ind = 1;
  for (int i = 0; i < n; i++)
    if (used[i] == 1) {
      for (int j = 0; j < gr[i].size(); j++) used1[gr[i][j]] = used1ind;
      used1ind++;
      for (int j = 0; j < d2.size(); j++) {
        int v2 = d2[j];
        if (used1[v2] + 1 != used1ind) vis[v2].push_back(i);
      }
    }
  int kol = 0;
  for (int i = 0; i < n; i++)
    if (used[i] == 2)
      if (vis[i].size() >= 2) kol++;
  if (kol <= 1) {
    printf("NO\n");
    return 0;
  }
  kol = 0;
  for (int i = 0; i < n; i++)
    if (used[i] == 2)
      if (vis[i].size() >= 2) {
        ans[i] = n / 3 - kol;
        used[i] = 0;
        for (int j = 0; j < 2; j++) {
          int v = vis[i][j];
          used[v] = 0;
          ans[v] = n / 3 - kol;
        }
        kol++;
        if (kol == 2) break;
      }
  paint();
  writeAns();
  return 0;
}
