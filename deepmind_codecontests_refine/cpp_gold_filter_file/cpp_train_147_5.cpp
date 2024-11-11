#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, const U &b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, const U &b) {
  if (a < b) a = b;
}
template <class T>
inline void gn(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <class T1, class T2>
inline void gn(T1 &x1, T2 &x2) {
  gn(x1), gn(x2);
}
template <class T1, class T2, class T3>
inline void gn(T1 &x1, T2 &x2, T3 &x3) {
  gn(x1, x2), gn(x3);
}
template <class T1, class T2, class T3, class T4>
inline void gn(T1 &x1, T2 &x2, T3 &x3, T4 &x4) {
  gn(x1, x2, x3), gn(x4);
}
template <class T1, class T2, class T3, class T4, class T5>
inline void gn(T1 &x1, T2 &x2, T3 &x3, T4 &x4, T5 &x5) {
  gn(x1, x2, x3, x4), gn(x5);
}
template <class T>
inline void print(T first) {
  if (first < 0) {
    putchar('-');
    return print(-first);
  }
  if (first < 10) {
    putchar('0' + first);
    return;
  }
  print(first / 10);
  putchar(first % 10 + '0');
}
template <class T>
inline void println(T first) {
  print(first);
  putchar('\n');
}
template <class T>
inline void printsp(T first) {
  print(first);
  putchar(' ');
}
template <class T1, class T2>
inline void print(T1 x1, T2 x2) {
  printsp(x1), println(x2);
}
template <class T1, class T2, class T3>
inline void print(T1 x1, T2 x2, T3 x3) {
  printsp(x1), printsp(x2), println(x3);
}
template <class T1, class T2, class T3, class T4>
inline void print(T1 x1, T2 x2, T3 x3, T4 x4) {
  printsp(x1), printsp(x2), printsp(x3), println(x4);
}
template <class T1, class T2, class T3, class T4, class T5>
inline void print(T1 x1, T2 x2, T3 x3, T4 x4, T5 x5) {
  printsp(x1), printsp(x2), printsp(x3), printsp(x4), println(x5);
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
vector<int> adj[300010];
int vst[300010], root[300010];
int d[300010], mx[300010];
void dfs(int u, int root) {
  vst[u] = 1;
  ::root[u] = root;
  int one = 0, two = 0;
  for (int i = adj[u].size(); i--;) {
    int v = adj[u][i];
    if (!vst[v]) {
      dfs(v, root);
      if (mx[v] + 1 > one) {
        two = one;
        one = mx[v] + 1;
      } else if (mx[v] + 1 > two)
        two = mx[v] + 1;
    }
  }
  smax(d[root], one + two);
  mx[u] = one;
}
int find_root(int u) {
  if (u == root[u]) return u;
  return root[u] = find_root(root[u]);
}
int main() {
  int n, m, q;
  gn(n, m, q);
  while (m--) {
    int u, v;
    gn(u, v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++)
    if (!vst[i]) {
      dfs(i, i);
    }
  while (q--) {
    int t, first, second;
    gn(t, first);
    if (t == 1)
      println(d[find_root(first)]);
    else {
      gn(second);
      first = find_root(first), second = find_root(second);
      if (first != second) {
        root[first] = second;
        d[second] = max(max(d[first], d[second]),
                        (d[first] + 1 >> 1) + (d[second] + 1 >> 1) + 1);
      }
    }
  }
}
