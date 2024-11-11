#include <bits/stdc++.h>
using namespace std;
const int INF = (int)2e9;
const int mod = (int)1e9 + 123;
const int N = (int)1e6 + 10;
const long long LLINF = (long long)3e18 + 10;
const long double pi = acos(-1);
template <typename T1, typename T2>
bool umin(T1 &x, T2 y) {
  if (x > y) return x = y, true;
  return false;
}
template <typename T1, typename T2>
bool umax(T1 &x, T2 y) {
  if (x < y) return x = y, true;
  return false;
}
template <typename T>
T getint() {
  char c = getchar();
  T p = 1, x = 0;
  while (c == ' ' || c == '\n') c = getchar();
  if (c == '-') p = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * p;
}
long long bp[N], h[N];
int n, m, q;
map<tuple<int, int, int, int>, long long> s;
struct tree {
  vector<tree *> t;
  vector<long long> a;
  tree(int n, int m) {
    t.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      t[i] = new tree(m);
    }
  }
  tree(int m) { a.resize(m + 1); }
  void add(int x, int y, long long val) {
    if (x >= t.size()) return;
    for (; x <= n; x |= (x + 1)) t[x]->add(y, val);
  }
  void add(int y, long long val) {
    if (y >= a.size()) return;
    for (; y <= n; y |= (y + 1)) a[y] += val;
  }
  long long get(int x, int y) {
    long long ans = 0;
    for (; x >= 1; x = (x & (x + 1)) - 1) {
      ans += t[x]->get(y);
    }
    return ans;
  }
  long long get(int y) {
    long long ans = 0;
    for (; y >= 1; y = (y & (y + 1)) - 1) {
      ans += a[y];
    }
    return ans;
  }
  void couttree() {
    if (t.size()) {
      for (int i = 1; i < t.size(); ++i) {
        t[i]->couttree();
        cout << '\n';
      }
      cout << endl;
    } else {
      for (int i = 1; i < a.size(); ++i) {
        cout << a[i] << ' ';
      }
    }
  }
};
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(0);
  n = getint<int>();
  m = getint<int>();
  q = getint<int>();
  tree *t = new tree(n, m);
  for (int i = 0; i < q; ++i) {
    bp[i] = (i ? bp[i - 1] * 23123 % mod : 1);
    h[i] = ((i ? h[i - 1] : 0) + (i + 1) * bp[i]) % mod;
    int ty = getint<int>();
    int x1 = getint<int>(), y1 = getint<int>();
    int x2 = getint<int>(), y2 = getint<int>();
    if (ty == 1) {
      s[make_tuple(x1, y1, x2, y2)] = h[i];
      t->add(x1, y1, h[i]);
      t->add(x1, y2 + 1, -h[i]);
      t->add(x2 + 1, y1, -h[i]);
      t->add(x2 + 1, y2 + 1, h[i]);
    }
    if (ty == 2) {
      long long val = s[make_tuple(x1, y1, x2, y2)];
      t->add(x1, y1, -val);
      t->add(x1, y2 + 1, val);
      t->add(x2 + 1, y1, val);
      t->add(x2 + 1, y2 + 1, -val);
    }
    if (ty == 3) {
      if (t->get(x1, y1) == t->get(x2, y2))
        printf("Yes\n");
      else
        printf("No\n");
    }
  }
  return 0;
}
