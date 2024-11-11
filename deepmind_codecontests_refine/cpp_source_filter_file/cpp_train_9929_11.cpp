#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int now, c, d, tot, size, cnt, got, n, m, pos[6];
bool v[4][N];
int ans[2][N];
int T[N << 2][4], f[N << 2][4], Pi[N << 2], que[N << 2];
vector<int> have[N << 2];
vector<pair<int, int> > step[N];
inline void read(int &ret) {
  ret = 0;
  static char x;
  for (x = getchar(); x < '0' || x > '9'; x = getchar())
    ;
  while (x >= '0' && x <= '9') {
    ret = ret * 10 + x - '0';
    x = getchar();
  }
}
struct Res {
  pair<int, int> e[4][N], data[N << 2];
  int now, r1, t, ex[4];
  vector<pair<int, int> >::iterator r2;
  void addedge(int a, int b, int c, int d) {
    e[a][b] = make_pair(c, d);
    e[c][d] = make_pair(a, b);
  }
  bool Go() {
    now = 0;
    for (int i = 0; i < 2; ++i)
      for (int j = 0; j < got; ++j) {
        now = f[now][data[j].first];
        if ((j & 1) && !have[now].empty()) {
          t = *have[now].rbegin();
          if (step[t].size() != got) continue;
          have[now].pop_back();
          r1 = (j + 1) % got;
          r2 = step[t].begin();
          for (int order = 1; r2 != step[t].end();
               ++r2, r1 = (r1 + 1) % got, order ^= 1)
            if (order) ans[ex[data[r1].first]][data[r1].second] = r2->second;
          return 1;
        }
      }
    return 0;
  }
  bool work(int a, int b) {
    got = 0;
    do {
      data[got++] = make_pair(a, b);
      v[a][b] = 1;
      if (!v[a ^ 1][b])
        a ^= 1;
      else
        c = e[a][b].first, d = e[a][b].second, a = c, b = d;
    } while (!v[a][b]);
    if (Go()) return 1;
    reverse(data, data + got);
    if (Go()) return 1;
    return 0;
  }
  bool Compare() {
    for (int i = 1; i <= pos[0]; ++i) addedge(3, i, 0, i);
    for (int i = 1; i <= pos[1]; ++i) addedge(0, m - i + 1, 2, i);
    for (int i = 1; i <= pos[2]; ++i) addedge(1, m - i + 1, 2, n - i + 1);
    for (int i = 1; i <= pos[3]; ++i) addedge(3, n - i + 1, 1, i);
    for (int i = 1; i <= pos[5]; ++i) addedge(3, i + pos[3], 2, i + pos[2]);
    for (int i = 1; i <= pos[4]; ++i) addedge(0, i + pos[0], 1, i + pos[3]);
    ex[0] = ex[1] = 1;
    ex[2] = ex[3] = 0;
    memset(v, 0, sizeof(v));
    for (int i = 1; i <= n; ++i) {
      if (!v[3][i])
        if (!work(3, i)) return 0;
      if (!v[2][i])
        if (!work(2, i)) return 0;
    }
    for (int i = 1; i <= m; ++i) {
      if (!v[0][i])
        if (!work(0, i)) return 0;
      if (!v[1][i])
        if (!work(1, i)) return 0;
    }
    return 1;
  }
} Result;
struct Now {
  pair<int, int> e[4][N];
  int ex[260], place[4][4];
  void addedge(int a, int b, int c, int d) {
    e[a][b] = make_pair(c, d);
    e[c][d] = make_pair(a, b);
  }
  void Insert(int a, int b) {
    now = 0;
    do {
      step[tot].push_back(make_pair(a, b));
      if (!T[now][a]) T[now][a] = ++size;
      now = T[now][a];
      v[a][b] = 1;
      if (!v[a ^ 1][b])
        a ^= 1;
      else
        c = e[a][b].first, d = e[a][b].second, a = c, b = d;
    } while (!v[a][b]);
    have[now].push_back(tot++);
  }
  void Aho_Corasick() {
    for (int head = 1, tail = 1, x, u, k, i; head <= tail; ++head) {
      u = que[head];
      for (i = 0; i < 4; ++i)
        if (T[u][i]) f[u][i] = que[++tail] = T[u][i];
      if (!u) continue;
      for (i = 0; i < 4; ++i) {
        k = Pi[u];
        while (k && !T[k][i]) k = Pi[k];
        if ((x = T[u][i]))
          Pi[x] = T[k][i];
        else
          f[u][i] = T[k][i];
      }
    }
  }
  bool Init() {
    ex['T'] = 0;
    ex['B'] = 1;
    ex['R'] = 2;
    ex['L'] = 3;
    place[0][3] = 0;
    place[0][2] = 1;
    place[1][2] = 2;
    place[1][3] = 3;
    place[0][1] = 4;
    place[2][3] = 5;
    scanf("%d%d", &n, &m);
    for (int i = 0, a, b, p, q; i < n + m; ++i) {
      for (a = getchar(); !ex[a] && a != 'T'; a = getchar())
        ;
      for (b = getchar(); !ex[b] && b != 'T'; b = getchar())
        ;
      read(p);
      read(q);
      a = ex[a];
      b = ex[b];
      if (a > b) {
        swap(a, b);
        swap(p, q);
      }
      addedge(a, p, b, q);
      pos[place[a][b]]++;
    }
    if (pos[4] && pos[5]) return 0;
    if (pos[3] != pos[1] || pos[0] != pos[2]) return 0;
    for (int i = 1; i <= n; ++i) {
      if (!v[3][i]) Insert(3, i);
      if (!v[2][i]) Insert(2, i);
    }
    for (int i = 1; i <= m; ++i) {
      if (!v[0][i]) Insert(0, i);
      if (!v[1][i]) Insert(1, i);
    }
    Aho_Corasick();
    return 1;
  }
} Now_Work;
int main() {
  if (Now_Work.Init())
    if (Result.Compare()) {
      for (int i = 1; i <= n; ++i) printf("%d ", ans[0][i]);
      printf("\n");
      for (int i = 1; i <= m; ++i) printf("%d ", ans[1][i]);
      return 0;
    }
  printf("No solution");
  return 0;
}
