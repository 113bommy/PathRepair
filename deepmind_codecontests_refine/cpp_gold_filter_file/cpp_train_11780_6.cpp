#include <bits/stdc++.h>
int kx[8] = {+2, +2, -2, -2, +1, +1, -1, -1};
int ky[8] = {+1, -1, +1, -1, +2, -2, +2, -2};
int d9x[9] = {+1, +1, +1, +0, +0, +0, -1, -1, -1};
int d9y[9] = {+1, +0, -1, +1, +0, -1, +1, +0, -1};
int dx4[4] = {+0, +0, +1, -1};
int dy4[4] = {+1, -1, +0, +0};
long long int gcd(unsigned long long int a, unsigned long long int b) {
  return (a == 0) ? b : gcd(b % a, a);
}
long long int lcm(unsigned long long int a, unsigned long long int b) {
  return a * (b / gcd(a, b));
}
const long long INF = 1e18;
using namespace std;
int n, m, q;
int end_loop[200005];
int L[200005 * 4], R[200005 * 4], seg[200005 * 4];
vector<int> adj[200005 + 1];
vector<int> path;
void dfs(int at) {
  path.push_back(at);
  if ((int)path.size() - n > 0) {
    end_loop[at] = path[(int)path.size() - n];
  }
  for (int to : adj[at]) {
    dfs(to);
  }
  path.pop_back();
  return;
}
void build(int at, int l, int r) {
  L[at] = l;
  R[at] = r;
  int M = l + (r - l) / 2;
  if (l == r) {
    seg[at] = ((end_loop[l] == -1) ? 200005 : end_loop[l]);
    return;
  }
  build(at * 2, l, M);
  build(at * 2 + 1, M + 1, r);
  seg[at] = min(seg[at * 2], seg[at * 2 + 1]);
  return;
}
int mrq(int at, int l, int r) {
  if (L[at] >= l && r >= R[at]) {
    return seg[at];
  }
  int M = L[at] + (R[at] - L[at]) / 2;
  int res = 200005 + 1;
  if (l <= M) {
    res = min(res, mrq(at * 2, l, r));
  }
  if (r >= M + 1) {
    res = min(res, mrq(at * 2 + 1, l, r));
  }
  return res;
}
int main() {
  cin >> n >> m >> q;
  int a[n], b[m], match[n];
  int first[n];
  memset(first, -1, sizeof(first));
  memset(end_loop, -1, sizeof(end_loop));
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
    if (i > 0) {
      match[a[i - 1]] = a[i];
    }
  }
  match[a[n - 1]] = a[0];
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
    --b[i];
  }
  for (int i = m - 1; ~i; --i) {
    first[b[i]] = i;
    int par;
    if (first[match[b[i]]] == -1) {
      par = 200005;
    } else {
      par = first[match[b[i]]];
    }
    adj[par].push_back(i);
  }
  dfs(200005);
  build(1, 0, m - 1);
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    if (n == 1) {
      cout << 1;
      continue;
    }
    int res = mrq(1, l, r);
    cout << (res <= r);
  }
  cout << endl;
}
