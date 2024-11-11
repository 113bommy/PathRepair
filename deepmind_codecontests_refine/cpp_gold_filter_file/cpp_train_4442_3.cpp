#include <bits/stdc++.h>
using namespace std;
const int Max = 2e5 + 10;
const int Mod = 1e9 + 7;
const long long int Inf = 1LL << 62;
long long int ar[Max];
long long int br[Max];
long long int nxt[Max];
long long int seg[Max * 4];
vector<long long int> vec[Max];
void calc(int node, int left, int right) {
  if (left == right) {
    seg[node] = nxt[left];
    return;
  }
  int mid = (left + right) >> 1;
  int lf = node * 2;
  int rt = node * 2 + 1;
  calc(lf, left, mid);
  calc(rt, mid + 1, right);
  seg[node] = min(seg[lf], seg[rt]);
}
int query(int node, int left, int right, int L, int R) {
  if (R < left || L > right) {
    return 1e9;
  }
  if (L <= left && right <= R) {
    return seg[node];
  }
  int mid = (left + right) >> 1;
  int u = query(node * 2, left, mid, L, R);
  int v = query(node * 2 + 1, mid + 1, right, L, R);
  return min(u, v);
}
int update(int node, int left, int right, int idx, int val) {
  if (right == left) {
    seg[node] = val;
    return seg[node];
  }
  int mid = (left + right) >> 1, u = seg[node * 2], v = seg[node * 2 + 1];
  if (mid >= idx) {
    u = update(2 * node, left, mid, idx, val);
  } else {
    v = update(2 * node + 1, mid + 1, right, idx, val);
  }
  return seg[node] = min(u, v);
}
int main() {
  long long int n, m, t, k, q;
  while (~scanf("%lld %lld", &n, &m)) {
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &ar[i]);
    }
    long long int cur = -1, sum = 0, tot = 0;
    for (int i = 1; i <= m; i++) {
      scanf("%lld", &br[i]);
      sum += br[i];
      nxt[i] = 1e9;
      if (br[i]) {
        tot++;
      }
    }
    int mn = 1e9;
    long long int cnt = 0;
    calc(1, 1, m);
    for (int i = 1; i <= n; i++) {
      if (!br[ar[i]]) {
        continue;
      }
      vec[ar[i]].push_back(i);
      if (vec[ar[i]].size() == br[ar[i]]) {
        cnt++;
      }
      if (vec[ar[i]].size() >= br[ar[i]]) {
        long long int x = vec[ar[i]][vec[ar[i]].size() - br[ar[i]]];
        update(1, 1, m, ar[i], x);
      }
      if (cnt == tot) {
        mn = min((1 + i - query(1, 1, m, 1, m)) - sum, (long long int)mn);
      }
    }
    if (mn == 1e9) {
      mn = -1;
    }
    printf("%d\n", mn);
    cerr << "--------------------" << endl;
  }
  return 0;
}
