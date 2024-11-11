#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
struct debugger {
  static void call(const char* it) {}
  template <typename T, typename... valT>
  static void call(const char* it, T val, valT... rest) {
    string var = "";
    for (; *it && *it != ','; it++)
      if (*it != ' ') var += *it;
    cerr << var << '=' << val << " ";
    call(++it, rest...);
  }
};
const int MAX = 2e5 + 10;
int P[MAX], V[MAX], root = -1, cnt = 0;
void dfs(int u) {
  V[u] = 1;
  int v = P[u];
  if (!V[v]) {
    dfs(v);
  } else if (V[v] == 1) {
    if (root != u) {
      if (root == -1) root = u;
      P[u] = root, cnt++;
    }
  }
  V[u] = 2;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < (int)n; i++) {
    scanf("%d", &P[i + 1]);
    if (P[i + 1] == i + 1) root = i + 1;
  }
  for (int i = 0; i < (int)n; i++) {
    int u = i + 1;
    if (!V[u]) {
      dfs(u);
    }
  }
  printf("%d\n", cnt);
  for (int i = 0; i < (int)n; i++) {
    printf("%d ", P[i + 1]);
  }
  puts("");
}
