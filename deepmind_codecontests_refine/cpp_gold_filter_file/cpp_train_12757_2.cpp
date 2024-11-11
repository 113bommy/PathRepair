#include <bits/stdc++.h>
using namespace std;
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
inline T POW(T B, T P) {
  if (P == 0) return 1;
  if (P & 1)
    return B * POW(B, P - 1);
  else
    return (POW(B, P / 2) * POW(B, P / 2));
}
template <typename T>
inline T Gcd(T a, T b) {
  if (a < 0) return Gcd(-a, b);
  if (b < 0) return Gcd(a, -b);
  return (b == 0) ? a : Gcd(b, a % b);
}
template <typename T>
inline T Lcm(T a, T b) {
  if (a < 0) return Lcm(-a, b);
  if (b < 0) return Lcm(a, -b);
  return a * (b / Gcd(a, b));
}
long long Bigmod(long long base, long long power, long long MOD) {
  long long ret = 1;
  while (power) {
    if (power & 1) ret = (ret * base) % MOD;
    base = (base * base) % MOD;
    power >>= 1;
  }
  return ret;
}
bool isVowel(char ch) {
  ch = toupper(ch);
  if (ch == 'A' || ch == 'U' || ch == 'I' || ch == 'O' || ch == 'E')
    return true;
  return false;
}
template <typename T>
long long int isLeft(T a, T b, T c) {
  return (a.x - b.x) * (b.y - c.y) - (b.x - c.x) * (a.y - b.y);
}
long long ModInverse(long long number, long long MOD) {
  return Bigmod(number, MOD - 2, MOD);
}
bool isConst(char ch) {
  if (isalpha(ch) && !isVowel(ch)) return true;
  return false;
}
int toInt(string s) {
  int sm;
  stringstream second(s);
  second >> sm;
  return sm;
}
vector<int> A[400007];
int Lv[400007];
int St[400007];
int Ed[400007];
int dp[400007];
int T;
int Node[400007];
void Dekhi(int u, int p, int L) {
  Lv[u] = L;
  dp[u] = 1;
  St[u] = ++T;
  Node[T] = u;
  for (int i = 0; i < A[u].size(); i++) {
    int v = A[u][i];
    if (v == p) continue;
    Dekhi(v, u, L + 1);
    dp[u] += dp[v];
  }
  Ed[u] = T;
}
int Tree[400007 * 4];
int Id[400007 * 4];
void Up(int id, int l, int r, int pos, int v, int nd) {
  if (l == r) {
    Tree[id] = v;
    Id[id] = nd;
    return;
  }
  int mid = (l + r) / 2;
  int lft = 2 * id;
  int rgt = lft + 1;
  if (pos <= mid)
    Up(lft, l, mid, pos, v, nd);
  else
    Up(rgt, mid + 1, r, pos, v, nd);
  if (Tree[rgt] >= Tree[lft]) {
    Tree[id] = Tree[rgt];
    Id[id] = Id[rgt];
  } else {
    Tree[id] = Tree[lft];
    Id[id] = Id[lft];
  }
  return;
}
int wow(int id, int l, int r, int st, int ed) {
  if (l >= st && r <= ed) return Tree[id];
  int mid = (l + r) / 2;
  int lft = 2 * id;
  int rgt = lft + 1;
  if (ed <= mid)
    return wow(lft, l, mid, st, ed);
  else if (st > mid)
    return wow(rgt, mid + 1, r, st, ed);
  else {
    return max(wow(lft, l, mid, st, ed), wow(rgt, mid + 1, r, st, ed));
  }
}
int N;
int Qry(int id, int l, int r, int st, int ed, int v) {
  if (l == r) {
    return Id[id];
  }
  int mid = (l + r) / 2;
  int lft = 2 * id;
  int rgt = lft + 1;
  if (ed <= mid)
    return Qry(lft, l, mid, st, ed, v);
  else if (st > mid)
    return Qry(rgt, mid + 1, r, st, ed, v);
  else {
    int rf = wow(1, 1, N, mid + 1, min(r, ed));
    if (rf >= v)
      return Qry(rgt, mid + 1, r, st, ed, v);
    else
      Qry(lft, l, mid, st, ed, v);
  }
}
int main() {
  int n, m;
  n = in<int>(), m = in<int>();
  N = n;
  for (int i = 2; i < n + 1; i++) {
    int x;
    x = in<int>();
    A[x].push_back(i);
  }
  Dekhi(1, 0, 1);
  for (int i = 1; i < T + 1; i++) {
    Up(1, 1, n, i, dp[Node[i]], Node[i]);
  }
  for (int i = 1; i < m + 1; i++) {
    int x;
    x = in<int>();
    if (dp[x] == 1) {
      printf("%d\n", x);
    } else {
      int s = St[x];
      int e = Ed[x];
      int mn = dp[x] / 2;
      if (dp[x] % 2) mn++;
      int an = Qry(1, 1, n, s, e, mn);
      printf("%d\n", an);
    }
  }
  return 0;
}
