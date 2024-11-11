#include <bits/stdc++.h>
using namespace std;
char s[1111][1111];
int lessthan[2222];
vector<int> morethan[2222];
int f[2222], in[2222];
int root(int u) { return u == f[u] ? u : f[u] = root(f[u]); }
void merge(int u, int v) { f[root(u)] = root(v); }
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int N = n + m;
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s[i] + 1);
  }
  for (int i = 1; i <= N; ++i) f[i] = i;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s[i][j] == '=') {
        merge(i, n + j);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s[i][j] == '>') {
        morethan[root(n + j)].push_back(root(i));
      } else if (s[i][j] == '<') {
        morethan[root(i)].push_back(root(n + j));
      }
    }
  }
  for (int i = 1; i <= N; ++i) {
    for (auto x : morethan[i]) {
      lessthan[x]++;
    }
  }
  set<int> st1, st2;
  for (int i = 1; i <= N; ++i) {
    if (f[i] == i && lessthan[i] == 0) st1.insert(i);
  }
  int cnt = 0;
  while (!st1.empty()) {
    ++cnt;
    for (int i : st1) {
      in[i] = cnt;
      for (int &j : morethan[i]) {
        --lessthan[j];
        if (lessthan[j] == 0) {
          st2.insert(j);
        }
      }
    }
    st1 = st2;
    st2.clear();
  }
  for (int i = 1; i <= N; ++i) {
    if (f[i] == i && !in[i]) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  for (int i = 1; i <= N; ++i) {
    printf("%d ", in[root(i)]);
    if (i == n) puts("");
  }
  return 0;
}
