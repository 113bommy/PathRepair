#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long inf = 1LL << 50;
const int N = 200000;
struct lazySegTreeMax {
  int* tree;
  int len;
  vector<int> lazy;
  lazySegTreeMax(const vector<int>& input, int l)
      : lazy(2 * (int)pow(2, ceil(log2(l))) - 1, 0) {
    int le = 2 * (int)pow(2, ceil(log2(l))) - 1;
    tree = new int[le];
    len = l;
    constructTree(0, len - 1, 0, input);
  }
  void constructTree(int low, int high, int pos, const vector<int>& input) {
    if (low == high) {
      tree[pos] = input[low];
      return;
    }
    int mid = (low + high) / 2;
    constructTree(low, mid, pos * 2 + 1, input);
    constructTree(mid + 1, high, pos * 2 + 2, input);
    tree[pos] = max(tree[pos * 2 + 2], tree[pos * 2 + 1]);
  }
  int query(int low, int high) { return rangeMax(low, high, 0, len - 1, 0); }
  int rangeMax(int qlow, int qhigh, int low, int high, int pos) {
    if (qlow > high || low > qhigh) {
      return -2147483640;
    }
    if (lazy[pos] != 0) {
      tree[pos] += lazy[pos];
      if (low != high) {
        lazy[pos * 2 + 1] += lazy[pos];
        lazy[pos * 2 + 2] += lazy[pos];
      }
      lazy[pos] = 0;
    }
    if (qlow <= low && qhigh >= high) {
      return tree[pos];
    }
    int mid = (low + high) / 2;
    return max(rangeMax(qlow, qhigh, low, mid, pos * 2 + 1),
               rangeMax(qlow, qhigh, mid + 1, high, pos * 2 + 2));
  }
  void update(int ql, int qh, int incr) { update(incr, ql, qh, 0, len - 1, 0); }
  void update(int incr, int ql, int qh, int low, int high, int pos) {
    if (lazy[pos] != 0) {
      tree[pos] += lazy[pos];
      if (low != high) {
        lazy[pos * 2 + 1] += lazy[pos];
        lazy[pos * 2 + 2] += lazy[pos];
      }
      lazy[pos] = 0;
    }
    if (ql > high || low > qh) {
      return;
    }
    if (ql <= low && high <= qh) {
      tree[pos] += incr;
      if (low != high) {
        lazy[pos * 2 + 2] += incr;
        lazy[pos * 2 + 1] += incr;
      }
      return;
    }
    int mid = (low + high) / 2;
    update(incr, ql, qh, low, mid, pos * 2 + 1);
    update(incr, ql, qh, mid + 1, high, pos * 2 + 2);
    tree[pos] = max(tree[pos * 2 + 1], tree[pos * 2 + 2]);
  }
  int search(int bound) { return search(bound, 0, len - 1, 0); }
  int search2(int bound) { return search2(bound, 0, len - 1, 0); }
  int search(int bound, int low, int high, int pos) {
    if (lazy[pos] != 0) {
      tree[pos] += lazy[pos];
      if (low != high) {
        lazy[pos * 2 + 1] += lazy[pos];
        lazy[pos * 2 + 2] += lazy[pos];
      }
      lazy[pos] = 0;
    }
    if (tree[pos] <= 0) {
      return -1;
    }
    if (low == high) {
      return low;
    }
    int mid = (low + high) >> 1;
    if (mid >= bound) {
      int ret = search(bound, low, mid, pos * 2 + 1);
      if (ret != -1) {
        return ret;
      }
    }
    return search(bound, mid + 1, high, pos * 2 + 2);
  }
  int search2(int bound, int low, int high, int pos) {
    if (lazy[pos] != 0) {
      tree[pos] += lazy[pos];
      if (low != high) {
        lazy[pos * 2 + 1] += lazy[pos];
        lazy[pos * 2 + 2] += lazy[pos];
      }
      lazy[pos] = 0;
    }
    if (tree[pos] < 0) {
      return -1;
    }
    if (low == high) {
      return low;
    }
    int mid = (low + high) >> 1;
    if (mid >= bound) {
      int ret = search2(bound, low, mid, pos * 2 + 1);
      if (ret != -1) {
        return ret;
      }
    }
    return search2(bound, mid + 1, high, pos * 2 + 2);
  }
};
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin.exceptions(cin.failbit);
  int n, k, m;
  cin >> n >> k >> m;
  int len = n + max(m, n) + 5;
  vector<int> input(len);
  for (int i = 0; i < len; i++) {
    input[i] = 1;
  }
  lazySegTreeMax st(input, len);
  set<long long> s;
  set<pair<int, long long> > mxes;
  k--;
  for (int i = 0; i < m; i++) {
    long long x, y;
    cin >> x >> y;
    x--;
    y--;
    int meet = abs(x - k) + y;
    if (s.count(y * n + x)) {
      s.erase(y * n + x);
      mxes.erase({meet, y * n + x});
      int ind = st.search2(meet);
      st.update(meet, ind, 1);
    } else {
      s.insert(y * n + x);
      mxes.insert({meet, y * n + x});
      int ind = st.search(meet);
      st.update(meet, ind, -1);
    }
    if (s.size()) {
      int mx = (*(--mxes.end())).first;
      cout << max(st.search2(mx) - n + 1, 0) << "\n";
    } else {
      cout << "0\n";
    }
  }
}
