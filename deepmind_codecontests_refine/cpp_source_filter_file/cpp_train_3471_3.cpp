#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const double pi = 3.141592653589793238462;
const int nmax = 200000;
const int hash_base = 119;
vector<unsigned long long> pw, hash123456789;
bool isprime(int first) {
  for (int i = 2; i * i <= first; i++)
    if (first % i == 0) return false;
  return true;
};
void kmp(string s, vector<int> &func) {
  func.resize(s.size());
  for (int i = 1; i < s.size(); i++) {
    int j = func[i - 1];
    while (j > 0 && s[j] != s[i]) j = func[j - 1];
    if (s[j] == s[i]) j++;
    func[i] = j;
  };
};
unsigned long long subhash(vector<unsigned long long> hash123456789, int l,
                           int r) {
  if (l == 0) return hash123456789[r];
  return hash123456789[r] - hash123456789[l] * pw[r - l + 1];
};
void make_hash(string s, vector<unsigned long long> &hash123456789) {
  hash123456789.resize(s.size());
  hash123456789[0] = s[0] - 'a' + 1;
  pw[0] = 1;
  for (int i = 1; i < s.size(); i++) {
    pw[i] = pw[i - 1] * hash_base;
    hash123456789[i] = hash123456789[i - 1] * hash_base + s[i] - 'a' + 1;
  };
};
struct tree {
  int tl, tr, key;
  tree *l, *r;
  tree(){};
  tree(int _tl, int _tr) : tl(_tl), tr(_tr), l(0), r(0), key(0){};
};
typedef tree *node;
void build(node &t) {
  if (t->tl != t->tr) {
    int mid = (t->tl + t->tr) >> 1;
    t->l = new tree(t->tl, mid);
    t->r = new tree(mid + 1, t->tr);
    build(t->l);
    build(t->r);
    t->key = t->l->key + t->r->key;
  };
};
void modify(node &t, int pos, int key) {
  if (t->tl == pos && t->tr == pos)
    t->key = key;
  else {
    int mid = (t->tl + t->tr) >> 1;
    if (pos <= mid)
      modify(t->l, pos, key);
    else
      modify(t->r, pos, key);
    t->key = t->l->key + t->r->key;
  };
};
int query(node t, int l, int r) {
  if (t->tl == l && t->tr == r)
    return t->key;
  else {
    int mid = (t->tl + t->tr) >> 1;
    if (l > mid)
      return query(t->r, l, r);
    else if (r <= mid)
      return query(t->l, l, r);
    else
      return query(t->l, l, mid) + query(t->r, mid + 1, r);
  };
};
long long bpowmod(long long a, long long b, long long m) {
  long long ans = 1;
  for (; b;) (b & 1) ? (ans = (ans * a) % m, b--) : (a = (a * a) % m, b >>= 1);
  return ans;
};
bool cmp_int(int a, int b) { return a > b; };
bool cmp_pair(pair<long long, int> a, pair<long long, int> b) { return a > b; };
int n, k;
bool big[200000];
long long money;
long long b[200000];
pair<long long, int> a[200000];
int main() {
  scanf("%d%d%I64d", &n, &k, &money);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i].first);
    a[i].second = i;
    b[i] = a[i].first;
  };
  sort(a + 1, a + n + 1, cmp_pair);
  long long sum = 0;
  for (int i = 1; i < k; i++) {
    sum += a[i].first;
    big[a[i].second] = true;
  };
  for (int i = 1; i < n; i++) {
    long long cnt;
    if (!big[i])
      cnt = sum;
    else
      cnt = sum - b[i] + a[k].first;
    if (money - cnt < b[i]) {
      printf("%d\n", i);
      return 0;
    };
  };
  printf("%d\n", n);
  return 0;
}
