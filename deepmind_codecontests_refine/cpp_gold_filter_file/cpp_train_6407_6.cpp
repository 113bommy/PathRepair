#include <bits/stdc++.h>
using namespace std;
void read(int &x) { scanf("%d", &x); }
void read(long long int &x) { scanf("%I64d", &x); }
void read(long long int &a, long long int &b) { scanf("%I64d %I64d", &a, &b); }
void read(long long int &a, long long int &b, long long int &c) {
  scanf("%I64d %I64d %I64d", &a, &b, &c);
}
void read(long long int &a, long long int &b, long long int &c,
          long long int &d) {
  scanf("%I64d %I64d %I64d %I64d", &a, &b, &c, &d);
}
void read(double &x) { scanf("%lf", &x); }
void read(char &x) { scanf("%s", x); }
void read(string &x) {
  char y[1000006];
  scanf("%s", &y);
  x = y;
}
void print(long long int x, bool flag = false) {
  if (flag)
    printf("%I64d ", x);
  else
    printf("%I64d\n", x);
}
void print(int x, bool flag = false) {
  if (flag)
    printf("%d ", x);
  else
    printf("%d\n", x);
}
void print(double x, bool flag = false) {
  if (flag)
    printf("%lf ", x);
  else
    printf("%lf\n", x);
}
void print(char x) { printf("%c\n", x); }
void print(string x) {
  for (long long int i = 0; i < x.size(); i++) {
    printf("%c", x[i]);
  }
  printf("\n");
}
vector<long long int> graph[1001];
long long int vis[1001];
bool dfs(long long int node, long long int par) {
  vis[node] = true;
  for (auto child : graph[node]) {
    if (vis[child] == false) {
      if (dfs(child, node) == true) return true;
    } else if (child != par)
      return true;
  }
  return false;
}
int main() {
  long long int n, m;
  read(n, m);
  while (m--) {
    long long int a, b;
    read(a, b);
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  long long int cc = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i] == false) {
      cc++;
      if (dfs(i, -1) == true) {
        print("no");
        return 0;
      }
    }
  }
  if (cc == 1)
    print("yes");
  else
    print("no");
  cerr << "time taken : " << (float)clock() / (float)CLOCKS_PER_SEC << " secs"
       << endl;
  return 0;
}
