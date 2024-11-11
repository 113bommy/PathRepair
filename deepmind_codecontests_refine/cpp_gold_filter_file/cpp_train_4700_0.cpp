#include <bits/stdc++.h>
using namespace std;
const int N_MAX = 1e6 + 1;
int n, k, a[N_MAX], E[2 * N_MAX], fE[N_MAX], lE[N_MAX];
stack<int> st;
vector<int> G[N_MAX];
bool visited[N_MAX];
int Elen = 0;
void DFS(int u) {
  E[Elen++] = u;
  visited[u] = true;
  for (int v : G[u]) {
    if (visited[v]) continue;
    DFS(v);
    E[Elen++] = u;
  }
}
int arr[2 * N_MAX], F[2 * N_MAX], lazy[2 * N_MAX];
void pass_lazy(int a, int b) {
  int k = (a + b) / 2;
  F[k] += lazy[k];
  if (a == k)
    arr[a] += lazy[k];
  else
    lazy[(a + k) / 2] += lazy[k];
  if (k + 1 == b)
    arr[b] += lazy[k];
  else
    lazy[(b + k + 1) / 2] += lazy[k];
  lazy[k] = 0;
}
int add(int a, int b, int i, int j, int val) {
  if (a == b) {
    arr[a] += val;
    return arr[a];
  }
  int k = (a + b) / 2;
  if (a == i && b == j) {
    lazy[k] += val;
    return F[k] + lazy[k];
  }
  if (lazy[k] != 0) pass_lazy(a, b);
  if (j <= k)
    F[k] =
        max(add(a, k, i, j, val),
            (k + 1 == b ? arr[b] : F[(b + k + 1) / 2] + lazy[(b + k + 1) / 2]));
  else if (k + 1 <= i)
    F[k] = max((a == k ? arr[a] : F[(a + k) / 2] + lazy[(a + k) / 2]),
               add(k + 1, b, i, j, val));
  else
    F[k] = max(add(a, k, i, k, val), add(k + 1, b, k + 1, j, val));
  return F[k];
}
int query(int a, int b, int i, int j) {
  if (a == b) return arr[a];
  int k = (a + b) / 2;
  if (lazy[k] != 0) pass_lazy(a, b);
  if (a == i && b == j) return F[k];
  if (j <= k) return query(a, k, i, j);
  if (k + 1 <= i) return query(k + 1, b, i, j);
  return max(query(a, k, i, k), query(k + 1, b, k + 1, j));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  a[n] = 1e6 + 1;
  st.push(n);
  for (int i = n - 1; 0 <= i; i--) {
    while (a[st.top()] <= a[i]) st.pop();
    G[i].push_back(st.top());
    G[st.top()].push_back(i);
    st.push(i);
  }
  DFS(n);
  for (int i = 0; i < Elen; i++) lE[E[i]] = i;
  for (int i = Elen - 1; 0 <= i; i--) fE[E[i]] = i;
  for (int i = 0; i < n; i++) {
    add(0, Elen - 1, fE[i], lE[i], 1);
    if (k <= i) add(0, Elen - 1, fE[i - k], lE[i - k], -1);
    if (k - 1 <= i) cout << query(0, Elen - 1, 0, Elen - 1) << " ";
  }
  cout << endl;
  return 0;
}
