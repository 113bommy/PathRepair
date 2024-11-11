#include <bits/stdc++.h>
using namespace std;
struct node {
  vector<pair<int, int> > V;
  int s, e;
};
int N;
int pre[2][200100], post[2][200100], ind[2][200100];
int par[2][200100];
vector<int> T[2][200100];
node SEG[2][4 * 200100];
int idx;
bool done[2][200100];
int Q[2][200100];
int head[2], tail[2];
void dfs(int cur, int t) {
  ind[t][idx] = cur;
  pre[t][cur] = idx++;
  for (int i = 0; i < T[t][cur].size(); i++) {
    int ch = T[t][cur][i];
    if (ch == par[t][cur]) continue;
    dfs(ch, t);
  }
  post[t][cur] = idx - 1;
}
void build(int i1, int i2, int cur, int l, int r, int t) {
  if (i1 >= r || i1 < l) return;
  SEG[t][cur].V.push_back(pair<int, int>(i2, i1));
  if (l + 1 == r) return;
  int mid = (l + r) / 2;
  build(i1, i2, 2 * cur, l, mid, t);
  build(i1, i2, 2 * cur + 1, mid, r, t);
}
void rem(pair<int, int> E, int t) {
  int i1 = E.first, i2 = E.second;
  int v1 = ind[t][i1], v2 = ind[t][i2];
  int s;
  if (pre[(t + 1) % 2][v1] < pre[(t + 1) % 2][v2])
    s = v2;
  else
    s = v1;
  if (!done[(t + 1) % 2][s]) {
    Q[(t + 1) % 2][tail[(t + 1) % 2]++] = s;
    done[(t + 1) % 2][s] = true;
  }
}
void query(int left, int right, int t, int cur, int l, int r) {
  if (left >= r || l >= right) return;
  if (left <= l && r <= right) {
    int i;
    for (i = SEG[t][cur].s; i <= SEG[t][cur].e && SEG[t][cur].V[i].first < left;
         i++) {
      rem(SEG[t][cur].V[i], t);
    }
    SEG[t][cur].s = i;
    for (i = SEG[t][cur].e;
         i >= SEG[t][cur].s && SEG[t][cur].V[i].first >= right; i--) {
      rem(SEG[t][cur].V[i], t);
    }
    SEG[t][cur].e = i;
    return;
  }
  int mid = (l + r) / 2;
  query(left, right, t, 2 * cur, l, mid);
  query(left, right, t, 2 * cur + 1, mid, r);
}
void go(int t) {
  for (int i = head[t]; i < tail[t]; i++) {
    int cur = Q[t][i];
    int p1 = pre[t][cur], p2 = post[t][cur];
    query(p1, p2 + 1, t, 1, 0, N);
  }
}
int main() {
  scanf("%d", &N);
  par[0][0] = par[1][0] = -1;
  for (int i = 0; i < 2; i++)
    for (int j = 1; j < N; j++) {
      int a;
      scanf("%d", &a);
      a--;
      par[i][j] = a;
      T[i][j].push_back(a);
      T[i][a].push_back(j);
    }
  idx = 0;
  dfs(0, 0);
  idx = 0;
  dfs(0, 1);
  for (int i = 0; i < N; i++) done[0][i] = done[1][i] = false;
  for (int i = 0; i < 2; i++)
    for (int j = 1; j < N; j++) {
      build(pre[(i + 1) % 2][par[i][j]], pre[(i + 1) % 2][j], 1, 0, N,
            (i + 1) % 2);
      build(pre[(i + 1) % 2][j], pre[(i + 1) % 2][par[i][j]], 1, 0, N,
            (i + 1) % 2);
    }
  for (int i = 1; i < 4 * N; i++) {
    sort(SEG[0][i].V.begin(), SEG[0][i].V.end());
    sort(SEG[1][i].V.begin(), SEG[1][i].V.end());
    SEG[0][i].s = 0;
    SEG[0][i].e = (int)SEG[0][i].V.size() - 1;
    SEG[1][i].s = 0;
    SEG[1][i].e = (int)SEG[1][i].V.size() - 1;
  }
  head[0] = head[1] = tail[0] = tail[1] = 0;
  int C;
  scanf("%d", &C);
  Q[0][tail[0]++] = C;
  done[0][C] = true;
  int m = 0;
  while (head[m] != tail[m]) {
    sort(&Q[m][head[m]], &Q[m][tail[m]]);
    go(m);
    if (m == 0)
      printf("Blue\n");
    else
      printf("Red\n");
    printf("%d", Q[m][head[m]]);
    for (int i = head[m] + 1; i < tail[m]; i++) printf(" %d", Q[m][i]);
    printf("\n");
    head[m] = tail[m] = 0;
    m = (m + 1) % 2;
  }
}
