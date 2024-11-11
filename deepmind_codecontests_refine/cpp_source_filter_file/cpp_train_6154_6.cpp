#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10;
long long int now = 142396129374LL;
bool rnd(int a, int b) {
  now ^= 12398476193LL;
  now %= (a + b);
  return now > b;
}
struct node {
  node* l;
  node* r;
  int val;
  long long int tot;
  int size;
  void pull() {
    size = 1;
    tot = val;
    if (l) {
      size += l->size;
      tot += l->tot;
    }
    if (r) {
      tot += r->tot;
      size += r->size;
    }
    return;
  }
  node(int n) {
    size = 1;
    val = n;
    tot = n;
    l = r = nullptr;
    return;
  }
};
long long int ans;
node* s[N];
int p[N], en[N];
int find(int n) { return p[n] == n ? n : p[n] = find(p[n]); }
void into(node* n, vector<int>& v) {
  if (!n) return;
  if (n->r) into(n->l, v);
  v.push_back(n->val);
  if (n->l) into(n->r, v);
  return;
}
void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
  return;
}
node* merge(node* a, node* b) {
  if (!a) return b;
  if (!b) return a;
  if (rnd(a->size, b->size)) {
    a->r = merge(a->r, b);
    a->pull();
    return a;
  } else {
    b->l = merge(a, b->l);
    b->pull();
    return b;
  }
}
void split(node* x, int v, node*& a, node*& b) {
  if (!x) {
    a = b = nullptr;
    return;
  }
  if (x->val > v) {
    b = x;
    split(x->l, v, a, b->l);
    b->pull();
  } else {
    a = x;
    split(x->r, v, a->r, b);
    a->pull();
  }
  return;
}
void mer(int a, int b) {
  vector<int> v;
  if (s[b]->size > s[a]->size) swap(a, b);
  int pa = a;
  into(s[b], v);
  node *nl, *nr;
  for (int i = 0; i < v.size(); i++) {
    split(s[a], v[i], nl, nr);
    if (a > b) {
      if (nr) ans -= nr->tot;
      pa--;
      ans += ((long long int)pa + (nr ? (long long int)nr->size : 0) -
              (long long int)b - (long long int)i) *
             (long long int)v[i];
    } else {
      if (nl) ans += nl->tot;
      ans -= ((long long int)i + (long long int)b - (long long int)a -
              (nr ? (long long int)nr->size : 0)) *
             (long long int)v[i];
    }
    s[a] = merge(nl, new node(v[i]));
    s[a] = merge(s[a], nr);
  }
  if (a > b) {
    p[b] = p[a] = b;
    en[a] = en[b] = s[a]->size + b - 1;
    s[b] = s[a];
  } else {
    p[a] = p[b] = a;
    en[b] = en[a] = s[a]->size + a - 1;
  }
  return;
}
int main() {
  int n, l, r, temp;
  node *a, *b;
  scanf("%d", &n);
  ans = 0;
  for (int i = 0; i < N; i++) {
    p[i] = en[i] = i;
    s[i] = nullptr;
  }
  p[1] = 1;
  while (n--) {
    scanf("%d%d", &l, &r);
    temp = find(l);
    if (s[temp]) {
      split(s[temp], r, a, b);
      if (a) ans += a->tot;
      ans += ((long long int)temp + (b ? b->size : 0) - (long long int)l) *
             (long long int)r;
      a = merge(a, new node(r));
      s[temp] = merge(a, b);
      en[temp]++;
      p[en[temp]] = temp;
    } else
      s[temp] = new node(r);
    while (s[en[temp] + 1]) {
      mer(temp, en[temp] + 1);
      temp = find(temp);
    }
    l = find(l);
    temp = find(temp - 1);
    if (temp > 0) {
      while (s[temp]) {
        mer(temp, en[temp] + 1);
        temp = find(temp - 1);
        if (temp <= 0) break;
      }
    }
    printf("%lld\n", ans);
  }
}
