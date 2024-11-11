#include <bits/stdc++.h>
using namespace std;
int n, m, name[100100];
vector<int> g[100100];
bool dfs(int i, int c, int p) {
  name[i] = 1 + c;
  for (int j : g[i]) {
    if (j != p) {
      if (name[j] == 0) {
        bool ch = dfs(j, 1 - c, i);
        if (ch == false) {
          return false;
        }
      } else {
        if (name[j] == name[i]) {
          return false;
        } else {
          if ((name[i] == 1 && i < j) || (name[i] == 2 && i > j)) {
            return false;
          }
        }
      }
    }
  }
  return true;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1, u, v; i <= m; ++i) {
    scanf("%d %d", &u, &v);
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  for (int i = n; i >= 1; --i) {
    if (name[i] == 0 && g[i].size() > 0) {
      bool ch = dfs(i, 0, -1);
      if (ch == false) {
        puts("0");
        exit(0);
      }
    }
  }
  int one = n + 1, two = 0;
  for (int i = 1; i <= n; ++i) {
    if (name[i] == 1) {
      one = min(one, i);
    } else if (name[i] == 2) {
      two = max(two, i);
    }
  }
  if (one <= two) {
    puts("0");
    exit(0);
  }
  int C = 0;
  for (int i = 1; i < n; ++i) {
    if (name[i] == 1) {
      break;
    }
    if (i >= two && i < one) {
      ++C;
    }
  }
  cout << C << "\n";
  return 0;
}
