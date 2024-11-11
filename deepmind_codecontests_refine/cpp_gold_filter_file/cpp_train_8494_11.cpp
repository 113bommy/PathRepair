#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
mt19937 gen;
constexpr int N = 300005;
int costs[N];
tiii points[N * 2];
pii requests[N];
int answers[N];
int one_len[N];
int best_for[N];
map<int, int> two_ans[N];
struct Node {
  pii x;
  int y, val, mx;
  Node *l, *r;
  Node(const pii &x, int val) {
    this->x = x;
    this->val = val;
    this->mx = val;
    this->y = gen();
    l = nullptr;
    r = nullptr;
  }
};
using Treap = Node *;
inline int mx(Treap t) {
  if (t) return t->mx;
  return -1;
}
inline Treap fix(Treap t) {
  if (t) t->mx = max(t->val, max(mx(t->l), mx(t->r)));
  return t;
}
Treap find(Treap t, const pii &x) {
  if (!t) return nullptr;
  if (x < t->x) {
    return find(t->l, x);
  } else if (x > t->x) {
    return find(t->r, x);
  } else {
    return t;
  }
}
Treap merge(Treap t1, Treap t2) {
  if (!t1 || !t2) return t1 ? t1 : t2;
  if (t1->y > t2->y) {
    t1->r = merge(t1->r, t2);
    return fix(t1);
  } else {
    t2->l = merge(t1, t2->l);
    return fix(t2);
  }
}
pair<Treap, Treap> split(Treap t, const pii &x) {
  if (!t) return make_pair(nullptr, nullptr);
  if (x < t->x) {
    auto p = split(t->l, x);
    t->l = p.second;
    return make_pair(p.first, fix(t));
  } else {
    auto p = split(t->r, x);
    t->r = p.first;
    return make_pair(fix(t), p.second);
  }
}
int main(void) {
  int n, C;
  scanf("%d%d", &n, &C);
  for (int i = 0; i < n; i++) {
    int l, r, c;
    scanf("%d%d%d", &l, &r, &c);
    costs[i] = c;
    points[i * 2] = make_tuple(l, 1, i);
    points[i * 2 + 1] = make_tuple(r, 0, i);
  }
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int q;
    scanf("%d", &q);
    requests[i] = make_pair(q, i);
  }
  sort(points, points + 2 * n);
  sort(requests, requests + m);
  set<int> stk;
  int prev_pos = 0;
  int ptr = 0;
  int free_len = 0;
  int best_ans = 0;
  Treap t = nullptr;
  for (int i = 0; i < 2 * n; i++) {
    int pos, is_start, original_idx;
    tie(pos, is_start, original_idx) = points[i];
    int seg_len = pos - prev_pos;
    if (stk.size() == 0) {
      free_len += seg_len;
    } else if (stk.size() == 1) {
      int idx = *stk.begin();
      int cost = costs[idx];
      if (cost <= C) {
        one_len[idx] += seg_len;
        Treap p, q, original_node = nullptr;
        tie(p, q) = split(t, make_pair(cost, idx - 1));
        tie(original_node, q) = split(q, make_pair(cost, idx));
        auto treap_wo = merge(p, q);
        Treap less_eq, higher;
        tie(less_eq, higher) = split(treap_wo, make_pair(C - cost + 1, -1));
        if (less_eq) {
          int best_pair = mx(less_eq);
          best_for[idx] = max(best_for[idx], best_pair);
        }
        treap_wo = merge(less_eq, higher);
        tie(p, q) = split(treap_wo, make_pair(cost, idx));
        if (!original_node) {
          original_node = new Node(make_pair(cost, idx), 0);
        }
        original_node->val += seg_len;
        t = merge(merge(p, original_node), q);
        best_ans = max(best_ans, one_len[idx] + best_for[idx]);
      }
    } else if (stk.size() == 2) {
      int a, b;
      a = *stk.begin();
      b = *stk.rbegin();
      if (costs[a] + costs[b] <= C) {
        two_ans[a][b] += seg_len;
        best_for[a] = max(best_for[a], one_len[b] + two_ans[a][b]);
        best_for[b] = max(best_for[b], one_len[a] + two_ans[a][b]);
        best_ans = max(best_ans,
                       max(one_len[a] + best_for[a], one_len[b] + best_for[b]));
      }
    }
    while (free_len + best_ans >= requests[ptr].first && ptr < m) {
      answers[requests[ptr].second] =
          pos - (free_len + best_ans - requests[ptr].first);
      ptr++;
    }
    if (is_start) {
      stk.insert(original_idx);
    } else {
      stk.erase(stk.find(original_idx));
    }
    prev_pos = pos;
  }
  while (ptr < m) {
    answers[requests[ptr].second] =
        prev_pos - (free_len + best_ans - requests[ptr].first);
    ptr++;
  }
  for (int i = 0; i < m; i++) {
    printf("%d\n", answers[i]);
  }
  return 0;
}
