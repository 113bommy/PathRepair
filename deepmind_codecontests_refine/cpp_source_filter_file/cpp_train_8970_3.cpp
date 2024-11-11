#include <bits/stdc++.h>
using namespace std;
struct item {
  int key, prior, sz, mx, sum;
  item *l, *r;
  item() {}
  item(int key, int prior)
      : key(key), prior(prior), mx(key), sz(1), sum(key), l(NULL), r(NULL) {}
};
struct node {
  int cnt_pass = 0;
  int cnt_end = 0;
  int chld[2] = {-1, -1};
  node() {}
};
typedef item* pitem;
const int maxN = 200005;
int N, K, ANS;
pitem sets[maxN];
vector<node> trie(1);
int get_size(pitem t) { return t ? t->sz : 0; }
void upd_size(pitem& t) {
  if (t) t->sz = 1 + get_size(t->l) + get_size(t->r);
}
int get_max(pitem t) { return t ? t->mx : -1; }
void upd_max(pitem& t) {
  if (t) t->mx = max(t->key, max(get_max(t->l), get_max(t->r)));
}
int get_sum(pitem t) { return t ? t->sum : 0; }
void upd_sum(pitem& t) {
  if (t) t->sum = t->key + get_sum(t->l) + get_sum(t->r);
}
int get_top(pitem t) { return t ? t->key : 0; }
void add_str(int t, string& s) {
  int c;
  for (char ch : s) {
    c = ch - '0';
    if (trie[t].chld[c] == -1) {
      trie[t].chld[c] = trie.size();
      trie.emplace_back();
    }
    ++trie[t].cnt_pass;
    t = trie[t].chld[c];
  }
  ++trie[t].cnt_pass;
  ++trie[t].cnt_end;
}
void split(pitem t, int key, pitem& l, pitem& r) {
  if (!t)
    l = r = NULL;
  else if (key < t->key) {
    split(t->l, key, l, t->l), r = t;
  } else {
    split(t->r, key, t->r, r), l = t;
  }
  upd_size(t);
  upd_max(t);
  upd_sum(t);
}
void insert(pitem& t, pitem it) {
  if (!t)
    t = it;
  else if (it->prior > t->prior) {
    split(t, it->key, it->l, it->r);
    t = it;
  } else {
    insert(it->key < t->key ? t->l : t->r, it);
  }
  upd_size(t);
  upd_max(t);
  upd_sum(t);
}
void merge(pitem& t, pitem l, pitem r) {
  if (!l || !r)
    t = l ? l : r;
  else if (l->prior > r->prior) {
    merge(l->r, l->r, r), t = l;
  } else {
    merge(r->l, l, r->l), t = r;
  }
  upd_size(t);
  upd_max(t);
  upd_sum(t);
}
void erase(pitem& t, int key) {
  if (t->key == key)
    merge(t, t->l, t->r);
  else
    erase(key < t->key ? t->l : t->r, key);
  upd_size(t);
  upd_max(t);
  upd_sum(t);
}
int combine(int a, int b) {
  if (get_size(sets[a]) < get_size(sets[b])) swap(a, b);
  int key;
  pitem p;
  while (get_size(sets[b]) > 0) {
    key = get_top(sets[b]);
    erase(sets[b], key);
    p = new item(key, rand());
    insert(sets[a], p);
    if (get_size(sets[a]) > K) {
      key = get_max(sets[a]);
      erase(sets[a], key);
    }
  }
  return a;
}
int dfs(int t, int d) {
  if (t == -1) return -1;
  vector<int> inds(1, t);
  pitem p;
  int a, b, x;
  for (int i = trie[t].cnt_end; i > 0; --i) {
    p = new item(d, rand());
    insert(sets[t], p);
  }
  for (int i = 0; i < 2; ++i) {
    if (trie[t].chld[i] == -1) continue;
    x = dfs(trie[t].chld[i], d + 1);
    if (x != -1) inds.push_back(x);
  }
  while (inds.size() > 1) {
    a = inds.back();
    inds.pop_back();
    b = inds.back();
    inds.pop_back();
    inds.push_back(combine(a, b));
  }
  x = inds[0];
  if (get_size(sets[x]) == K) ANS = min(ANS, get_sum(sets[x]) - d * K);
  return x;
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    string s = "";
    int j;
    for (j = 1 << 22; j > x; j >>= 1)
      ;
    for (; j > 0; j >>= 1) {
      if (j <= x) {
        x -= j;
        s += '1';
      } else {
        s += '0';
      }
      ++ANS;
    }
    add_str(0, s);
  }
  dfs(0, 0);
  printf("%d\n", ANS);
  return 0;
}
