#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T read() {
  T f = 0, x = 0;
  char c = getchar();
  while (!isdigit(c)) f = c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
  return f ? -x : x;
}
namespace run {
vector<vector<int> > sta;
vector<int> st;
int num, f[495 * 495], vis[495 * 495];
inline void dfs(int x, int sum) {
  if (x == 5) {
    if (!sum) sta.push_back(st), num++;
    return;
  }
  dfs(x + 1, sum);
  for (int i = 1; i <= sum; i++) st.push_back(x), dfs(x + 1, sum - i);
  for (int i = 1; i <= sum; i++) st.pop_back();
}
const int N = 8e6 + 9;
int head[N], nex[N], to[N], cnt, deg[N];
queue<int> q;
inline void add(int u, int v) {
  nex[++cnt] = head[u], head[u] = cnt, to[cnt] = v;
}
inline int id(vector<int> a) {
  return lower_bound(sta.begin(), sta.end(), a) - sta.begin();
}
inline void pre() {
  sort(sta.begin(), sta.end());
  for (int i = 0; i < num; i++)
    for (int p = 0; p < 8; p++)
      if (sta[i][p] && (!p || (p && sta[i][p - 1] != sta[i][p]))) {
        for (int k = 1; k < 5; k++) {
          vector<int> a = sta[i];
          a[p] = (a[p] + k) % 5, sort(a.begin(), a.end());
          int tmp = id(a);
          for (int j = 0; j < num; j++) {
            int peg = 0;
            for (int l = 0; l < 8; l++)
              if (sta[j][l] == k) {
                peg = 1;
                break;
              }
            if (peg) add(j * num + tmp, i * num + j), deg[i * num + j]++;
          }
        }
      }
  memset(f, -1, sizeof f);
  for (int i = 1; i < num; i++) q.push(i), vis[i] = 1, f[i] = 1;
  for (int i = 1; i < num; i++)
    q.push(i * num), vis[num * i] = 1, f[num * i] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; i; i = nex[i]) {
      if (!f[u]) f[to[i]] = 1;
      if (f[to[i]] == 1 && !vis[to[i]]) q.push(to[i]), vis[to[i]] = 1;
      if (!--deg[to[i]] && !vis[to[i]])
        f[to[i]] = 0, q.push(to[i]), vis[to[i]] = 1;
    }
  }
}
int main() {
  dfs(0, 8), assert(sta.size() == 495), pre();
  int T = read<int>();
  while (T--) {
    vector<int> a, b;
    a.clear(), b.clear();
    int _f = read<int>();
    for (int i = 0; i < 8; i++) a.push_back(read<int>());
    for (int i = 0; i < 8; i++) b.push_back(read<int>());
    if (_f) swap(a, b);
    sort(a.begin(), a.end()), sort(b.begin(), b.end());
    int tmp = num * id(a) + id(b), ret = f[tmp];
    if (ret == -1)
      puts("Deal");
    else if (_f ^ ret)
      puts("Alice");
    else
      puts("Bob");
  }
  return 0;
}
}  // namespace run
int main() { return run::main(); }
