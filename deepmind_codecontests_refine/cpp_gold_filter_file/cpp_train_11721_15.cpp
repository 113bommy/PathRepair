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
int Root[200007];
struct Node {
  int l, r, sum;
  Node() { l = r = sum = 0; }
};
int avail;
Node Tree[200007 * 20];
int Upd(int id, int l, int r, int pos, int v) {
  int u = ++avail;
  Tree[u] = Tree[id];
  if (l == r) {
    Tree[u].sum = v;
    return u;
  }
  int mid = (l + r) / 2;
  if (pos <= mid)
    Tree[u].l = Upd(Tree[u].l, l, mid, pos, v);
  else
    Tree[u].r = Upd(Tree[u].r, mid + 1, r, pos, v);
  Tree[u].sum = Tree[Tree[u].l].sum + Tree[Tree[u].r].sum;
  return u;
}
int Qry(int id, int l, int r, int k) {
  int ans = r;
  while (l < r) {
    int mid = (l + r) / 2;
    if (Tree[Tree[id].l].sum > k) {
      r = mid;
      id = Tree[id].l;
    } else {
      ans = mid;
      l = mid + 1;
      k -= Tree[Tree[id].l].sum;
      id = Tree[id].r;
    }
  }
  return ans + 1;
}
int Last[200007];
int a[200007];
int vis[200007], KS;
int main() {
  Tree[0] = Node();
  int n;
  n = in<int>();
  for (int i = 1; i < n + 1; i++) a[i] = in<int>();
  for (int i = n + 1 - 1; i >= 1; i--) {
    int x = a[i];
    if (Last[x]) {
      Root[i] = Upd(Root[i + 1], 1, n, Last[x], 0);
      Last[x] = i;
      Root[i] = Upd(Root[i], 1, n, i, 1);
    } else {
      Last[x] = i;
      Root[i] = Upd(Root[i + 1], 1, n, i, 1);
    }
  }
  for (int i = 1; i <= n; i++) {
    int ps = 1;
    int ans = 0;
    int ls = ps;
    while (ps <= n) {
      ans++;
      if (Tree[Root[ps]].sum <= i) break;
      ps = Qry(Root[ps], 1, n, i);
    }
    printf("%d ", ans);
  }
  printf("\n");
  return 0;
}
