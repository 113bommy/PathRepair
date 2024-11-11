#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && (c != '-')) c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
const int N = 1e6 + 10;
int n, m, vis[N], col[N];
vector<int> e[N];
int main() {
  n = read(), m = read();
  for (register int i = (1); i <= (m); i++) {
    int x = read(), y = read();
    e[x].push_back(y);
  }
  for (register int i = (1); i <= (n); i++)
    if (!vis[i]) {
      vis[i] = col[i] = 1;
      for (auto v : e[i]) vis[v] = 1;
    }
  for (register int i = (n); i >= (1); i--)
    if (col[i] == 1) {
      for (auto v : e[i]) col[v] = 0;
    }
  vector<int> ans;
  for (register int i = (1); i <= (n); i++)
    if (col[i]) ans.push_back(i);
  printf("%d\n", ((int)(ans).size()));
  for (auto i : ans) printf("%d ", i);
}
