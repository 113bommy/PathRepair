#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
template <class Val>
struct SetSingleSegmentTree {
  vector<Val> V;
  size_t n;
  function<Val(Val, Val)> combine;
  void init(const vector<Val> &A,
            function<Val(Val, Val)> combine = plus<Val>()) {
    n = 1;
    while (n < A.size()) n <<= 1;
    V.assign(n, Val());
    V.insert(V.end(), A.begin(), A.end());
    V.resize(n << 1, Val());
    this->combine = combine;
    for (int i = n - 1; i > 0; i--)
      V[i] = this->combine(V[i << 1], V[i << 1 | 1]);
  }
  void setVal(int p, Val value) {
    for (V[p += n] = value; p > 1; p >>= 1)
      V[p >> 1] = p & 1 ? combine(V[p ^ 1], V[p]) : combine(V[p], V[p ^ 1]);
  }
  Val getRange(int l, int r) {
    Val left = Val();
    Val right = Val();
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) left = combine(left, V[l++]);
      if (r & 1) right = combine(V[--r], right);
    }
    return combine(left, right);
  }
};
struct Node {
  int ans = 0, left = 0, right = 0, length = 1;
};
Node combine(const Node &a, const Node &b) {
  Node ret;
  ret.ans = max(a.ans, b.ans);
  ret.ans = max(ret.ans, a.right + b.left);
  ret.left = a.left;
  ret.right = b.right;
  if (a.left == a.length) ret.left += b.left;
  if (b.right == b.length) ret.right += a.right;
  ret.length = a.length + b.length;
  return ret;
}
const int N = 1e5 + 5;
const int M = 50;
SetSingleSegmentTree<Node> stS[M + 5];
SetSingleSegmentTree<int> st;
string sS[N];
int D[N];
set<PII> S;
vector<int> L;
int dist(const string &s, const string &t) {
  int ret = 0;
  while (ret < s.length() && ret < t.length()) {
    if (s[ret] != t[ret]) return ret;
    ret++;
  }
  return ret;
}
void alter(int p, int oldV, int newV) {
  if (oldV > M) S.erase(make_pair(p, oldV));
  if (newV > M) S.insert(make_pair(p, newV));
  for (int i = (1); i <= (M); i++) {
    Node x;
    if (newV >= i) x.left = x.right = x.ans = 1;
    stS[i].setVal(p, x);
  }
  D[p] = newV;
}
LL solve(const vector<int> &V) {
  vector<int> L(V.size()), R(V.size());
  stack<int> K;
  for (int i = (0); i <= (int((V).size()) - 1); i++) {
    while (!K.empty() && V[K.top()] >= V[i]) K.pop();
    if (K.empty())
      L[i] = 0;
    else
      L[i] = K.top() + 1;
    K.push(i);
  }
  while (!K.empty()) K.pop();
  for (int i = (int((V).size()) - 1); i >= (0); i--) {
    while (!K.empty() && V[K.top()] >= V[i]) K.pop();
    if (K.empty())
      R[i] = int((V).size()) - 1;
    else
      R[i] = K.top() - 1;
    K.push(i);
  }
  LL ret = 0;
  for (int i = (0); i <= (int((V).size()) - 1); i++) {
    ret = max(ret, 1LL * (R[i] - L[i] + 2) * V[i]);
  }
  return ret;
}
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = (1); i <= (n); i++) cin >> sS[i];
  L.push_back(0);
  for (int i = (1); i <= (n); i++) L.push_back(sS[i].length());
  for (int i = (1); i <= (n - 1); i++) {
    D[i] = dist(sS[i], sS[i + 1]);
    if (D[i] > M) {
      S.insert(make_pair(i, D[i]));
    }
  }
  st.init(L, [](int x, int y) { return max(x, y); });
  for (int i = (1); i <= (M); i++) {
    vector<Node> V;
    V.push_back(Node());
    for (int j = (1); j <= (n - 1); j++) {
      if (D[j] >= i) {
        auto x = Node();
        x.ans = x.left = x.right = x.length = 1;
        V.push_back(x);
      } else {
        auto x = Node();
        x.length = 1;
        V.push_back(x);
      }
    }
    stS[i].init(V, combine);
  }
  while (q--) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int a, b;
      scanf("%d%d", &a, &b);
      LL ans = st.getRange(a, b + 1);
      for (int i = (1); i <= (M); i++) {
        int length = stS[i].getRange(a, b).ans;
        if (length) {
          ans = max(ans, 1LL * i * (length + 1));
        }
      }
      auto left = S.lower_bound(make_pair(a, 0));
      auto right = S.upper_bound(make_pair(b, 0));
      auto pos = left;
      vector<int> V;
      int pre = -1;
      while (pos != right) {
        if (V.empty() || pre + 1 == pos->first) {
          V.push_back(pos->second);
          pre = pos->first;
        } else {
          V.push_back(0);
          V.push_back(pos->second);
          pre = pos->first;
        }
        pos++;
      }
      ans = max(ans, solve(V));
      printf("%lld\n", ans);
    } else {
      int p;
      string s;
      scanf("%d", &p);
      cin >> s;
      sS[p] = s;
      st.setVal(p, sS[p].length());
      if (p > 1) {
        alter(p - 1, D[p - 1], dist(sS[p - 1], sS[p]));
      }
      if (p < n) {
        alter(p, D[p], dist(sS[p], sS[p + 1]));
      }
    }
  }
}
