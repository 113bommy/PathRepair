#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int INF = 0x3f3f3f3f;
const int iinf = 1 << 30;
const long long linf = 2e18;
const int mod = 1000000007;
const double eps = 1e-7;
void douout(double x) { printf("%lf\n", x + 0.0000000001); }
template <class T>
void print(T a) {
  cout << a << endl;
  exit(0);
}
template <class T>
void chmin(T &a, T b) {
  if (a > b) a = b;
}
template <class T>
void chmax(T &a, T b) {
  if (a < b) a = b;
}
void sub(int &a, int b) { a = (a - b + mod) % mod; }
void mul(int &a, int b) { a = (long long)a * b % mod; }
int addv(int a, int b) { return (a += b) >= mod ? a -= mod : a; }
int subv(int a, int b) { return (a -= b) < 0 ? a += mod : a; }
int mulv(int a, int b) { return (long long)a * b % mod; }
int read() {
  int f = 1, x = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int pw(int a, int b) {
  int s = 1;
  for (; b; b >>= 1, a = (long long)a * a % mod)
    if (b & 1) s = (long long)s * a % mod;
  return s;
}
int n, m;
int a[N], v[N], pos[N], vis[N];
int bit[N];
vector<vector<int> > ans;
int f(int x) {
  int i = 0;
  while (i * (i + 1) / 2 <= x) i++;
  return i - 1;
}
void add(int x, int id) {
  for (; x <= n; x += (x & -x))
    if (v[bit[x]] < v[id]) bit[x] = id;
}
int ask(int x) {
  int ans = 0;
  for (; x; x -= (x & -x))
    if (v[ans] < v[bit[x]]) ans = bit[x];
  return ans;
}
void work() {
  ans.clear();
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) scanf("%d", &a[i]);
  m = n;
  while (m > 0) {
    int k = f(m);
    memset(bit, 0, sizeof(bit));
    for (int i = (1); i <= (m); i++) {
      vis[i] = 0;
      pos[i] = ask(a[i]);
      v[i] = v[pos[i]] + 1;
      add(a[i], i);
    }
    int tl = ask(n), len = v[tl];
    if (len > k) {
      vector<int> tmp;
      tmp.clear();
      for (int i = tl; i; i = pos[i]) vis[i] = 1, tmp.push_back(a[i]);
      reverse(tmp.begin(), tmp.end());
      ans.push_back(tmp);
      int newm = 0;
      for (int i = (1); i <= (m); i++)
        if (!vis[i]) a[++newm] = a[i];
      m = newm;
    } else {
      int c = ((int)ans.size()) - 1;
      vector<int> tmp;
      tmp.clear();
      for (int i = (1); i <= (len); i++) ans.push_back(tmp);
      for (int i = (1); i <= (m); i++) ans[c + v[i]].push_back(a[i]);
      break;
    }
  }
  printf("%d\n", ((int)ans.size()));
  for (auto it = ans.begin(); it != ans.end(); it++) {
    vector<int> cur = *it;
    printf("%d", ((int)cur.size()));
    for (int i = (0); i <= (((int)cur.size()) - 1); i++) printf(" %d", cur[i]);
    cout << endl;
  }
}
signed main() {
  int T;
  scanf("%d", &T);
  while (T--) work();
  return 0;
}
