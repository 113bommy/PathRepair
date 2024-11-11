#include <bits/stdc++.h>
using namespace std;
mt19937 rnd;
struct node {
  node *l = 0, *r = 0;
  int x, y, siz;
  node(int x) : x(x), y(rnd()), siz(1) {}
};
int size(node *t) {
  if (!t) return 0;
  return t->siz;
}
void update(node *t) { t->siz = size(t->l) + size(t->r) + 1; }
pair<node *, node *> split(node *t, int x) {
  if (!t) return {0, 0};
  if (t->x <= x) {
    auto p = split(t->r, x);
    t->r = p.first;
    update(t);
    return {t, p.second};
  } else {
    auto p = split(t->l, x);
    t->l = p.second;
    update(t);
    return {p.first, t};
  }
}
node *merge(node *a, node *b) {
  if (!a) return b;
  if (!b) return a;
  if (a->y > b->y) {
    a->r = merge(a->r, b);
    update(a);
    return a;
  } else {
    b->l = merge(a, b->l);
    update(b);
    return b;
  }
}
node *insert(node *t, node *in) {
  if (!t) return in;
  if (in->y > t->y) {
    auto p = split(t, in->x);
    in->l = p.first;
    in->r = p.second;
    update(in);
    return in;
  }
  if (in->x < t->x) {
    t->l = insert(t->l, in);
  } else {
    t->r = insert(t->r, in);
  }
  update(t);
  return t;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int useless = 0; useless < t; useless++) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    node *t = 0;
    vector<int> a_srt(n);
    copy(a.begin(), a.end(), a_srt.begin());
    sort(a_srt.begin(), a_srt.end());
    bool good = false;
    for (int i = 1; i < n; i++) {
      if (a[i] == a[i - 1]) {
        cout << "YES\n";
        good = true;
        break;
      }
    }
    if (good) continue;
    bool dp_all = true;
    t = insert(t, new node(a[0]));
    for (int i = 1; i < n; i++) {
      auto p = split(t, a[i]);
      if (size(p.second) % 2) {
        dp_all = !dp_all;
      }
      t = merge(p.first, p.second);
      t = insert(t, new node(a[i]));
    }
    if (dp_all)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
