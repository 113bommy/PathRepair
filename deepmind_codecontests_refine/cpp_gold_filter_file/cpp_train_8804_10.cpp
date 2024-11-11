#include <bits/stdc++.h>
using namespace std;
template <typename T>
T next_int() {
  T x = 0, p = 1;
  char ch;
  do {
    ch = getchar();
  } while (ch <= ' ');
  if (ch == '-') {
    p = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return p * x;
}
string next_token() {
  char ch;
  string ans = "";
  do {
    ch = getchar();
  } while (ch <= ' ');
  while (ch > ' ') {
    ans += ch;
    ch = getchar();
  }
  return ans;
}
const long long INF = (long long)1e18;
const int INFINT = (int)1e9 + 227 + 1;
const int MAXN = (int)1e6 + 227 + 1;
const int MOD = (int)1e9 + 7;
const long double EPS = 1e-9;
long long bin_pow(long long a, long long b) {
  if (!b) return 1;
  long long ans = bin_pow(a, b / 2);
  ans = ans * ans;
  if (b % 2) ans = ans * a;
  return ans;
}
struct tree {
  struct node {
    node() {
      l = r = -1;
      mx = 0;
    }
    int l, r;
    long long mx;
  };
  vector<node> t;
  int len;
  tree(int len) : len(len) { t.push_back(node()); }
  void up(int v, int l, int r, int p, long long c) {
    t[v].mx = max(t[v].mx, c);
    if (l == r) return;
    if (t[v].l == -1) {
      t[v].l = t.size();
      t.push_back(node());
    }
    if (t[v].r == -1) {
      t[v].r = t.size();
      t.push_back(node());
    }
    int mid = (l + r) / 2;
    if (p <= mid)
      up(t[v].l, l, mid, p, c);
    else
      up(t[v].r, mid + 1, r, p, c);
  }
  void up(int p, long long c) { up(0, 0, len, p, c); }
  long long get(int v, int l, int r, int _l, int _r) {
    if (_l > _r) return 0;
    if (_l == l && _r == r) return t[v].mx;
    if (t[v].l == -1) {
      t[v].l = t.size();
      t.push_back(node());
    }
    if (t[v].r == -1) {
      t[v].r = t.size();
      t.push_back(node());
    }
    int mid = (l + r) / 2;
    return max(get(t[v].l, l, mid, _l, min(mid, _r)),
               get(t[v].r, mid + 1, r, max(mid + 1, _l), _r));
  }
  long long get(int l, int r) { return get(0, 0, len, l, r); }
};
int main() {
  int n;
  cin >> n;
  vector<pair<pair<int, int>, int> > c(n);
  for (int i = 0; i < n; i++) {
    c[i].first.second = -next_int<int>();
    c[i].first.first = -next_int<int>();
    c[i].second = next_int<int>();
  }
  sort((c).begin(), (c).end());
  tree t((int)1e9);
  for (int i = 0; i < n; i++) {
    int a = -c[i].first.second;
    int b = -c[i].first.first;
    int h = c[i].second;
    t.up(a, t.get(0, b - 1) + h);
  }
  cout << t.get(0, (int)1e9) << "\n";
}
