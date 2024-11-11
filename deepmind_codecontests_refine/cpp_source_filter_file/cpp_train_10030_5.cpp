#include <bits/stdc++.h>
using namespace std;
int n;
const int MAX_N = 400000;
vector<int> a;
const int MAX_C = 60;
int val[2 * MAX_N];
struct ST {
  struct Node {
    int carry, val;
    bool hasCarry;
    Node() {
      carry = val = 0;
      hasCarry = 0;
    }
    Node(int v) {
      carry = 0;
      val = v;
      hasCarry = 0;
    }
    void upd1(int v) {
      carry += v;
      val += v;
      hasCarry = true;
    }
  };
  Node join(const Node &p1, const Node &p2) {
    Node r = Node(p1.val + p2.val);
    r.carry = p1.carry + p2.carry;
    r.hasCarry = p1.hasCarry | p2.hasCarry;
    return r;
  }
  int N;
  vector<Node> st;
  ST(int n, vector<int> &A) {
    N = n - 1;
    st.resize(4 * n);
    create(1, 0, N, A);
  }
  void create(int n, int l, int r, vector<int> &A) {
    if (l == r)
      st[n] = Node(a[A[l]]);
    else {
      int m = (l + r) / 2;
      create(2 * n, l, m, A);
      create(2 * n + 1, m + 1, r, A);
      st[n] = join(st[2 * n], st[2 * n + 1]);
    }
  }
  Node query(int x, int y, int n, int l, int r) {
    if (x <= l && r <= y)
      return st[n];
    else {
      if (st[n].hasCarry) {
        st[n * 2].upd1(-st[n].carry);
        st[n * 2 + 1].upd1(-st[n].carry);
        st[n].hasCarry = st[n].carry = 0;
      }
      int m = (l + r) / 2;
      if (y <= m) return query(x, y, 2 * n, l, m);
      if (x > m) return query(x, y, 2 * n + 1, m + 1, r);
      return join(query(x, y, 2 * n, l, m), query(x, y, 2 * n + 1, m + 1, r));
    }
  }
  Node query(int x, int y) { return query(x, y, 1, 0, N); }
  void update(int x, int y, int v, int n, int l, int r) {
    if (x <= l && r <= y)
      st[n].upd1(v);
    else {
      if (st[n].hasCarry) {
        st[n * 2].upd1(-st[n].carry);
        st[n * 2 + 1].upd1(-st[n].carry);
        st[n].hasCarry = st[n].carry = 0;
      }
      int m = (l + r) / 2;
      if (x <= m) update(x, y, v, 2 * n, l, m);
      if (y > m) update(x, y, v, 2 * n + 1, m + 1, r);
      st[n] = join(st[2 * n], st[2 * n + 1]);
    }
  }
  void update(int x, int y, int v) { update(x, y, v, 1, 0, N); }
};
vector<int> et, adj[MAX_N];
int IN[MAX_N], OUT[MAX_N];
void dfs(int u, int p = -1) {
  IN[u] = et.size();
  et.push_back(u);
  for (int v : adj[u]) {
    if (v != p) dfs(v, u);
  }
  OUT[u] = et.size();
  et.push_back(u);
}
int main() {
  int a, b, c;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  if (min(a, b) > 2 * c) {
    cout << "First";
  } else {
    cout << "Second";
  }
}
