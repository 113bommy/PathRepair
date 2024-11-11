#include <bits/stdc++.h>
using namespace std;
const int Nmax = 2e5 + 5;
const int Bsize = 1 << 17;
double val, fail[Nmax], sum[Nmax];
int t[Nmax], x, y, i, n, q;
vector<int> v[Nmax];
char buffer[Bsize + 2];
int cursor = 0;
void read(int &x) {
  x = 0;
  while (!isdigit(buffer[cursor])) {
    ++cursor;
    if (cursor == Bsize) fread(buffer, 1, Bsize, stdin), cursor = 0;
  }
  while (isdigit(buffer[cursor])) {
    x = x * 10 + buffer[cursor] - '0';
    ++cursor;
    if (cursor == Bsize) fread(buffer, 1, Bsize, stdin), cursor = 0;
  }
}
void read(double &x) {
  x = 0;
  while (!isdigit(buffer[cursor])) {
    ++cursor;
    if (cursor == Bsize) fread(buffer, 1, Bsize, stdin), cursor = 0;
  }
  while (isdigit(buffer[cursor])) {
    x = x * 10 + buffer[cursor] - '0';
    ++cursor;
    if (cursor == Bsize) fread(buffer, 1, Bsize, stdin), cursor = 0;
  }
  if (buffer[cursor] != '.') return;
  ++cursor;
  if (cursor == Bsize) fread(buffer, 1, Bsize, stdin), cursor = 0;
  double y = 0;
  while (isdigit(buffer[cursor])) {
    y = y * 10 + buffer[cursor] - '0';
    ++cursor;
    if (cursor == Bsize) fread(buffer, 1, Bsize, stdin), cursor = 0;
  }
  x += y / 100;
}
void dfs(int node, int dad = -1) {
  t[node] = dad;
  for (auto it : v[node])
    if (it != dad) {
      dfs(it, node);
      sum[node] += fail[it];
    }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fread(buffer, 1, Bsize, stdin), cursor = 0;
  read(n);
  for (i = 0; i < n; ++i) read(fail[i]);
  for (i = 1; i < n; ++i) {
    read(x);
    read(y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  dfs(1);
  double ans = -1;
  for (i = 0; i < n; ++i) {
    ans += (1 - fail[i]) * (2 - (int)v[i].size());
    ans += fail[i];
    ans -= fail[i] * sum[i];
  }
  cout << setprecision(5) << fixed;
  int node;
  read(q);
  for (i = 1; i <= q; ++i) {
    read(node);
    read(val);
    val -= fail[node];
    fail[node] += val;
    if (t[node] != -1) sum[t[node]] += val, ans -= val * fail[t[node]];
    ans += val;
    ans -= val * sum[node];
    ans -= val * (2 - (int)v[node].size());
    cout << ans << '\n';
  }
  return 0;
}
