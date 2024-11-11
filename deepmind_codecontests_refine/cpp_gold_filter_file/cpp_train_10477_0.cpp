#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize(3, "Ofast", "inline")
const long long mod = 1e9 + 7;
long long gcd(long long a, long long b) {
  long long r;
  while (b > 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
long long llread() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
int intread() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
long long fp(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
const int maxn = 505;
int in[maxn], in2[maxn];
vector<int> v[maxn];
queue<int> q;
bool vis[505];
int solve(int s, int n) {
  memset(vis, 0, sizeof(vis));
  while (!q.empty()) q.pop();
  int tot = 0;
  for (int i = 1; i <= n; i++) in2[i] = in[i];
  in2[s]--;
  for (int i = 1; i <= n; i++) {
    if (!in2[i]) q.push(i);
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    if (vis[x]) continue;
    vis[x] = 1;
    tot++;
    int _size = v[x].size();
    for (int i = 0; i <= _size - 1; i++) {
      int y = v[x][i];
      in2[y]--;
      if (!in2[y]) q.push(y);
    }
  }
  if (tot == n) return 1;
  return 0;
}
int main() {
  int n = intread();
  int m = intread();
  for (int i = 1; i <= m; i++) {
    int x = intread();
    int y = intread();
    in[y]++;
    v[x].push_back(y);
  }
  for (int i = 1; i <= n; i++) {
    in2[i] = in[i];
    if (!in[i]) q.push(i);
  }
  int cnt = 0;
  while (!q.empty()) {
    cnt++;
    int x = q.front();
    q.pop();
    int _size = v[x].size();
    for (int i = 0; i <= _size - 1; i++) {
      int y = v[x][i];
      in2[y]--;
      if (in2[y] == 0) q.push(y);
    }
  }
  if (cnt == n) {
    printf("YES\n");
  } else {
    for (int i = 1; i <= n; i++) {
      int flag = 0;
      if (in[i]) flag = solve(i, n);
      if (flag) {
        printf("YES\n");
        return 0;
      }
    }
    printf("NO\n");
  }
  return 0;
}
