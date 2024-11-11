#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T abs(T t) {
  return t < 0 ? -t : t;
}
const long long modn = 1000000007;
inline long long mod(long long x) { return x % modn; }
namespace sf {
const int NS = 112345;
const int N = 2123456;
int cn, cd, ns, en = 1;
string S[NS];
int si = -1;
long long val[N];
int lst_chr(int si) { return '$'; }
struct node {
  int l, r, si;
  int p, suf;
  map<int, int> adj;
  node() : l(0), r(-1), suf(0), p(0) {}
  node(int L, int R, int S, int P) : l(L), r(R), si(S), p(P) {}
  inline int len() { return r - l + 1; }
  inline int operator[](int i) {
    return l + i == S[si].size() ? lst_chr(si) : S[si][l + i];
  }
  inline int &operator()(int c) { return adj[c]; }
} t[N];
inline int new_node(int L, int R, int S, int P) {
  t[en] = node(L, R, S, P);
  return en++;
}
void add_char(int c, int &i, int j, int n) {
  for (; i <= j; i++) {
    if (cd == t[cn].len() && t[cn](c)) cn = t[cn](c), cd = 0;
    if (cd < t[cn].len() && t[cn][cd] == c) {
      cd++;
      break;
    } else if (cd == t[cn].len()) {
      t[cn](c) = new_node(j, n - 1, si, cn);
      cn = t[cn].suf;
      cd = t[cn].len();
    } else {
      int mid = new_node(t[cn].l, t[cn].l + cd - 1, t[cn].si, t[cn].p);
      t[t[cn].p](t[cn][0]) = mid;
      if (ns) t[ns].suf = mid;
      t[mid](c) = new_node(j, n - 1, si, mid);
      t[mid](t[cn][cd]) = cn;
      t[cn].p = mid;
      t[cn].l += cd;
      cn = t[mid].p;
      int g = cn ? j - cd : i + 1;
      cn = t[cn].suf;
      while (g < j && g + t[t[cn](S[si][g])].len() <= j)
        cn = t[cn](S[si][g]), g += t[cn].len();
      if (g == j)
        ns = 0, t[mid].suf = cn, cd = t[cn].len();
      else
        ns = mid, cn = t[cn](S[si][g]), cd = j - g;
    }
  }
}
void add_string(string s) {
  S[++si] = s;
  cn = cd = 0;
  int i = 0;
  for (int j = 0; j < s.size(); j++) add_char(s[j], i, j, s.size() + 1);
  add_char(lst_chr(si), i, s.size(), s.size() + 1);
}
void proc(string &s, int si, int c) {
  cn = cd = 0;
  for (char c : s) {
    if (cd == t[cn].len()) cd = 0, cn = t[cn](c);
    cd++;
  }
  if (cd == t[cn].len()) cd = 0, cn = t[cn](lst_chr(si));
  cd++;
  assert(cd == t[cn].len());
  val[cn] += c;
  for (int i = 1; i <= s.size(); i++) {
    int g = t[cn].p ? s.size() + 1 - t[cn].len() : i;
    cn = t[cn].p;
    cn = t[cn].suf;
    while (g != s.size() + 1) {
      int c = g == s.size() ? lst_chr(si) : s[g];
      cn = t[cn](c);
      g += t[cn].len();
    }
    val[cn] += c;
  }
}
long long mx = 0;
long long dfs(int u, long long sz) {
  for (auto &e : t[u].adj) val[u] += dfs(e.second, sz + t[e.second].len());
  if (t[u].adj.empty()) sz--;
  mx = max(mx, val[u] * sz);
  return val[u];
}
};  // namespace sf
char s[500009];
int main() {
  int i, n, x;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", s);
    sf::add_string(s);
  }
  for (i = 0; i < n; i++) {
    scanf("%d", &x);
    sf::proc(sf::S[i], i, x);
  }
  sf::dfs(0, 0);
  printf("%I64d\n", sf::mx);
}
