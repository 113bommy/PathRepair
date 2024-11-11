#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
template <typename T>
inline void gn(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <class T, class T1>
inline void gn(T &first, T1 &second) {
  gn(first);
  gn(second);
}
template <class T, class T1, class T2>
inline void gn(T &first, T1 &second, T2 &z) {
  gn(first);
  gn(second);
  gn(z);
}
template <typename T>
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
template <typename T>
inline void println(T first) {
  print(first), putchar('\n');
}
template <typename T>
inline void printsp(T first) {
  print(first), putchar(' ');
}
template <class T, class T1>
inline void print(T first, T1 second) {
  printsp(first), println(second);
}
template <class T, class T1, class T2>
inline void print(T first, T1 second, T2 z) {
  printsp(first), printsp(second), println(z);
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
char s[55][55];
int root[55], val[55], adj[55];
vector<int> v[55];
int can[1 << 23];
int mx[55], mn[1 << 23];
int find_root(int u) { return u == root[u] ? u : root[u] = find_root(root[u]); }
int main() {
  int n;
  gn(n);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  for (int i = 0; i < n; i++) root[i] = i;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (s[i][j] == 'A') {
        int u = find_root(i);
        int v = find_root(j);
        root[v] = u;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    v[find_root(i)].push_back(i);
  }
  for (int i = 0; i < n; i++)
    if (find_root(i) == i) {
      for (int j = 0; j < v[i].size(); j++) {
        for (int k = 0; k < j; k++) {
          if (s[v[i][j]][v[i][k]] == 'X') return puts("-1"), 0;
        }
      }
    }
  int nn = 0;
  for (int i = 0; i < n; i++) {
    if (root[i] == i && v[i].size() > 1) val[i] = nn++;
  }
  for (int i = 0; i < nn; i++) adj[i] = 1 << i;
  for (int i = 0; i < n; i++)
    if (find_root(i) == i && v[i].size() > 1) {
      for (int j = 0; j < i; j++)
        if (find_root(j) == j && v[j].size() > 1) {
          int ok = 1;
          for (int a = 0; ok && a < v[i].size(); a++) {
            for (int b = 0; ok && b < v[j].size(); b++) {
              if (s[v[i][a]][v[j][b]] == 'X') ok = 0;
            }
          }
          if (ok) adj[val[i]] |= (1 << val[j]), adj[val[j]] |= (1 << val[i]);
        }
    }
  for (int i = 0; i < n; i++) v[i].clear();
  can[0] = 1;
  for (int i = 1; i < 1 << nn; i++) {
    can[i] = can[i - (1 << (__builtin_ctz(i)))] &&
             (adj[(__builtin_ctz(i))] & i - (1 << (__builtin_ctz(i)))) ==
                 (i - (1 << (__builtin_ctz(i))));
    if (can[i]) {
      for (int j = 0; j < nn; j++) {
        if ((((i) >> (j)) & 1)) smax(mx[j], (__builtin_popcount(i)));
      }
    }
  }
  for (int i = 1; i < 1 << nn; i++)
    if (can[i]) {
      for (int j = 0; j < nn; j++) {
        if ((((i) >> (j)) & 1) && (__builtin_popcount(i)) == mx[j])
          v[j].push_back(i);
      }
    }
  for (int i = 1; i < 1 << nn; i++) {
    mn[i] = 0x3f3f3f3f;
    for (int j = 0; j < nn; j++)
      if ((((i) >> (j)) & 1)) {
        smin(mn[i], mn[i - (1 << j)] + 1);
        for (int k = 0; k < v[j].size(); k++) {
          smin(mn[i], mn[i - (i & v[j][k])] + 1);
        }
      }
  }
  println(n + mn[(1 << nn) - 1] - 1);
  return 0;
}
