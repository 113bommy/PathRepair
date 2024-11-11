#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &a, T b) {
  return b < a ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, T b) {
  return b > a ? a = b, 1 : 0;
}
inline int read() {
  int x(0), sgn(1);
  char ch(getchar());
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') sgn = -1;
  for (; isdigit(ch); ch = getchar()) x = (x * 10) + (ch ^ 48);
  return x * sgn;
}
inline char read_char() {
  char ch(getchar());
  for (; !isupper(ch); ch = getchar())
    ;
  return ch;
}
void File() {}
const int N = 1e5 + 1e3;
int n, m;
template <int Maxn>
struct Fenwick_Tree {
  int sumv[Maxn];
  inline void Update(int pos, int uv) {
    for (; pos <= n; pos += (pos & -pos)) sumv[pos] += uv;
  }
  inline int Query(int pos) {
    int res = 0;
    for (; pos; pos -= (pos & -pos)) res += sumv[pos];
    return res;
  }
  inline int Query(int l, int r) { return Query(r) - Query(l - 1); }
};
int id[255], a[N];
Fenwick_Tree<N> T[3];
set<int> S[3];
inline void Insert(int pos, int val) {
  S[a[pos] = val].insert(pos);
  T[a[pos]].Update(pos, 1);
}
inline void Delete(int pos) {
  S[a[pos]].erase(pos);
  T[a[pos]].Update(pos, -1);
}
inline int Calc() {
  int res = 0;
  for (register int i = (0), iend = (int)(3); i < iend; ++i) {
    int u = (i + 1) % 3, v = (u + 1) % 3;
    if (S[u].empty()) {
      res += T[i].Query(1, n);
    } else if (!S[v].empty()) {
      int fu = *S[u].begin(), lu = *prev(S[u].end()), fv = *S[v].begin(),
          lv = *prev(S[v].end());
      if (fu < fv && lv < lu)
        res += T[i].Query(fv, lv) + T[i].Query(1, fu) + T[i].Query(lu, n);
      else if (fv < fu && lu < fv)
        res += T[i].Query(1, n);
      else if (fv < fu && fu < lv && lv < lu)
        res += T[i].Query(1, lv) + T[i].Query(lu, n);
      else if (fu < fv && fv < lu && lu < lv)
        res += T[i].Query(1, fu) + T[i].Query(fv, n);
      else if (lu < fv)
        res += T[i].Query(1, fu) + T[i].Query(fv, n);
      else
        res += T[i].Query(1, lv) + T[i].Query(lu, n);
    }
  }
  return res;
}
int main() {
  File();
  id['R'] = 0;
  id['P'] = 1;
  id['S'] = 2;
  n = read(), m = read();
  for (register int i = (1), iend = (int)(n); i <= iend; ++i)
    Insert(i, id[read_char()]);
  printf("%d\n", Calc());
  for (register int i = (1), iend = (int)(m); i <= iend; ++i) {
    int pos = read();
    Delete(pos);
    Insert(pos, id[read_char()]);
    printf("%d\n", Calc());
  }
  return 0;
}
