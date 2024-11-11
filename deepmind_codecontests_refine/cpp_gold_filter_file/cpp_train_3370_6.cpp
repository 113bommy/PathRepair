#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const double EPS = 1e-9, INF = 1e12;
template <class T>
struct avl_tree {
  struct node {
    T key;
    int size, height;
    node *child[2];
    node(const T &key) : key(key), size(1), height(1) {
      child[0] = child[1] = 0;
    }
  } * root;
  typedef node *pointer;
  avl_tree() { root = NULL; }
  pointer find(const T &key) { return find(root, key); }
  node *find(node *t, const T &key) {
    if (t == NULL) return NULL;
    if (key == t->key)
      return t;
    else if (key < t->key)
      return find(t->child[0], key);
    else
      return find(t->child[1], key);
  }
  void insert(const T &key) { root = insert(root, new node(key)); }
  node *insert(node *t, node *x) {
    if (t == NULL) return x;
    if (x->key <= t->key)
      t->child[0] = insert(t->child[0], x);
    else
      t->child[1] = insert(t->child[1], x);
    t->size += 1;
    return balance(t);
  }
  void erase(const T &key) { root = erase(root, key); }
  node *erase(node *t, const T &x) {
    if (t == NULL) return NULL;
    if (x == t->key) {
      return move_down(t->child[0], t->child[1]);
    } else {
      if (x < t->key)
        t->child[0] = erase(t->child[0], x);
      else
        t->child[1] = erase(t->child[1], x);
      t->size -= 1;
      return balance(t);
    }
  }
  node *move_down(node *t, node *rhs) {
    if (t == NULL) return rhs;
    t->child[1] = move_down(t->child[1], rhs);
    return balance(t);
  }
  node *rotate(node *t, int l, int r) {
    node *s = t->child[r];
    t->child[r] = s->child[l];
    s->child[l] = balance(t);
    if (t)
      t->size = (t->child[0] ? t->child[0]->size : 0) +
                (t->child[1] ? t->child[1]->size : 0) + 1;
    if (s)
      s->size = (s->child[0] ? s->child[0]->size : 0) +
                (s->child[1] ? s->child[1]->size : 0) + 1;
    return balance(s);
  }
  node *balance(node *t) {
    for (int i = 0; i < 2; ++i) {
      if ((t->child[!i] ? t->child[!i]->height : 0) -
              (t->child[i] ? t->child[i]->height : 0) <
          -1) {
        if ((t->child[i]->child[!i] ? t->child[i]->child[!i]->height : 0) -
                (t->child[i]->child[i] ? t->child[i]->child[i]->height : 0) >
            0)
          t->child[i] = rotate(t->child[i], i, !i);
        return rotate(t, !i, i);
      }
    }
    if (t)
      t->height = max((t->child[0] ? t->child[0]->height : 0),
                      (t->child[1] ? t->child[1]->height : 0)) +
                  1;
    if (t)
      t->size = (t->child[0] ? t->child[0]->size : 0) +
                (t->child[1] ? t->child[1]->size : 0) + 1;
    return t;
  }
  pointer rank(int k) const { return rank(root, k); }
  pointer rank(node *t, int k) const {
    if (!t) return NULL;
    int m = (t->child[0] ? t->child[0]->size : 0);
    if (k < m) return rank(t->child[0], k);
    if (k == m) return t;
    if (k > m) return rank(t->child[1], k - m - 1);
  }
};
const int MX = 100010;
int n, m;
long long t[MX], s[MX], f[MX];
long long ans[MX];
int main() {
  priority_queue<pair<long long, long long> > q;
  avl_tree<pair<long long, long long> > st;
  set<pair<long long, long long> > ss;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> s[i] >> f[i];
    q.push(make_pair(-t[i], i));
  }
  int cur = 1, goal = 1;
  long long tm = 0;
  while (!q.empty() || ss.size()) {
    long long nxt = -1, nxtid;
    if (!q.empty()) {
      nxtid = q.top().second;
      nxt = -q.top().first;
    }
    long long nxt2 = -1, nxt2id, aim;
    if (ss.size()) {
      set<pair<long long, long long> >::iterator it =
          ss.lower_bound(make_pair(cur, -inf));
      if (it->first != cur && goal < cur) it--;
      nxt2id = it->second;
      aim = it->first;
      nxt2 = tm + abs(cur - it->first);
    }
    if (nxt < 0 || nxt2 >= 0 && nxt2 < nxt) {
      tm += abs(aim - cur);
      cur = aim;
      ss.erase(make_pair(aim, nxt2id));
      st.erase(make_pair(aim, nxt2id));
      if (nxt2id < 0)
        ans[-nxt2id] = tm;
      else {
        ss.insert(make_pair(f[nxt2id], -nxt2id));
        st.insert(make_pair(f[nxt2id], -nxt2id));
      }
    } else {
      q.pop();
      ss.insert(make_pair(s[nxtid], nxtid));
      st.insert(make_pair(s[nxtid], nxtid));
      if (goal != cur) cur += (goal > cur ? 1 : -1) * max(0ll, nxt - tm);
      tm = max(tm, nxt);
    }
    if (ss.size() == 0) {
      goal = cur;
      continue;
    }
    avl_tree<pair<long long, long long> >::pointer mid = st.rank(ss.size() / 2);
    set<pair<long long, long long> >::iterator it =
        ss.lower_bound(make_pair(cur, -inf));
    if (mid->key.first < cur) {
      it--;
      goal = it->first;
    } else
      goal = it->first;
  }
  for (int i = 0; i < (int)n; i++) cout << ans[i + 1] << endl;
  return 0;
}
