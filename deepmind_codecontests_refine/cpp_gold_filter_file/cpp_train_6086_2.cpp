#include <bits/stdc++.h>
using namespace std;
template <typename T>
void Read(T &x) {
  char ch;
  bool neg = 0;
  x = 0;
  while (!isdigit(ch = getchar()) && ch != '-')
    ;
  if (ch == '-') {
    neg = 1;
    ch = getchar();
  }
  do {
    x = x * 10 + ch - 48;
  } while (isdigit(ch = getchar()));
  if (neg) x = -x;
  return;
}
template <typename T>
void Write(T x) {
  char ch[32];
  int cnt = 0;
  bool neg = 0;
  if (x < 0) {
    neg = 1;
    x = -x;
  }
  do {
    ch[++cnt] = x % 10 + 48;
    x /= 10;
  } while (x);
  if (neg) putchar('-');
  for (int i = (cnt); i >= (1); --i) putchar(ch[i]);
}
template <typename T>
void Writeln(T x) {
  Write(x);
  putchar('\n');
}
template <typename T>
void Writesp(T x) {
  Write(x);
  putchar(' ');
}
const int MAX = 1e5 + 5;
const int INF = 0x3f3f3f3f;
struct SegmentMin {
  pair<int, int> Tree[MAX << 2];
  void Init(int n) {
    for (int i = (1); i <= (n << 2); ++i) Tree[i] = pair<int, int>(INF, 1);
  }
  void Update(int id, int l, int r, int u, int val) {
    if (l > u || r < u) return;
    if (l == r) {
      Tree[id] = pair<int, int>(val, 1);
      return;
    }
    int mid = (l + r) >> 1;
    Update(2 * id, l, mid, u, val);
    Update(2 * id + 1, mid + 1, r, u, val);
    if (Tree[2 * id].first < Tree[2 * id + 1].first)
      Tree[id] = Tree[2 * id];
    else if (Tree[2 * id].first > Tree[2 * id + 1].first)
      Tree[id] = Tree[2 * id + 1];
    else
      Tree[id] = pair<int, int>(Tree[2 * id].first,
                                Tree[2 * id].second + Tree[2 * id + 1].second);
  }
  pair<int, int> Query(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return pair<int, int>(INF, 1);
    if (l >= u && r <= v) return Tree[id];
    int mid = (l + r) >> 1;
    pair<int, int> L = Query(2 * id, l, mid, u, v);
    pair<int, int> R = Query(2 * id + 1, mid + 1, r, u, v);
    if (L.first < R.first)
      return L;
    else if (L.first > R.first)
      return R;
    else
      return pair<int, int>(L.first, L.second + R.second);
  }
} IT0;
struct SegmentGCD {
  int Tree[MAX << 2];
  void Init(int n) {
    for (int i = (1); i <= (n << 2); ++i) Tree[i] = 1;
  }
  int GCD(int x, int y) {
    if (!y) return x;
    return GCD(y, x % y);
  }
  void Update(int id, int l, int r, int u, int val) {
    if (l > u || r < u) return;
    if (l == r) {
      Tree[id] = val;
      return;
    }
    int mid = (l + r) >> 1;
    Update(2 * id, l, mid, u, val);
    Update(2 * id + 1, mid + 1, r, u, val);
    Tree[id] = GCD(Tree[2 * id], Tree[2 * id + 1]);
  }
  int Query(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) return Tree[id];
    int mid = (l + r) >> 1;
    int L = Query(2 * id, l, mid, u, v);
    int R = Query(2 * id + 1, mid + 1, r, u, v);
    if (L == 0) return R;
    if (R == 0) return L;
    return GCD(L, R);
  }
} IT1;
int main(int argc, char const *argv[]) {
  int n, q;
  int u, v;
  Read(n);
  IT0.Init(n);
  IT1.Init(n);
  for (int i = (1); i <= (n); ++i) {
    Read(u);
    IT0.Update(1, 1, n, i, u);
    IT1.Update(1, 1, n, i, u);
  }
  Read(q);
  for (int i = (1); i <= (q); ++i) {
    Read(u);
    Read(v);
    pair<int, int> Min = IT0.Query(1, 1, n, u, v);
    int Gcd = IT1.Query(1, 1, n, u, v);
    if (Min.first != Gcd)
      Writeln(v - u + 1);
    else
      Writeln(v - u - Min.second + 1);
  }
  return 0;
}
