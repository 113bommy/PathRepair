#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 1e9;
long long powm(long long a, long long p, long long m) {
  long long r = 1 % m;
  while (p) {
    if (p & 1) r = r * a % m;
    p >>= 1;
    a = a * a % m;
  }
  return r;
}
bool issimple(int d) {
  for (int i = 2; i * i <= d; ++i)
    if (d % i == 0) return false;
  return true;
}
int g[210][210], n, f[210], s = 0, t, mf[210][201], uses[210];
vector<int> path;
bool bfs() {
  deque<int> q;
  q.push_back(s);
  vector<int> d(n + 2, -1);
  d[s] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop_front();
    for (int i = 0; i < (n + 2); ++i)
      if (g[v][i] > mf[v][i] && d[i] == -1) {
        d[i] = v;
        q.push_back(i);
      }
  }
  if (d[t] != -1) {
    path.clear();
    int cur = t;
    while (cur != s) {
      path.push_back(cur);
      cur = d[cur];
    }
    path.push_back(s);
    reverse((path).begin(), (path).end());
  }
  return d[t] != -1;
}
int main() {
  scanf("%d", &n);
  t = n + 1;
  int odd = 0;
  for (int i = 0; i < (n); ++i) {
    scanf("%d", f + i + 1);
    if (f[i + 1] % 2 == 1)
      g[s][i + 1] = 2, odd++;
    else
      g[i + 1][t] = 2;
  }
  if (2 * odd != n) {
    puts("Impossible");
    return 0;
  }
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (n); ++j)
      if (f[i + 1] % 2) g[i + 1][j + 1] = issimple(f[i + 1] + f[j + 1]);
  for (int i = 0; i < (n); ++i) {
    if (bfs()) {
      for (int j = 0; j < (((int)(path).size()) - 1); ++j) {
        int u = path[j], v = path[j + 1];
        mf[u][v]++;
        mf[v][u]--;
      }
    } else {
      puts("Impossible");
      return 0;
    }
  }
  memset(uses, 0, sizeof(uses));
  vector<vector<int> > ans;
  for (int i = 0; i < (n); ++i)
    if (!uses[i + 1]) {
      vector<int> tmp;
      int c;
      for (c = i + 1; !uses[c];) {
        tmp.push_back(c);
        uses[c] = 1;
        for (int j = 0; j < (n); ++j)
          if (abs(mf[c][j + 1]) == 1 && !uses[j + 1]) {
            c = j + 1;
            break;
          }
      }
      ans.push_back(tmp);
    }
  printf("%d\n", ((int)(ans).size()));
  for (int i = 0; i < (((int)(ans).size())); ++i) {
    printf("%d", ((int)(ans[i]).size()));
    for (int j = 0; j < (((int)(ans[i]).size())); ++j) printf(" %d", ans[i][j]);
    puts("");
  }
  return 0;
}
