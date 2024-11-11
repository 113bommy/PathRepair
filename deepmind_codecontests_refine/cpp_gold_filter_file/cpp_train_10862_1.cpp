#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int INT_INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
const long double PI = acos((long double)-1);
const int xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1};
const int MN = 1e5 + 5;
struct bnode {
  int val, prior, sz;
  long long sum = 0;
  bnode *ch[2] = {0, 0};
  bnode(int val) {
    this->val = val;
    this->prior = rand();
    this->sz = 1;
    this->sum = val;
  }
};
struct bbst {
  bnode *rt;
  bbst(int val) { rt = new bnode(val); }
  inline int sz(bnode *&n) {
    if (n) return n->sz;
    return 0;
  }
  inline int size() {
    if (!rt) return 0;
    return sz(rt);
  }
  inline long long gsum(bnode *&n) {
    if (n) return n->sum;
    return 0;
  }
  inline void upd_sz(bnode *&n) {
    if (n) {
      n->sz = sz(n->ch[0]) + sz(n->ch[1]) + 1;
      n->sum = gsum(n->ch[0]) + gsum(n->ch[1]) + n->val;
    }
  }
  void rot(bnode *&n, int b) {
    bnode *tmp = n->ch[b];
    n->ch[b] = tmp->ch[!b];
    tmp->ch[!b] = n;
    upd_sz(n);
    upd_sz(tmp);
    n = tmp;
  }
  long long getSum(bnode *n, int i, long long sum) {
    if (i == 0) return 0;
    if (sz(n->ch[0]) + 1 == i)
      return sum + gsum(n->ch[0]) + n->val;
    else if (sz(n->ch[0]) + 1 < i)
      return getSum(n->ch[1], i - sz(n->ch[0]) - 1,
                    sum + gsum(n->ch[0]) + n->val);
    else
      return getSum(n->ch[0], i, sum);
  }
  int numLess(bnode *n, long long num) {
    if (!n) return 0;
    if (n->val < num) return sz(n->ch[0]) + 1 + numLess(n->ch[1], num);
    return numLess(n->ch[0], num);
  }
  int kth(bnode *n, int i) {
    if (sz(n->ch[0]) + 1 == i)
      return n->val;
    else if (sz(n->ch[0]) + 1 < i)
      return kth(n->ch[1], i - sz(n->ch[0]) - 1);
    else
      return kth(n->ch[0], i);
  }
  void insert(bnode *&curr, bnode *ins) {
    if (!curr)
      curr = ins;
    else {
      int b = ins->val > curr->val;
      insert(curr->ch[b], ins);
      if (curr->ch[b]->prior > curr->prior) rot(curr, b);
      upd_sz(curr);
    }
  }
  void del(bnode *&n, int i) {
    if (!n) return;
    if (n->val == i) {
      if (!n->ch[0] || !n->ch[1])
        n = n->ch[0] ? n->ch[0] : n->ch[1];
      else {
        bool b = n->ch[1]->prior > n->ch[0]->prior;
        rot(n, b);
        del(n->ch[!b], i);
      }
    } else
      del(n->ch[n->val < i], i);
    upd_sz(n);
  }
  inline void printInOrder() {
    for (int i = 1; i <= sz(rt); i++) cout << kth(rt, i) << " ";
    cout << "\n";
  }
};
int N, K, R, A[MN];
long long res = LLONG_MIN;
bbst *pos, *neg;
inline long long calcPos() {
  long long base = (pos ? pos->getSum(pos->rt, pos->size(), 0) : 0);
  long long sub =
      (neg ? neg->size() <= R ? 0 : neg->getSum(neg->rt, neg->size() - R, 0)
           : 0);
  long long add = (neg ? neg->getSum(neg->rt, neg->size(), 0) - sub : 0);
  return base + add - sub;
}
inline long long calcNeg() {
  long long base = (neg ? neg->getSum(neg->rt, neg->size(), 0) : 0);
  long long sub =
      (pos ? pos->size() <= R ? 0 : pos->getSum(pos->rt, pos->size() - R, 0)
           : 0);
  long long add = (pos ? pos->getSum(pos->rt, pos->size(), 0) - sub : 0);
  return base + add - sub;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;
  for (int i = 1; i <= N; i++) cin >> A[i];
  cin >> R;
  for (int i = 1; i <= N; i++) {
    if (A[i] < 0) {
      if (!neg)
        neg = new bbst(-A[i]);
      else
        neg->insert(neg->rt, new bnode(-A[i]));
    } else {
      if (!pos)
        pos = new bbst(A[i]);
      else
        pos->insert(pos->rt, new bnode(A[i]));
    }
    if (i >= K) {
      res = max({res, calcNeg(), calcPos()});
      if (A[i - K + 1] < 0)
        neg->del(neg->rt, -A[i - K + 1]);
      else
        pos->del(pos->rt, A[i - K + 1]);
    }
  }
  cout << res << "\n";
}
