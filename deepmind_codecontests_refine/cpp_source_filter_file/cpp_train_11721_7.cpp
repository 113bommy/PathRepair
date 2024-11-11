#include <bits/stdc++.h>
using namespace std;
bool check(long long n, long long pos) { return n & (1LL << pos); }
long long Set(long long n, long long pos) { return n = n | (1LL << pos); }
void test() {
  long long cnt = 0;
  long long n = (1e5);
  for (long long i = 1; i <= n; i++) {
    cnt += (n / i);
  }
  cout << cnt << "\n";
}
struct node {
  node *left, *right;
  long long val;
  node(long long a = 0, node *b = NULL, node *c = NULL)
      : val(a), left(b), right(c) {}
  void build(long long l, long long r) {
    if (l == r) return;
    left = new node();
    right = new node();
    long long mid = l + r >> 1;
    left->build(l, mid);
    right->build(mid + 1, r);
  }
  node *update(long long l, long long r, long long idx, long long v) {
    if (r < idx || l > idx) return this;
    if (l == r) {
      node *ret = new node(val, left, right);
      ret->val += v;
      return ret;
    }
    long long mid = l + r >> 1;
    node *ret = new node(val);
    ret->left = left->update(l, mid, idx, v);
    ret->right = right->update(mid + 1, r, idx, v);
    ret->val = ret->left->val + ret->right->val;
    return ret;
  }
  long long query(long long l, long long r, long long v) {
    if (l == r) {
      return l;
    }
    long long mid = l + r >> 1;
    if (left->val >= v)
      return left->query(l, mid, v);
    else
      return right->query(mid + 1, r, v - (left->val));
  }
} * root[100005];
long long val[100005];
vector<long long> g[100005];
long long bs(long long last, long long idx) {
  long long lo = 0;
  long long hi = g[idx].size() - 1;
  long long ret = -1;
  while (lo <= hi) {
    long long mid = (lo + hi) / 2;
    if (g[idx][mid] > last) {
      ret = g[idx][mid];
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  return ret;
}
int main() {
  long long i, j, k, l, m, n, o, r, q;
  long long testcase;
  long long input, flag, tag, ans;
  while (cin >> n) {
    root[1] = new node();
    root[1]->build(1, n);
    for (long long i = 1; i <= n; i++) {
      cin >> val[i];
      if (g[val[i]].empty()) root[1] = root[1]->update(1, n, i, 1);
      g[val[i]].push_back(i);
    }
    for (long long i = 1; i <= n; i++) {
      root[i + 1] = root[i]->update(1, n, i, -1);
      long long pos = bs(i, val[i]);
      if (pos != -1) root[i + 1] = root[i + 1]->update(1, n, pos, 1);
    }
    for (long long i = 9; i <= 9; i++) {
      long long now = 1;
      ans = 0;
      while (now <= n) {
        ans++;
        if (root[now]->val <= i) break;
        now = root[now]->query(1, n, i + 1);
      }
      cout << ans << " ";
    }
    cout << endl;
  }
}
