#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while (((c = getchar()) == ' ') || c == '\n')
    ;
  x = c;
}
int n, m, q, i, j, g[1005][1005], deg[1005], id[10005], nd[25], mp[1 << 19], t;
vector<int> v;
vector<pair<char, pair<int, int> > > res;
char s[15];
void dfs(int x) {
  deg[x] = -1;
  v.push_back(x);
  int i;
  for (((i)) = (1); ((i)) <= ((n)); ((i))++)
    if (g[x][i]) {
      if (!--deg[i]) dfs(i);
    }
}
void init(int x) {
  res.push_back(make_pair('+', make_pair(x, x)));
  int cur = 0, i, j, k;
  for (j = v.size() - t; j < v.size() - 1; j++) {
    if (g[x][v[j]]) cur ^= (1 << (j - (v.size() - t)));
  }
  if (!mp[cur]) {
    mp[cur] = x;
    return;
  }
  for (((i)) = (0); ((i)) <= (((int)(t - 1)) - 1); ((i))++) {
    if (!mp[cur ^ (1 << i)]) {
      if (g[x][nd[i]])
        res.push_back(make_pair('-', make_pair(x, nd[i])));
      else
        res.push_back(make_pair('+', make_pair(x, nd[i])));
      g[x][nd[i]] ^= 1;
      cur ^= (1 << i);
      mp[cur] = x;
      return;
    }
  }
  for (((i)) = (0); ((i)) <= (((int)(t - 1)) - 1); ((i))++)
    for (((j)) = (0); ((j)) <= (((int)(t - 1)) - 1); ((j))++) {
      if (!mp[cur ^ (1 << i) ^ (1 << j)]) {
        if (g[x][nd[i]])
          res.push_back(make_pair('-', make_pair(x, nd[i])));
        else
          res.push_back(make_pair('+', make_pair(x, nd[i])));
        g[x][nd[i]] ^= 1;
        cur ^= (1 << i);
        if (g[x][nd[j]])
          res.push_back(make_pair('-', make_pair(x, nd[j])));
        else
          res.push_back(make_pair('+', make_pair(x, nd[j])));
        g[x][nd[j]] ^= 1;
        cur ^= (1 << j);
        mp[cur] = x;
        return;
      }
    }
  for (((i)) = (0); ((i)) <= (((int)(t - 1)) - 1); ((i))++)
    for (((j)) = (0); ((j)) <= (((int)(t - 1)) - 1); ((j))++)
      for (((k)) = (0); ((k)) <= (((int)(t - 1)) - 1); ((k))++) {
        if (!mp[cur ^ (1 << i) ^ (1 << j) ^ (1 << k)]) {
          if (g[x][nd[i]])
            res.push_back(make_pair('-', make_pair(x, nd[i])));
          else
            res.push_back(make_pair('+', make_pair(x, nd[i])));
          g[x][nd[i]] ^= 1;
          cur ^= (1 << i);
          if (g[x][nd[j]])
            res.push_back(make_pair('-', make_pair(x, nd[j])));
          else
            res.push_back(make_pair('+', make_pair(x, nd[j])));
          g[x][nd[j]] ^= 1;
          cur ^= (1 << j);
          if (g[x][nd[k]])
            res.push_back(make_pair('-', make_pair(x, nd[k])));
          else
            res.push_back(make_pair('+', make_pair(x, nd[k])));
          g[x][nd[k]] ^= 1;
          cur ^= (1 << k);
          mp[cur] = x;
          return;
        }
      }
}
void solve() {
  puts("? 0");
  fflush(stdout);
  scanf("%s", s);
  if (s[0] == 'L') {
    printf("! %d\n", v.back());
    fflush(stdout);
    scanf("%s", s);
    return;
  }
  int cur = 0;
  for (((i)) = (0); ((i)) <= (((int)(t - 1)) - 1); ((i))++) {
    printf("? 1 %d\n", nd[i]);
    fflush(stdout);
    scanf("%s", s);
    if (s[0] == 'L') {
      printf("! %d\n", nd[i]);
      fflush(stdout);
      scanf("%s", s);
      return;
    }
    if (s[0] == 'W') {
      cur |= (1 << i);
    }
  }
  printf("! %d\n", mp[cur]);
  fflush(stdout);
  scanf("%s", s);
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (((i)) = (1); ((i)) <= ((m)); ((i))++) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[x][y] = 1;
    deg[y]++;
  }
  for (((i)) = (1); ((i)) <= ((n)); ((i))++)
    if (!deg[i]) dfs(i);
  t = min(n, 20);
  memset(id, -1, sizeof(id));
  for (i = v.size() - t; i < v.size(); i++) {
    nd[id[v[i]] = i - (v.size() - t)] = v[i];
    for (j = i + 1; j < v.size(); j++) {
      if (!g[v[i]][v[j]]) {
        res.push_back(make_pair('+', make_pair(v[i], v[j])));
        g[v[i]][v[j]] = 1;
      }
    }
  }
  for (((i)) = (1); ((i)) <= ((n)); ((i))++)
    if (id[i] == -1) {
      init(i);
    }
  printf("%d\n", res.size());
  for (__typeof((res).begin()) it = (res).begin(); it != (res).end(); it++) {
    printf("%c %d %d\n", it->first, it->second.first, it->second.second);
  }
  fflush(stdout);
  while (q--) {
    solve();
  }
  return 0;
}
