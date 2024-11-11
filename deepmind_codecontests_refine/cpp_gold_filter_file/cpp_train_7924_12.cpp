#include <bits/stdc++.h>
using namespace std;
class trp {
 public:
  long long a, b, c;
  trp() {
    this->a = 0;
    this->b = 0;
    this->c = 0;
  }
  trp(long long a, long long b, long long c) {
    this->a = a;
    this->b = b;
    this->c = c;
  }
};
bool srt(trp x, trp y) { return x.a < y.a; }
long long pw(long long a, long long b, long long m) {
  if (b == 0) return 1;
  if (b % 2 == 0) return (pw(a, b / 2, m) * pw(a, b / 2, m)) % m;
  return (a * ((pw(a, b / 2, m) * pw(a, b / 2, m)) % m)) % m;
}
long long gc(long long a, long long b) {
  if (b == 0) return a;
  return gc(b, a % b);
}
vector<string> splt(string x, char w) {
  vector<string> v;
  string s;
  int l = x.length();
  for (int i = 0; i < l; i++) {
    if (x[i] == w) {
      v.push_back(s);
      s = "";
    } else {
      s.push_back(x[i]);
    }
  }
  v.push_back(s);
  return v;
}
class node {
 public:
  long long index, a, l, ml, d;
  node* mr_img;
  node* lf = NULL;
  node* rt = NULL;
  node* pr_nd = NULL;
  vector<node*> v;
  node() {
    index = 0, a = 0, ml = -1, l = 0, d = 0;
    node* mr_img = NULL;
    node* lf = NULL;
    node* rt = NULL;
    node* p_nd = NULL;
  }
  void addnode(node* t) {
    v.push_back(t);
    this->l++;
  }
};
node* newnode(long long a) {
  node* t = new node();
  t->a = a;
  return t;
}
void ioe() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
}
void solve() {
  long long l1 = 3, l2 = 1, x = 10;
  vector<long long> v;
  v.push_back(0);
  v.push_back(4), v.push_back(7);
  while (x <= 1000000000) {
    long long y = 4 * x, i1 = l1;
    for (int i = l2; i < l1; i++) v.push_back(v[i] + y), i1++;
    y = 7 * x;
    for (int i = l2; i < l1; i++) v.push_back(v[i] + y), i1++;
    l2 = l1, l1 = i1, x = x * 10;
  }
  long long p1, p2, v1, v2, k, t = 0;
  cin >> p1 >> p2 >> v1 >> v2 >> k;
  if (v1 < p1) {
    p2 = v2 + p2, v2 = p2 - v2, p2 = p2 - v2;
    p1 = v1 + p1, v1 = p1 - v1, p1 = p1 - v1;
  }
  double ans = 0, d = (v2 - v1 + 1) * (p2 - p1 + 1);
  long long i1 = lower_bound(v.begin(), v.end(), p1) - v.begin();
  while (t == 0) {
    if (v[i1 - 1] > p2 || (i1 + k) > l1 || v[i1 + k - 1] > v2)
      t++;
    else if (v[i1 + k] >= v1) {
      ans += (min(v[i1], p2) - max(p1 - 1, v[i1 - 1])) *
             (min(v2, v[i1 + k] - 1) - max(v[i1 + k - 1] - 1, v1 - 1)) / d;
    }
    i1++;
  }
  i1 = lower_bound(v.begin(), v.end(), v1) - v.begin(), t = 0;
  while (t == 0) {
    if (v[i1 - 1] > v2 || (i1 + k) > l1 || v[i1 + k - 1] > p2)
      t++;
    else if (v[i1 + k] >= p1) {
      ans += ((min(v[i1], v2) - max(v1 - 1, v[i1 - 1])) *
                  (min(p2, v[i1 + k] - 1) - max(v[i1 + k - 1] - 1, p1 - 1)) -
              (k == 1 ? 1 : 0)) /
             d;
    }
    i1++;
  }
  printf("%.10f\n", ans);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  long long f = t;
  while (f--) {
    solve();
  }
}
