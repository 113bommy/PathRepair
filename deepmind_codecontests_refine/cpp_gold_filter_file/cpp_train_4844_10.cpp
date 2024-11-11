#include <bits/stdc++.h>
using namespace std;
int n, a[202222], b[202222], pos_a[202222], pos_b[202222], pa[202222],
    deep[202222];
int root, xp, cir_list[2022222], cnt_list, pos[202222];
bool cir[202222];
vector<int> adj[2010000];
long long ans;
bool must[2010000];
void dfs(int id, int pr) {
  int i, j, s, p, q, ip;
  pa[id] = pr;
  for (i = 0; i < adj[id].size(); i++) {
    ip = adj[id][i];
    if (ip == pr) continue;
    deep[ip] = deep[id] + 1;
    dfs(ip, id);
  }
}
bool got(int id) {
  int i, j, s, p, q, ip, cnt = 0;
  cir_list[cnt_list++] = id;
  for (i = 0; i < adj[id].size(); i++) {
    ip = adj[id][i];
    if (ip == pa[id]) continue;
    if (cir[ip] && (a[ip] != b[ip] || must[ip])) {
      cnt++;
      if (id == root && cnt > 2) return false;
      if (id != root && cnt > 1) return false;
      if (!got(ip)) return false;
      if (id == root && cnt == 1) xp = cnt_list;
    }
  }
}
int main() {
  int i, j, s, p, q, u, v, id, id1, id2, ip;
  scanf("%d", &n);
  ans = 0;
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    pos_a[a[i]] = i;
  }
  for (i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    pos_b[b[i]] = i;
  }
  for (i = 0; i < n; i++) adj[i].clear();
  for (i = 0; i < n - 1; i++) {
    scanf("%d%d", &u, &v);
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  deep[pos_a[0]] = 0;
  dfs(pos_a[0], -1);
  id = pos_b[0];
  memset(cir, true, sizeof(cir));
  int kn[2] = {0}, flag = -1;
  memset(must, false, sizeof(must));
  while (id != pos_a[0]) {
    if (kn[1] == 0) {
      if (b[pa[id]] == a[id]) {
        cir[id] = false;
        if (flag != 0) {
          flag = 0;
          kn[flag]++;
        }
        ans++;
      } else {
        if (a[id] == b[id]) must[id] = true;
        if (flag != 1) {
          flag = 1;
          kn[flag]++;
        }
      }
      id = pa[id];
    } else {
      if (b[pa[id]] == a[id]) {
        cir[pa[id]] = false;
        if (flag != 0) {
          flag = 0;
          kn[flag]++;
        }
        ans++;
      } else {
        if (a[id] == b[id]) must[id] = true;
        if (flag != 1) {
          flag = 1;
          kn[flag]++;
        }
      }
      id = pa[id];
    }
  }
  if (kn[1] == 0) cir[pos_a[0]] = false;
  int fir = 1e9, sec = 1e9;
  id1 = id2 = -1;
  for (i = 0; i < n; i++) {
    if (cir[i] && (a[i] != b[i] || must[i])) {
      if (fir > deep[i]) {
        sec = fir;
        fir = deep[i];
        id2 = id1;
        id1 = i;
      } else if (sec > deep[i]) {
        sec = deep[i];
        id2 = i;
      }
    }
  }
  if (kn[0] > 2 || kn[1] > 1) {
    puts("-1");
    return 0;
  }
  for (i = 0; i < n; i++) {
    if (cir[i] && (a[i] != b[i] || must[i])) break;
  }
  if (i < n) {
    int ip1 = id1, ip2 = id2;
    bool you = false;
    if (id1 >= 0 && id2 >= 0) {
      while (id1 != id2) {
        if (deep[id1] > deep[id2])
          id1 = pa[id1];
        else
          id2 = pa[id2];
      }
    }
    if (id1 == ip1 || id1 == ip2) you = true;
    id = pos_b[0];
    ip = -1;
    bool fin = false;
    while (true) {
      if ((cir[id] && ip < 0) || id1 == id) {
        ip = id;
        fin = true;
        break;
      }
      if (id == pos_a[0]) break;
      id = pa[id];
    }
    if (!fin) {
      if (a[id1] != b[id1]) {
        if (!you) {
          puts("-1");
          return 0;
        }
        while (cir[id1] && a[id1] != b[id1]) id1 = pa[id1];
        if (!cir[id1]) {
          fin = true;
          ip = id1;
        }
      }
    }
    root = id1;
    cir[id1] = true;
    cnt_list = 0;
    xp = 0;
    if (!got(id1)) {
      puts("-1");
      return 0;
    }
    for (i = xp; i < cnt_list + xp - 1 - i; i++)
      swap(cir_list[i], cir_list[cnt_list + xp - 1 - i]);
    memset(pos, -1, sizeof(pos));
    for (i = 0; i < cnt_list; i++) pos[cir_list[i]] = i;
    if (ip >= 0)
      ip = pos[ip];
    else
      ip = 0;
    for (i = 0; i < n; i++) {
      if (cir[i] && (a[i] != b[i] || must[i]) && pos[i] < 0) {
        puts("-1");
        return 0;
      }
    }
    long long dx = 1e18;
    for (int fg = 0; fg < 2; fg++) {
      if (fg == 1) {
        for (i = 1; i < cnt_list - i; i++)
          swap(cir_list[i], cir_list[cnt_list - i]);
        for (i = 1; i < cnt_list; i++) pos[cir_list[i]] = i;
        if (ip >= 0) ip = (cnt_list - ip) % cnt_list;
      }
      int dl, in = 1e9, ax = -1e9;
      for (i = 0; i < cnt_list; i++) {
        if (i == ip) continue;
        j = cir_list[i];
        id = pos_a[b[j]];
        if (pos[id] < 0) {
          puts("-1");
          return 0;
        }
        dl = ((pos[id] - i) % cnt_list + cnt_list) % cnt_list;
        if (in > dl) in = dl;
        if (ax < dl) ax = dl;
      }
      if (ax - in <= 1) {
        long long th = (long long)(cnt_list - 1) * (long long)in;
        id = (cnt_list - in) % cnt_list;
        th = th + (ip - id + cnt_list) % cnt_list;
        dx = min(dx, th);
      }
      if (fg == 1) {
        for (i = 1; i < cnt_list - i; i++)
          swap(cir_list[i], cir_list[cnt_list - i]);
      }
    }
    if (dx == 1e18) {
      puts("-1");
      return 0;
    }
    ans += dx;
    if (!fin) {
      id = cir_list[0];
      while (id != pos_a[0] && cir[id]) {
        id = pa[id];
        ans += 2;
      }
    }
    u = cir_list[xp % cnt_list] + 1;
    v = cir_list[(xp - 1 + cnt_list) % cnt_list] + 1;
    if (u > v) swap(u, v);
    printf("%d %d %I64d\n", u, v, ans);
  } else
    printf("0 %I64d\n", ans);
  return 0;
}
