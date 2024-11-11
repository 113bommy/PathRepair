#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const long long mod = 1e9 + 7;
inline long long read() {
  long long X = 0;
  bool flag = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = 0;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    X = (X << 1) + (X << 3) + ch - '0';
    ch = getchar();
  }
  if (flag) return X;
  return ~(X - 1);
}
long long n, m, k;
long long ans;
long long ar[N];
long long as[N];
map<int, int> mp;
struct node {
  int id, v, od;
  const bool operator<(const node &a) const { return od < a.od; }
} nd[N];
bool vis[N];
bool cmp(int a, int b) { return nd[a].v < nd[b].v; }
int main() {
  int T;
  T = read();
  while (T--) {
    int x, y;
    mp.clear();
    priority_queue<node> q;
    while (!q.empty()) q.pop();
    n = read();
    x = read();
    y = read();
    for (int i = 1; i <= n; i++) {
      vis[i] = 0;
      nd[i].v = read();
      mp[nd[i].v]++;
      nd[i].id = i;
      nd[i].od = mp[nd[i].v];
      q.push(nd[i]);
    }
    int no;
    for (int i = 1; i <= n + 1; i++)
      if (mp[i] == 0) no = i;
    for (int i = 1; i <= x; i++) {
      node p = q.top();
      q.pop();
      as[p.id] = p.v;
      vis[p.id] = 1;
    }
    vector<int> vk;
    vk.clear();
    for (int i = 1; i <= n; i++)
      if (vis[i] == 0) vk.push_back(i);
    sort(vk.begin(), vk.end(), cmp);
    for (int i = 0; i < vk.size(); i++) {
      as[vk[i]] = nd[vk[(i + (n - x) / 2) % (n - x)]].v;
    }
    m = n - y;
    for (int i = 1; i <= n; i++) {
      if (m <= 0) break;
      if (vis[i] == 0 && as[i] == nd[i].v) {
        vis[i] = 1;
        as[i] = no;
        m--;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (m <= 0) break;
      if (!vis[i]) {
        m--;
        as[i] = no;
        vis[i] = 1;
      }
    }
    int cct = 0;
    for (int i = 1; i <= n; i++) {
      if (as[i] == nd[i].v) cct++;
    }
    if (cct == x) {
      printf("YES\n");
      for (int i = 1; i <= n; i++) printf("%d ", as[i]);
      puts("");
    } else
      printf("NO\n");
  }
  return 0;
}
