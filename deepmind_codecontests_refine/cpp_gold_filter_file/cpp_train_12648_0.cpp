#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int a[N], n;
pair<long long, long long> operator+(const pair<long long, long long> &a,
                                     const pair<long long, long long> &b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
struct node {
  int ch[2], p;
  pair<long long, long long> s, t;
} T[N];
int tl = 0;
void rot(int first, int d) {
  int second = T[first].ch[d];
  swap(T[first], T[second]), swap(first, second);
  T[first].ch[d] = T[second].ch[d ^ 1], T[second].ch[d ^ 1] = first;
}
void push(int first) {
  T[first].s = T[first].s + T[first].t;
  for (int d = 0; d <= 1; d++) {
    int second = T[first].ch[d];
    if (second) T[second].t = T[second].t + T[first].t;
  }
  T[first].t = make_pair(0, 0);
}
void add(int &first, int a, int t) {
  if (!first)
    first = ++tl, T[first].p = rand() * rand(),
    T[first].s = make_pair(1LL * a * t, t);
  else {
    push(first);
    if (T[first].s.first >= a * T[first].s.second) {
      int &second = T[first].ch[1];
      add(second, a, T[first].s.second + 1);
      if (T[second].p < T[first].p) rot(first, 1);
    } else {
      int &second = T[first].ch[0];
      T[first].s = T[first].s + make_pair(a, 1);
      {
        int second = T[first].ch[1];
        if (second) T[second].t = T[second].t + make_pair(a, 1);
      }
      add(second, a, T[first].s.second - 1);
      if (T[second].p < T[first].p) rot(first, 0);
    }
  }
}
int l = 0;
long long G[N];
void dfs(int first) {
  push(first);
  if (T[first].ch[0]) dfs(T[first].ch[0]);
  G[++l] = T[first].s.first;
  if (T[first].ch[1]) dfs(T[first].ch[1]);
}
int main() {
  srand(233);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int rt = 0;
  for (int i = 1; i <= n; i++) add(rt, a[i], 1);
  dfs(rt);
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    if (G[i] > 0)
      ans += G[i];
    else
      break;
  printf("%I64d\n", ans);
  return 0;
}
