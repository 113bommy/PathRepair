#include <bits/stdc++.h>
using namespace std;
const static int N = 1e5 + 7;
const static int M = 1e5 + 7;
const int static inf = 1e9;
int p[N][2];
int c[M][3];
int pNum[M];
int pp[2 * N + 6 * M][4], pi;
int ppBak[2 * N + 6 * M][4];
int ss[M];
int cc[M];
int lev[M];
int startPoint, endPoint;
char ansColor[N];
void addE(int f, int to, int cap, int id) {
  ++pi;
  pp[pi][0] = to;
  pp[pi][1] = cap;
  pp[pi][2] = id;
  pp[pi][3] = ss[f];
  ss[f] = pi;
}
void add(int from, int to, int cap, int id) {
  addE(from, to, cap, id);
  addE(to, from, 0, id);
}
bool bfs(int s, int e) {
  memset(lev, 0, sizeof(lev));
  memcpy(cc, ss, sizeof(cc));
  lev[s] = 1;
  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int i = cc[v]; i; i = pp[i][3]) {
      int to = pp[i][0];
      if (lev[to] == 0 && pp[i][1] > 0) {
        que.push(to);
        lev[to] = lev[v] + 1;
      }
    }
  }
  return lev[e] > 0;
}
int dfs(int v, int f) {
  if (v == endPoint) {
    return f;
  }
  int rf = f;
  int i = cc[v];
  for (; i; i = pp[i][3]) {
    int to = pp[i][0];
    int lf = pp[i][1];
    if (lev[v] == lev[to] - 1 && lf > 0) {
      int tmp = dfs(to, min(f, lf));
      pp[i][1] -= tmp;
      f -= tmp;
      pp[i + ((i & 1) ? 1 : -1)][1] += tmp;
      if (f == 0) {
        break;
      }
    }
  }
  cc[v] = i;
  return rf - f;
}
int mf() {
  int ans = 0;
  while (bfs(startPoint, endPoint)) {
    int tmp = dfs(startPoint, inf);
    if (tmp == 0) {
      break;
    }
    ans += tmp;
  }
  return ans;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int costR, costB;
  scanf("%d%d", &costR, &costB);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &p[i][0], &p[i][1]);
  }
  unordered_map<int, int> mp[2];
  for (int i = 0; i < m; ++i) {
    int t, l, d;
    scanf("%d%d%d", &t, &l, &d);
    --t;
    c[i][0] = t;
    c[i][1] = l;
    c[i][2] = d;
    if (mp[t].count(l) == 0) {
      mp[t][l] = i;
    } else if (c[mp[t][l]][2] > d) {
      mp[t][l] = i;
    }
  }
  long long ans = 0;
  int minCost = min(costR, costB);
  int maxCost = max(costR, costB);
  char minColor = costR < costB ? 'r' : 'b';
  char maxColor = minColor == 'r' ? 'b' : 'r';
  int s = m + 1;
  int t = s + 1;
  int ss = t + 1;
  int tt = ss + 1;
  startPoint = ss;
  endPoint = tt;
  queue<int> que;
  for (int i = 0; i < n; ++i) {
    int id[2] = {-1, -1};
    for (int j = 0; j < 2; ++j) {
      if (mp[j].count(p[i][j]) > 0) {
        id[j] = mp[j][p[i][j]];
        ++pNum[id[j]];
      }
    }
    if (id[0] >= 0) {
      if (id[1] >= 0) {
        add(id[0], id[1], 1, i);
      } else {
        add(id[0], t, 1, i);
      }
    } else if (id[1] >= 0) {
      add(s, id[1], 1, i);
    } else {
      ans += minCost;
      ansColor[i] = minColor;
    }
  }
  int minMf = 0;
  int s2tt = 0;
  int ss2t = 0;
  for (int i = 0; i < m; ++i) {
    if (mp[c[i][0]][c[i][1]] != i) {
      continue;
    }
    int allPoints = pNum[i];
    int d = c[i][2];
    int minF = max(0, (allPoints - d + 1) / 2);
    int maxF = min(allPoints, (allPoints + d) / 2);
    minMf += minF;
    if (minF > maxF) {
      printf("-1");
      return 0;
    }
    if (c[i][0] == 0) {
      add(ss, i, minF, -1);
      s2tt += minF;
      if (maxF > minF) {
        add(s, i, maxF - minF, -1);
      }
    } else {
      add(i, tt, minF, -1);
      ss2t += minF;
      if (maxF > minF) {
        add(i, t, maxF - minF, -1);
      }
    }
  }
  add(s, tt, s2tt, -1);
  add(ss, t, ss2t, -1);
  add(t, s, inf, -1);
  memcpy(ppBak, pp, sizeof(pp[0]) * (1 + pi));
  int mmf = mf();
  if (mmf < minMf) {
    printf("-1");
    return 0;
  }
  int minFlowCost = pp[pi][1];
  for (int from = mmf, to = minFlowCost; from <= to;) {
    int tmp = (from + to) >> 1;
    memcpy(pp, ppBak, sizeof(pp[0]) * (pi + 1));
    pp[pi - 1][1] = tmp;
    if (mf() == mmf) {
      to = min(tmp, pp[pi][1]) - 1;
      minFlowCost = tmp;
    } else {
      from = tmp + 1;
    }
  }
  memcpy(pp, ppBak, sizeof(pp[0]) * (pi + 1));
  pp[pi - 1][1] = minFlowCost;
  mf();
  for (int i = 1; i < pi; i += 2) {
    int id = pp[i][2];
    if (id >= 0) {
      if (pp[i][1] == 0) {
        ansColor[id] = maxColor;
        ans += maxCost;
      } else {
        ansColor[id] = minColor;
        ans += minCost;
      }
    }
  }
  cout << ans << endl;
  cout << ansColor;
  return 0;
}
