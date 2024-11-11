#include <bits/stdc++.h>
using namespace std;
const int mod = (1e9) + 7;
const int siz = 2e5 + 5, siz2 = 105e4 + 5;
int n, centroid, mn, last, lim = 1 << 19, treesz[siz], dfsnodes[siz],
                           dfsmasks[siz], parent[siz], mask[siz2];
pair<int, int> lims[siz];
vector<int> adj[siz];
char arr[siz];
bool done[siz];
long long ans[siz], curans[siz];
void calcsz(int node, int par) {
  treesz[node] = 1;
  int sz = adj[node].size(), mx = INT_MIN;
  for (int i = 0; i < sz; i++) {
    int nex = adj[node][i];
    if (!done[nex] && nex != par) {
      calcsz(nex, node);
      treesz[node] += treesz[nex];
    }
  }
}
void getcentroid(int node, int par, int tot) {
  while (true) {
    int mx = tot - treesz[node], mxnode = node;
    int sz = adj[node].size();
    for (int i = 0; i < sz; i++) {
      int nex = adj[node][i];
      if (!done[nex] && nex != par) {
        if (treesz[nex] > mx) {
          mx = treesz[nex];
          mxnode = nex;
        }
      }
    }
    if (mx < mn) {
      mn = mx;
      centroid = node;
    }
    if (node == mxnode) return;
    par = node;
    node = mxnode;
  }
}
void calcmask(int node, int par, int parmask) {
  int curmask = (1 << arr[node]) ^ parmask;
  dfsnodes[last] = node;
  dfsmasks[last++] = curmask;
  parent[node] = par;
  mask[curmask]++;
  int sz = adj[node].size();
  for (int i = 0; i < sz; i++) {
    int nex = adj[node][i];
    if (!done[nex] && nex != par) {
      calcmask(nex, node, curmask);
    }
  }
}
void calcans(int l, int r) {
  int centmask = (1 << arr[centroid]);
  for (int i = l; i <= r; i++) {
    mask[dfsmasks[i]]--;
  }
  for (int i = r; i >= l; i--) {
    int node = dfsnodes[i], wocent = dfsmasks[i] ^ centmask;
    curans[node] += mask[wocent];
    for (int i = 1; i <= lim; i <<= 1) {
      int val = wocent ^ i;
      curans[node] += mask[val];
    }
    curans[parent[node]] += curans[node];
    ans[node] += curans[node];
    curans[node] = 0;
  }
  for (int i = l; i <= r; i++) {
    mask[dfsmasks[i]]++;
  }
}
void clearmask() {
  int centmask = (1 << arr[centroid]);
  mask[centmask] = 0;
  for (int i = 0; i < last; i++) mask[dfsmasks[i]] = 0;
}
void solve(int start) {
  stack<int> st;
  st.push(start);
  while (st.size() != 0) {
    int cur = st.top();
    st.pop();
    calcsz(cur, 0);
    mn = INT_MAX;
    getcentroid(cur, 0, treesz[cur]);
    int centmask = (1 << arr[centroid]);
    mask[centmask]++;
    int sz = adj[centroid].size();
    int c = 0;
    for (int i = 0; i < sz; i++) {
      int node = adj[centroid][i];
      if (!done[node]) {
        calcmask(node, centroid, centmask);
        lims[c] = {c ? lims[c - 1].second + 1 : 0, last - 1};
        c++;
      }
    }
    for (int i = c - 1; i >= 0; i--) {
      int l = lims[i].first, r = lims[i].second;
      calcans(l, r);
    }
    curans[centroid] += mask[0];
    for (int i = 1; i <= lim; i <<= 1) {
      curans[centroid] += mask[i];
    }
    curans[centroid]++;
    ans[centroid] += curans[centroid] / 2;
    curans[centroid] = 0;
    clearmask();
    last = 0;
    done[centroid] = true;
    for (int i = 0; i < sz; i++) {
      int node = adj[centroid][i];
      if (!done[node]) {
        st.push(node);
      }
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  scanf("%s", arr + 1);
  int sz = strlen(arr + 1);
  for (int i = 1; i < sz; i++) arr[i] -= 97;
  solve(1);
  for (int i = 1; i <= n; i++) {
    printf("%I64d", ans[i]);
    if (i != n)
      printf(" ");
    else
      printf("\n");
  }
  return 0;
}
