#include <bits/stdc++.h>
const double eps = (1e-9);
using namespace std;
int dcmp(double a, double b) {
  return fabs(a - b) <= eps ? 0 : (a > b) ? 1 : -1;
}
int getBit(int num, int idx) { return ((num >> idx) & 1) == 1; }
int setBit1(int num, int idx) { return num | (1 << idx); }
long long setBit0(long long num, int idx) { return num & ~(1ll << idx); }
long long flipBit(int num, int idx) { return num ^ (1 << idx); }
void FS() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int N = 100009;
vector<vector<int> > v(N);
int n, root, level[N], A[N];
bool ok, vis[N];
queue<int> q;
map<int, int> st, B;
bool canbe_1(int node) {
  while (((int)(q).size()) > 0) q.pop();
  memset(vis, 0, sizeof(vis));
  q.push(node);
  vis[node] = 1;
  while (!q.empty()) {
    int siz = ((int)(q).size());
    int lim = -1;
    while (siz--) {
      int cur = q.front();
      q.pop();
      for (int i = 0; i < ((int)(v[cur]).size()); i++) {
        int nw = v[cur][i];
        if (vis[nw]) continue;
        vis[nw] = 1;
        if (lim == -1)
          lim = ((int)(v[nw]).size());
        else if (((int)(v[nw]).size()) != lim)
          return 0;
        q.push(nw);
      }
    }
  }
  return 1;
}
int get_end(int node, int p) {
  int in = 0;
  for (int i = 0; i < ((int)(v[node]).size()); i++) {
    int nw = v[node][i];
    if (nw == p) continue;
    in = 1;
    return get_end(nw, node);
  }
  if (in == 0) return node;
}
void update(int p, int node) {
  int ans = 0;
  for (int i = 0; i < ((int)(v[node]).size()); i++) {
    int nw = v[node][i];
    if (nw == p) continue;
    ans = max(ans, level[nw] + 1);
  }
  level[node] = ans;
}
bool go1(int node, int ex) {
  B.clear();
  st.clear();
  int cnt = 0, my_node = -1;
  for (int i = 0; i < ((int)(v[node]).size()); i++) {
    int nw = v[node][i];
    cnt++;
    if (A[nw] == 1 && nw != ex) {
      my_node = nw;
    }
    if (nw != ex) B[level[nw]] = nw;
    st[level[nw]]++;
  }
  if (((int)(st).size()) == 1) {
    bool ret = canbe_1(node);
    if (ret == 1) {
      root = node;
      return 1;
    }
    if (cnt > 1) {
      int res = my_node;
      if (res != -1) {
        root = get_end(res, node);
        return 1;
      }
      root = -1;
      return 1;
    } else {
      if (v[node][0] == ex) {
        root = node;
        return 1;
      } else {
        root = v[node][0];
        update(v[node][0], node);
        return 0;
      }
    }
  } else if (((int)(st).size()) > 2) {
    root = -1;
    return 1;
  } else if (((int)(st).size()) == 2) {
    if (cnt > 2) {
      int d1, d2, c1, c2;
      d1 = (*st.begin()).first;
      c1 = (*st.begin()).second;
      st.erase(st.begin());
      d2 = (*st.begin()).first;
      c2 = (*st.begin()).second;
      if (c1 == 1 && B[d1] != 0 && (d1 > d2 || A[B[d1]] == 1)) {
        if (d1 > d2) {
          root = B[d1];
          update(B[d1], node);
          return 0;
        } else {
          root = get_end(B[d1], node);
          return 1;
        }
      } else if (c2 == 1 && B[d2] != 0 && (d2 > d1 || A[B[d2]] == 1)) {
        if (d2 > d1) {
          root = B[d2];
          update(B[d2], node);
          return 0;
        } else {
          root = get_end(B[d2], node);
          return 1;
        }
      } else {
        root = -1;
        return 1;
      }
    } else {
      int n1 = v[node][0];
      int n2 = v[node][1];
      if (ex != 0 && n1 != ex) {
        root = n1;
        update(root, node);
        return 0;
      } else if (ex != 0 && n2 != ex) {
        root = n2;
        update(root, node);
        return 0;
      } else {
        if (A[n1] == 1) {
          int f1 = get_end(n1, node);
          bool ret = canbe_1(f1);
          if (ret) {
            root = f1;
            return 1;
          } else {
            root = n2;
            update(root, node);
            return 0;
          }
        }
        if (A[n2] == 1) {
          int f1 = get_end(n2, node);
          bool ret = canbe_1(f1);
          if (ret) {
            root = f1;
            return 1;
          } else {
            root = n1;
            update(root, node);
            return 0;
          }
        }
        if (level[n1] > level[n2]) {
          root = n1;
          update(root, node);
          return 0;
        } else {
          root = n2;
          update(root, node);
          return 0;
        }
      }
    }
  }
}
bool solve(int node, int ex) {
  bool ret = go1(node, ex);
  if (ret == 1) return 1;
  return solve(root, node);
}
int dfs_1(int no, int p) {
  level[no] = 0;
  for (int i = 0; i < ((int)(v[no]).size()); i++) {
    int nw = v[no][i];
    if (nw == p) continue;
    level[no] = max(level[no], dfs_1(nw, no) + 1);
  }
  return level[no];
}
int dfs_2(int no, int p) {
  int in = 0;
  A[no] = 1;
  for (int i = 0; i < ((int)(v[no]).size()); i++) {
    int nw = v[no][i];
    if (nw == p) continue;
    in++;
    A[no] = dfs_2(nw, no);
  }
  if (in <= 1)
    return A[no];
  else
    return A[no] = 0;
}
int main() {
  FS();
  cin >> n;
  if (n == 1) {
    cout << "1\n";
    return 0;
  }
  for (int i = 0; i < n - 1; i++) {
    int f, t;
    cin >> f >> t;
    v[f].push_back(t);
    v[t].push_back(f);
  }
  dfs_1(1, 0);
  dfs_2(1, 0);
  solve(1, 0);
  if (root == -1)
    cout << root << endl;
  else {
    bool ret = canbe_1(root);
    if (ret)
      cout << root << endl;
    else
      cout << "-1" << endl;
  }
}
