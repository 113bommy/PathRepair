#include <bits/stdc++.h>
using namespace std;
const int INFI = (1 << 30);
const long long INFL = (1LL << 62);
const long long md = 1000000007;
int nr = 0;
int son[100001][2];
int tp[100001], fh[100001];
void build(int n) {
  string a;
  if (!(cin >> a)) {
    cout << "Error occurred";
    exit(0);
  }
  nr++;
  son[n][0] = nr;
  fh[nr] = n;
  if (a == "pair") {
    tp[nr] = 1;
    build(nr);
  } else if (a == "int")
    tp[nr] = 2;
  if (!(cin >> a)) {
    cout << "Error occurred";
    exit(0);
  }
  nr++;
  son[n][1] = nr;
  fh[nr] = n;
  if (a == "pair") {
    tp[nr] = 1;
    build(nr);
  } else if (a == "int")
    tp[nr] = 2;
  return;
}
void dfs(int n) {
  int u, v;
  u = son[n][0];
  v = son[n][1];
  if (tp[u] == 1) {
    cout << "pair<";
    dfs(u);
    cout << ">,";
  } else
    cout << "int,";
  if (tp[v] == 1) {
    cout << "pair<";
    dfs(v);
    cout << ">";
  } else
    cout << "int";
}
int main() {
  int n;
  cin >> n;
  string a;
  if (!(cin >> a)) {
    cout << "Error occurred";
    return 0;
  }
  nr++;
  if (a == "pair") {
    tp[1] = 1;
  } else if (a == "int") {
    if (n == 1 && !(cin >> a)) {
      cout << "int";
      return 0;
    }
    cout << "Error occurred";
    return 0;
  }
  build(1);
  if (cin >> a) {
    cout << "Error occurred";
    return 0;
  }
  for (int i = 1; i <= nr; i++)
    if (tp[i] == 1 && (!son[i][0] || !son[i][1])) {
      cout << "Error occurred";
      return 0;
    }
  cout << "pair<";
  dfs(1);
  cout << ">";
  return 0;
}
