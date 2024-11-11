#include <bits/stdc++.h>
using namespace std;
template <typename T>
T BigMod(T b, T p, T m) {
  if (p == 0) return 1;
  if (p % 2 == 0) {
    T s = BigMod(b, p / 2, m);
    return ((s % m) * (s % m)) % m;
  }
  return ((b % m) * (BigMod(b, p - 1, m) % m)) % m;
}
template <typename T>
T ModInv(T b, T m) {
  return BigMod(b, m - 2, m);
}
template <typename T>
T in() {
  char ch;
  T n = 0;
  bool ng = false;
  while (1) {
    ch = getchar();
    if (ch == '-') {
      ng = true;
      ch = getchar();
      break;
    }
    if (ch >= '0' && ch <= '9') break;
  }
  while (1) {
    n = n * 10 + (ch - '0');
    ch = getchar();
    if (ch < '0' || ch > '9') break;
  }
  return (ng ? -n : n);
}
template <typename T>
T POW(T B, T printf) {
  if (printf == 0) return 1;
  if (printf & 1)
    return B * POW(B, printf - 1);
  else
    return (POW(B, printf / 2) * POW(B, printf / 2));
}
template <typename T>
T Bigmod(T b, T p, T m) {
  if (p == 0)
    return 1;
  else if (!(p & 1))
    return (Bigmod(b, p / 2, m) * Bigmod(b, p / 2, m)) % m;
  else
    return ((b % m) * Bigmod(b, p - 1, m)) % m;
}
template <typename T>
T Dis(T x1, T y1, T x2, T y2) {
  return sqrt((x1 - x2 * x1 - x2) + (y1 - y2 * y1 - y2));
}
template <typename T>
T Angle(T x1, T y1, T x2, T y2) {
  return atan(double(y1 - y2) / double(x1 - x2));
}
template <typename T>
T DIFF(T a, T b) {
  T d = a - b;
  if (d < 0)
    return -d;
  else
    return d;
}
template <typename T>
T ABS(T a) {
  if (a < 0)
    return -a;
  else
    return a;
}
template <typename T>
T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <typename T>
T lcm(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / gcd(a, b));
}
template <typename T>
T euclide(T a, T b, T &x, T &y) {
  if (a < 0) {
    T d = euclide(-a, b, x, y);
    x = -x;
    return d;
  }
  if (b < 0) {
    T d = euclide(a, -b, x, y);
    y = -y;
    return d;
  }
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    T d = euclide(b, a % b, x, y);
    T t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
  }
}
template <typename T>
void ia(T a[], int n) {
  for (int i = 0; i < n; i++) cin >> a[i];
}
template <typename T>
void pa(T a[], int n) {
  for (int i = 0; i < n - 1; i++) cout << a[i] << " ";
  cout << a[n - 1] << endl;
}
template <typename T>
long long int isLeft(T a, T b, T c) {
  return (a.x - b.x) * (b.y - c.y) - (b.x - c.x) * (a.y - b.y);
}
int Set(int N, int pos) { return N = N | (1 << pos); }
int Reset(int N, int pos) { return N = N & ~(1 << pos); }
bool Check(int N, int pos) { return (bool)(N & (1 << pos)); }
template <class T, class first>
inline T togglebit(T a, first i) {
  T t = 1;
  return (a ^ (t << i));
}
int toInt(string s) {
  int sm;
  stringstream ss(s);
  ss >> sm;
  return sm;
}
int toLlint(string s) {
  long long int sm;
  stringstream ss(s);
  ss >> sm;
  return sm;
}
int cdigittoint(char ch) { return ch - '0'; }
bool isVowel(char ch) {
  ch = toupper(ch);
  if (ch == 'A' || ch == 'U' || ch == 'I' || ch == 'O' || ch == 'E')
    return true;
  return false;
}
bool isConst(char ch) {
  if (isalpha(ch) && !isVowel(ch)) return true;
  return false;
}
double DEG(double x) { return (180.0 * x) / (2.0 * acos(0.0)); }
double RAD(double x) { return (x * (double)2.0 * acos(0.0)) / (180.0); }
struct Node {
  int cnt;
  Node *l, *r;
  Node() {
    cnt = 0;
    l = r = NULL;
  }
};
vector<int> adj[100007];
vector<int> ppl[100007];
Node Tree[18 * 100007];
int avail;
Node *Roots[100007];
int L[100007], T[100007];
int PP[100007][20];
Node *Update(Node *idx, int l, int r, int pos) {
  Node *u = &Tree[++avail];
  if (idx != NULL) u = idx;
  if (l == r) {
    u->cnt++;
    return u;
  }
  u->cnt++;
  if (pos <= ((l + r) >> 1))
    u->l = Update(u->l, l, ((l + r) >> 1), pos);
  else
    u->r = Update(u->r, ((l + r) >> 1) + 1, r, pos);
  return u;
}
int Query(Node *u, Node *v, Node *p, Node *fp, int l, int r, int k) {
  if (l == r) return l;
  int sum = ((u ? u->l : NULL) ? (u ? u->l : NULL)->cnt : 0) +
            ((v ? v->l : NULL) ? (v ? v->l : NULL)->cnt : 0) -
            ((p ? p->l : NULL) ? (p ? p->l : NULL)->cnt : 0) -
            ((fp ? fp->l : NULL) ? (fp ? fp->l : NULL)->cnt : 0);
  if (sum >= k) {
    return Query((u ? u->l : NULL), (v ? v->l : NULL), (p ? p->l : NULL),
                 (fp ? fp->l : NULL), l, ((l + r) >> 1), k);
  } else {
    return Query((u ? u->r : NULL), (v ? v->r : NULL), (p ? p->r : NULL),
                 (fp ? fp->r : NULL), ((l + r) >> 1) + 1, r, k - sum);
  }
}
void Bfs(int n, int m) {
  queue<int> q;
  q.push(1);
  q.push(0);
  q.push(0);
  Roots[0] = NULL;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    int p = q.front();
    q.pop();
    int l = q.front();
    q.pop();
    L[u] = l;
    T[u] = p;
    Roots[u] = Roots[p];
    for (int i = 0; i < (int)ppl[u].size(); i++) {
      int x = ppl[u][i];
      Roots[u] = Update(Roots[u], 1, m, x);
    }
    for (int i = 0; i < (int)adj[u].size(); i++) {
      int v = adj[u][i];
      if (v != p) {
        q.push(v);
        q.push(u);
        q.push(l + 1);
      }
    }
  }
}
void Sparse(int n) {
  for (int i = 1; i <= n; i++) PP[i][0] = T[i];
  for (int j = 1; (1 << j) < n; j++) {
    for (int i = 1; i <= n; i++) {
      if (PP[i][j - 1]) PP[i][j] = PP[PP[i][j - 1]][j - 1];
    }
  }
}
int LCA(int p, int q) {
  if (L[p] < L[q]) swap(p, q);
  int b;
  for (b = 1; (1 << b) <= L[p]; b++)
    ;
  b--;
  for (int i = b; i >= 0; i--) {
    if (L[p] - (1 << i) >= L[q]) p = PP[p][i];
  }
  if (p == q) return p;
  for (int i = b; i >= 0; i--) {
    if (PP[p][i] && PP[p][i] != PP[q][i]) {
      p = PP[p][i];
      q = PP[q][i];
    }
  }
  return T[p];
}
int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= m; i++) {
    int(x);
    scanf("%d", &x);
    ppl[x].push_back(i);
  }
  Roots[0] = NULL;
  Bfs(n, m);
  Sparse(n);
  while (q--) {
    int u, v, a;
    scanf("%d%d%d", &u, &v, &a);
    int lca = LCA(u, v);
    int cnt = (Roots[u] ? Roots[u]->cnt : 0) + (Roots[v] ? Roots[v]->cnt : 0) -
              (Roots[lca] ? Roots[lca]->cnt : 0) -
              (Roots[T[lca]] ? Roots[T[lca]]->cnt : 0);
    int k = min(cnt, a);
    vector<int> xx;
    for (int i = 1; i <= k; i++) {
      int x = Query(Roots[u], Roots[v], Roots[lca], Roots[T[lca]], 1, m, i);
      xx.push_back(x);
    }
    printf("%d", (int)xx.size());
    for (int i = 0; i < (int)xx.size(); i++) printf(" %d", xx[i]);
    printf("\n");
    ;
  }
  return 0;
}
