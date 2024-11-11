#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const double oula = 0.57721566490153286060651209;
using namespace std;
vector<int> ve[1000006];
int n;
struct sair {
  string str;
  int v;
} a[1000006];
int val[1000006];
int ans[1000006];
int vis[1000006];
void dfs1(int pos) {
  int ans;
  if (a[pos].str == "AND") {
    for (int i = 0; i < ve[pos].size(); i++) {
      dfs1(ve[pos][i]);
    }
    val[pos] = val[ve[pos][0]] & val[ve[pos][1]];
  } else if (a[pos].str == "IN") {
    val[pos] = a[pos].v;
  } else if (a[pos].str == "XOR") {
    for (int i = 0; i < ve[pos].size(); i++) {
      dfs1(ve[pos][i]);
    }
    val[pos] = val[ve[pos][0]] ^ val[ve[pos][1]];
  } else if (a[pos].str == "NOT") {
    dfs1(ve[pos][0]);
    val[pos] = !val[ve[pos][0]];
  } else {
    for (int i = 0; i < ve[pos].size(); i++) {
      dfs1(ve[pos][i]);
    }
    val[pos] = val[ve[pos][0]] | val[ve[pos][1]];
  }
}
void dfs2(int pos) {
  int x, y;
  if (a[pos].str == "IN") {
    ans[pos] = !val[1];
  } else if (a[pos].str == "AND") {
    x = val[ve[pos][0]], y = val[ve[pos][1]];
    if (x == 0 && y == 1) {
      dfs2(ve[pos][0]);
    } else if (x == 1 && y == 0) {
      dfs2(ve[pos][1]);
    } else if (x == 1 && y == 1) {
      dfs2(ve[pos][0]);
      dfs2(ve[pos][1]);
    }
  } else if (a[pos].str == "OR") {
    x = val[ve[pos][0]], y = val[ve[pos][1]];
    if (x == 1 && y == 0) {
      dfs2(ve[pos][0]);
    } else if (x == 0 && y == 1) {
      dfs2(ve[pos][1]);
    } else if (x == 0 && y == 0) {
      dfs2(ve[pos][0]);
      dfs2(ve[pos][1]);
    }
  } else if (a[pos].str == "XOR") {
    x = val[ve[pos][0]], y = val[ve[pos][1]];
    if (x == 0 && y == 0) {
      dfs2(ve[pos][0]);
      dfs2(ve[pos][1]);
    } else if (x == 1 && y == 1) {
      dfs2(ve[pos][0]);
      dfs2(ve[pos][1]);
    } else if (x == 0 && y == 1) {
      dfs2(ve[pos][0]);
      dfs2(ve[pos][1]);
    } else if (x == 1 && y == 0) {
      dfs2(ve[pos][0]);
      dfs2(ve[pos][1]);
    }
  } else if (a[pos].str == "NOT") {
    x = val[ve[pos][0]];
    dfs2(ve[pos][0]);
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n;
  string str;
  int x, y;
  for (int i = 1; i <= n; i++) {
    cin >> str >> x;
    a[i].str = str;
    if (str == "AND") {
      cin >> y;
      ve[i].push_back(x);
      ve[i].push_back(y);
      a[i].v = 0;
    } else if (str == "IN") {
      a[i].v = x;
    } else if (str == "XOR") {
      cin >> y;
      ve[i].push_back(x);
      ve[i].push_back(y);
      a[i].v = 0;
    } else if (str == "NOT") {
      ve[i].push_back(x);
      a[i].v = 0;
    } else {
      cin >> y;
      ve[i].push_back(x);
      ve[i].push_back(y);
      a[i].v = 0;
    }
  }
  dfs1(1);
  for (int i = 1; i <= n; i++) ans[i] = val[1];
  dfs2(1);
  for (int i = 1; i <= n; i++) {
    if (a[i].str == "IN") {
      cout << ans[i];
    }
  }
  cout << endl;
}
