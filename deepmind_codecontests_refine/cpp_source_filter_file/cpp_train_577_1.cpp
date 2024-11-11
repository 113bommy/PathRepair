#include <bits/stdc++.h>
using namespace std;
vector<int> V;
int cnt[205], vis[205];
int n, h;
int flag = 0;
vector<int> query(int x) {
  cout << "? " << x << endl;
  int k;
  cin >> k;
  if (!k) exit(0);
  vector<int> ans;
  ans.resize(k);
  for (int i = 0; i < k; i++) cin >> ans[i];
  return ans;
}
int dfs(int u, int pre, int dep) {
  vector<int> tmp = query(u);
  if (tmp.size() == 2) {
    cout << "! " << u << endl;
    flag = 1;
    return 0;
  }
  if (tmp.size() == 1 || dep == h) return tmp.size();
  for (int i = 0; i < tmp.size(); i++)
    if (vis[tmp[i]]) {
      tmp.erase(tmp.begin() + i);
      i--;
    }
  if (tmp.size() >= 2 && tmp[1] != u) return dfs(tmp[1], u, dep + 1);
  return dfs(tmp[0], u, dep + 1);
}
void check(int id, int dep) {
  if (flag) return;
  vector<int> tmp = query(id);
  if (flag) return;
  if (tmp.size() == 2) {
    cout << "! " << id << endl;
    flag = 1;
    return;
  }
  if (dep <= 3) {
    int cnt = 1;
    vis[id] = 1;
    for (int i = 0; i < tmp.size(); i++) {
      if (vis[tmp[i]]) continue;
      if (cnt == 6) {
        flag = 1;
        cout << "! " << tmp[i] << endl;
        return;
      }
      vector<int> tmpp = query(tmp[i]);
      vis[tmp[i]] = 1;
      cnt++;
      if (tmpp.size() == 2) {
        flag = 1;
        cout << "! " << tmp[i] << endl;
        return;
      }
      for (int i = 0; i < tmpp.size(); i++) tmp.push_back(tmpp[i]);
    }
  }
  vis[id] = 1;
  for (int i = 0; i < tmp.size(); i++) {
    if (vis[tmp[i]]) {
      tmp.erase(tmp.begin() + i);
      i--;
      break;
    }
  }
  if (dfs(tmp[0], id, dep + 1) == 1)
    check(tmp[1], dep - 1);
  else
    check(tmp[0], dep - 1);
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> h;
    flag = 0;
    if (!h) return 0;
    memset(vis, 0, sizeof(vis));
    V = query(1);
    if (V.size() == 2) {
      cout << "! 1" << endl;
      continue;
    }
    vis[1] = 1;
    if (V.size() == 1) {
      check(V[0], h - 1);
      continue;
    }
    int a0, a1, a2;
    if (V.size() == 3) {
      a0 = V[0];
      a1 = V[1];
      a2 = V[2];
    }
    int dep = 0;
    while (1) {
      dep++;
      vector<int> tmp1, tmp2;
      tmp1 = query(V[0]), tmp2 = query(V[1]);
      if (tmp1.size() == 2) {
        cout << "! " << V[0] << endl;
        break;
      }
      if (tmp2.size() == 2) {
        cout << "! " << V[1] << endl;
        break;
      }
      if (tmp1.size() == 1 && tmp2.size() == 1) {
        memset(vis, 0, sizeof(vis));
        vis[1] = vis[a0] = vis[a1] = 1;
        check(a2, h - dep - 1);
        break;
      }
      if (tmp1.size() == 1) {
        memset(vis, 0, sizeof(vis));
        vis[1] = vis[a0] = vis[a2] = 1;
        check(a1, h - dep - 1);
        break;
      }
      if (tmp2.size() == 1) {
        memset(vis, 0, sizeof(vis));
        vis[1] = vis[a1] = vis[a2] = 1;
        check(a0, h - dep - 1);
        break;
      }
      vis[V[0]] = vis[V[1]] = 1;
      for (int i = 0; i < tmp1.size(); i++)
        if (vis[tmp1[i]]) tmp1.erase(tmp1.begin() + i), i--;
      for (int i = 0; i < tmp2.size(); i++)
        if (vis[tmp2[i]]) tmp2.erase(tmp2.begin() + i), i--;
      V[0] = tmp1[0];
      V[1] = tmp2[0];
    }
  }
}
