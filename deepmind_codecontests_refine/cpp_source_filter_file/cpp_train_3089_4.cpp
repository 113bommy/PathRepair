#include <bits/stdc++.h>
using namespace std;
template <typename T>
void alert(const T& t) {
  cout << t << endl;
  exit(0);
}
long long n, a, b;
vector<bool> used;
int cmp = 0;
void CALC(vector<vector<int>>& g, int p) {
  used[p] = true;
  for (auto& it : g[p]) {
    if (!used[it]) CALC(g, it);
  }
}
long long DFS(vector<vector<int>>& g) {
  used.assign(n, false);
  cmp = 0;
  for (int i = 0; i < g.size(); ++i) {
    if (!used[i]) {
      CALC(g, i);
      cmp++;
    }
  }
  return cmp;
}
pair<long long, string> mx = {0, ""};
pair<long long, string> mn = {0, ""};
bool Check(string& s) {
  long long l = 0, r = 0;
  vector<vector<int>> g(n, vector<int>());
  vector<vector<int>> rg(n, vector<int>());
  for (int i = 0; i < s.size(); ++i) {
    char ch = s[i];
    int v = i / n;
    int u = i % n;
    if (ch == '1') {
      g[v].push_back(u);
      g[u].push_back(v);
    } else {
      rg[v].push_back(u);
      rg[u].push_back(v);
    }
  }
  long long aa = DFS(g);
  long long bb = DFS(rg);
  return aa == a && bb == b;
}
void Print(vector<vector<char>>& g) {
  cout << "YES" << endl;
  for (int i = 0; i < g.size(); ++i) {
    for (auto& it : g[i]) cout << it << "";
    cout << endl;
  }
}
void Print(string& s) {
  vector<vector<char>> g(n, vector<char>(n, '0'));
  for (int i = 0; i < s.size(); ++i) {
    char ch = s[i];
    int v = i / n;
    int u = i % n;
    if (ch == '1') {
      g[v][u] = '1';
      g[u][v] = '1';
    }
  }
}
set<string> ma;
void Gready(string& s) {
  if (ma.count(s)) return;
  ma.insert(s);
  if (Check(s)) {
    Print(s);
  }
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '0' && (i % (n + 1) != 0)) {
      s[i] = '1';
      Gready(s);
      s[i] = '0';
    }
  }
}
int main() {
  {}
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> a >> b;
  string s(n * n, '0');
  vector<vector<char>> g(n, vector<char>(n, '0'));
  bool change = false;
  if (a == 1 || b == 1) {
    if (b == 1) {
      swap(a, b);
      change = true;
    }
    if (n == 1) alert("YES\n0");
    if (n <= 3 || b == 1) alert("NO");
    g.assign(n, vector<char>(n, '1'));
    int need = n - b;
    for (int i = 0; i < need; ++i) {
      int v = i;
      int u = i + 1;
      g[u][v] = '0';
      g[v][u] = '0';
    }
    if (change) {
      for (auto& it : g)
        for (auto& ti : it) ti = (ti == '0' ? '1' : '0');
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) g[i][j] = '0';
      }
    }
    Print(g);
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
