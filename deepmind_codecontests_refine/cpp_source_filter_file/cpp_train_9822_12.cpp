#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e+14;
const int nmax = 100009;
typedef struct item *pitem;
struct item {
  int prior, cnt;
  long long value;
  pitem l, r;
};
int cnt(pitem it) { return it ? it->cnt : 0; }
void upd_cnt(pitem it) {
  if (it) it->cnt = cnt(it->l) + cnt(it->r) + 1;
}
void merge(pitem &t, pitem l, pitem r) {
  if (!l || !r)
    t = l ? l : r;
  else if (l->prior > r->prior)
    merge(l->r, l->r, r), t = l;
  else
    merge(r->l, l, r->l), t = r;
  upd_cnt(t);
}
void split(pitem t, pitem &l, pitem &r, long long &key, int add = 0) {
  if (!t) return void(l = r = 0);
  if (t->value > key)
    split(t->l, l, t->l, key, add), r = t;
  else
    split(t->r, t->r, r, key, add + 1 + cnt(t->l)), l = t;
  upd_cnt(t);
}
int get(pitem T, long long &key) {
  if (!T) return 0;
  if (T->value > key) {
    return get(T->l, key);
  } else {
    return cnt(T->l) + get(T->r, key);
  }
}
long long n, k;
long long a[nmax];
long long s[nmax];
long long check(long long d) {
  s[0] = 0;
  pitem T = new item;
  T->cnt = 1;
  T->l = T->r = NULL;
  T->prior = int(rand()) * rand();
  T->value = 0;
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    s[i] = s[i - 1] + a[i];
    long long tmp = s[i] - d;
    pitem T1, T2;
    ans += get(T, tmp);
    pitem np = new item;
    np->cnt = 1;
    np->value = s[i];
    np->l = np->r = NULL;
    np->prior = rand() * (int)rand();
    split(T, T1, T2, s[i]);
    merge(T, T1, np);
    merge(T, T, T2);
  }
  return ans;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  check(3);
  long long l = -inf - 1;
  long long r = inf + 1;
  while (l < r - 1) {
    long long mid = (l + r) / 2;
    if (check(mid) >= k)
      l = mid;
    else
      r = mid;
  }
  cout << l << endl;
  return 0;
}
