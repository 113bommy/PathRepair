#include <bits/stdc++.h>
using namespace std;
int par[101000];
bool isDamage[101000];
int n, m, d;
vector<int> e[101000];
int deepest[101000];
int h[101000];
void dfs(int now, int depth) {
  h[now] = depth;
  if (isDamage[now]) deepest[now] = depth;
  for (int i = 0; i < e[now].size(); i++) {
    if (par[e[now][i]] == 0) {
      par[e[now][i]] = now;
      dfs(e[now][i], depth + 1);
      deepest[now] = max(deepest[now], deepest[e[now][i]]);
    }
  }
}
int answer;
void dfs2(int now, int life) {
  if (life < 0) return;
  vector<int> v;
  for (int i = 0; i < e[now].size(); ++i) {
    if (par[e[now][i]] == now) {
      v.push_back(deepest[e[now][i]]);
    }
  }
  if (v.size() == 0) {
    answer++;
    return;
  }
  sort(v.begin(), v.end());
  if (v[v.size() - 1] == 0 || v[v.size() - 1] - h[now] <= d) answer++;
  if (isDamage[now]) life = min(life, d);
  for (int i = 0; i < e[now].size(); ++i) {
    if (par[e[now][i]] == now) {
      if (deepest[e[now][i]] == v[v.size() - 1]) {
        if (v.size() == 1) {
          dfs2(e[now][i], life - 1);
        } else {
          if (v[v.size() - 2] == 0)
            dfs2(e[now][i], life - 1);
          else
            dfs2(e[now][i], min(life - 1, d - (v[v.size() - 2] - h[now]) - 1));
        }
      } else {
        dfs2(e[now][i], min(life - 1, d - (v[v.size() - 1] - h[now]) - 1));
      }
    }
  }
}
int main() {
  scanf("%d %d %d", &n, &m, &d);
  for (int i = 0; i < m; i++) {
    int l;
    scanf("%d", &l);
    isDamage[l] = true;
  }
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    e[a].push_back(b);
    e[b].push_back(a);
  }
  par[1] = -1;
  dfs(1, 1);
  dfs2(1, 1000000);
  printf("%d\n", answer);
}
