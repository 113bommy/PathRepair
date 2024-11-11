#include <bits/stdc++.h>
using namespace std;
const int RAGETREE_SZ = 1 << 17;
int ragetreemin[2 * RAGETREE_SZ];
int ragetreecnt[2 * RAGETREE_SZ];
long long ragetreeinc[2 * RAGETREE_SZ];
long long ragetreeans[2 * RAGETREE_SZ];
int ragetreelazy[2 * RAGETREE_SZ];
void apply(int idx, int val) {
  ragetreemin[idx] += val;
  if (idx < RAGETREE_SZ) {
    ragetreelazy[idx] += val;
  }
}
void pushdown(int idx) {
  if (ragetreelazy[idx]) {
    apply(2 * idx, ragetreelazy[idx]);
    apply(2 * idx + 1, ragetreelazy[idx]);
    ragetreelazy[idx] = 0;
  }
  if (ragetreeinc[idx]) {
    if (ragetreemin[2 * idx] == ragetreemin[idx]) {
      ragetreeans[2 * idx] += ragetreeinc[idx] * ragetreecnt[2 * idx];
      ragetreeinc[2 * idx] += ragetreeinc[idx];
    }
    if (ragetreemin[2 * idx + 1] == ragetreemin[idx]) {
      ragetreeans[2 * idx + 1] += ragetreeinc[idx] * ragetreecnt[2 * idx + 1];
      ragetreeinc[2 * idx + 1] += ragetreeinc[idx];
    }
    ragetreeinc[idx] = 0;
  }
}
void pullup(int idx) {
  ragetreemin[idx] = min(ragetreemin[2 * idx], ragetreemin[2 * idx + 1]);
  ragetreecnt[idx] = 0;
  if (ragetreemin[idx] == ragetreemin[2 * idx])
    ragetreecnt[idx] += ragetreecnt[2 * idx];
  if (ragetreemin[idx] == ragetreemin[2 * idx + 1])
    ragetreecnt[idx] += ragetreecnt[2 * idx + 1];
}
void upd(int idx, int pos, int sz, int lhs, int rhs, int v) {
  int clhs = pos;
  int crhs = pos + sz - 1;
  if (clhs > rhs || crhs < lhs) return;
  if (clhs >= lhs && crhs <= rhs) {
    apply(idx, v);
    return;
  }
  pushdown(idx);
  upd(2 * idx, pos, sz / 2, lhs, rhs, v);
  upd(2 * idx + 1, pos + sz / 2, sz / 2, lhs, rhs, v);
  pullup(idx);
}
void upd(int lhs, int rhs, int val) { upd(1, 0, RAGETREE_SZ, lhs, rhs, val); }
long long qry(int idx, int pos, int sz, int lhs, int rhs) {
  int clhs = pos;
  int crhs = pos + sz - 1;
  if (clhs > rhs || crhs < lhs) return 0;
  if (clhs >= lhs && crhs <= rhs) {
    return ragetreeans[idx];
  }
  long long ret = 0;
  pushdown(idx);
  ret += qry(2 * idx, pos, sz / 2, lhs, rhs);
  ret += qry(2 * idx + 1, pos + sz / 2, sz / 2, lhs, rhs);
  pullup(idx);
  return ret;
}
long long qry(int lhs, int rhs) { return qry(1, 0, RAGETREE_SZ, lhs, rhs); }
int l[RAGETREE_SZ];
int n;
vector<pair<int, int> > queries[RAGETREE_SZ];
int ret[RAGETREE_SZ];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l[i];
    ragetreecnt[RAGETREE_SZ + i] = 1;
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int lhs, rhs;
    cin >> lhs >> rhs;
    queries[rhs].push_back({lhs, i});
  }
  stack<pair<int, int> > maxstack, minstack;
  maxstack.push({0, 1e8});
  minstack.push({0, -1e8});
  for (int rhs = 1; rhs <= n; rhs++) {
    while (maxstack.top().second < l[rhs]) {
      pair<int, int> curr = maxstack.top();
      maxstack.pop();
      upd(maxstack.top().first + 1, curr.first, -curr.second);
    }
    upd(maxstack.top().first + 1, rhs, l[rhs]);
    maxstack.push({rhs, l[rhs]});
    while (minstack.top().second > l[rhs]) {
      pair<int, int> curr = minstack.top();
      minstack.pop();
      upd(minstack.top().first + 1, curr.first, curr.second);
    }
    upd(minstack.top().first + 1, rhs, -l[rhs]);
    minstack.push({rhs, l[rhs]});
    upd(1, rhs, -1);
    ragetreeinc[1]++;
    ragetreeans[1] += ragetreecnt[1];
    for (pair<int, int> out : queries[rhs]) {
      ret[out.second] = qry(out.first, rhs);
    }
  }
  for (int i = 0; i < q; i++) cout << ret[i] << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
