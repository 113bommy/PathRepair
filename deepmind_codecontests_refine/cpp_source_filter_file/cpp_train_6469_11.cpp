#include <bits/stdc++.h>
using namespace std;
struct ST {
  int l, r, m;
  long long sum, mx;
  bool prop = 0;
  ST *left, *right;
  ST(const vector<long long>& a, int L, int R) : l(L), r(R), m((L + R) / 2) {
    if (L == R) {
      sum = mx = a[L];
    } else {
      left = new ST(a, L, m);
      right = new ST(a, m + 1, R);
      sum = left->sum + right->sum;
      mx = max(left->mx, right->mx);
    }
  }
  ~ST() {
    if (l != r) {
      delete left;
      delete right;
    }
  }
  void push() {
    if (!prop || l == r) {
      return;
    }
    left->mx = mx;
    left->sum = (m - l + 1) * mx;
    left->prop = 1;
    right->mx = mx;
    right->sum = (r - m) * mx;
    right->prop = 1;
    prop = 0;
  }
  long long get(int L, int R) {
    if (L > R) {
      return 0;
    }
    if (l == L && r == R) {
      return sum;
    }
    push();
    return left->get(L, min(m, R)) + right->get(max(m + 1, L), R);
  }
  void upd(int i, int x) {
    if (l == r) {
      assert(l == i);
      sum += x;
      mx += x;
    } else {
      push();
      if (i <= m) {
        left->upd(i, x);
      } else {
        right->upd(i, x);
      }
      sum = left->sum + right->sum;
      mx = max(left->mx, right->mx);
    }
  }
  void set_max(int L, int R, long long x) {
    if (L > R) {
      return;
    }
    push();
    if (l == L && r == R) {
      mx = x;
      sum = x * (r - l + 1);
      prop = 1;
    } else {
      left->set_max(L, min(m, R), x);
      right->set_max(max(m + 1, L), R, x);
      sum = left->sum + right->sum;
      mx = max(left->mx, right->mx);
    }
  }
  int lower_bound(long long x) {
    if (l == r) {
      return l;
    }
    push();
    if (left->mx >= x) {
      return left->lower_bound(x);
    } else {
      return right->lower_bound(x);
    }
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < int(n); i++) {
    cin >> a[i];
  }
  vector<long long> k(n - 1);
  for (int i = 0; i < int(n - 1); i++) {
    cin >> k[i];
  }
  vector<long long> t(n);
  for (int i = 0; i < int(n - 1); i++) {
    t[i + 1] = t[i] + k[i];
  }
  vector<long long> pre_t(n + 1);
  for (int i = 0; i < int(n); i++) {
    pre_t[i + 1] = pre_t[i] + t[i];
  }
  vector<long long> b(n);
  for (int i = 0; i < int(n); i++) {
    b[i] = a[i] - t[i];
  }
  ST* root = new ST(b, 0, n - 1);
  int Q;
  cin >> Q;
  while (Q--) {
    char c;
    cin >> c;
    if (c == '+') {
      int i, x;
      cin >> i >> x;
      i--;
      int pos;
      int now = root->get(i, i) + x;
      if (root->mx < now) {
        pos = n;
      } else {
        pos = root->lower_bound(now);
      }
      root->set_max(i, pos - 1, now);
    } else if (c == 's') {
      int L, R;
      cin >> L >> R;
      L--, R--;
      cout << root->get(L, R) + pre_t[R + 1] - pre_t[L] << "\n";
    } else
      assert(0);
  }
  delete root;
}
