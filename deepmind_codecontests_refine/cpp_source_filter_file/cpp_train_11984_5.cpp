#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;
long long fac[1] = {1}, inv[1] = {1};
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long mp(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return ret;
}
long long cmb(long long r, long long c) {
  return fac[r] * inv[c] % MOD * inv[r - c] % MOD;
}
int rn[300], cn[300], rc[300], cc[300];
queue<int> q;
string st[300][300];
string ob[300][300];
struct node {
  int a, b, c, d;
};
vector<node> ans;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> st[i][j];
      reverse((st[i][j]).begin(), (st[i][j]).end());
      for (int k = 0; k < (int)(st[i][j]).size(); k++) st[i][j][k] -= '0';
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> ob[i][j];
      reverse((ob[i][j]).begin(), (ob[i][j]).end());
      for (int k = 0; k < (int)(ob[i][j]).size(); k++) ob[i][j][k] -= '0';
      if (i && j) {
        for (int k : ob[i][j]) {
          if (!k)
            rn[j]++;
          else
            cn[i]++;
        }
      }
    }
  for (int i : st[0][0]) q.push(i);
  for (int i = 1; i < m; i++)
    for (int j : st[0][i]) q.push(j), ans.push_back({0, i, 0, 0});
  for (int i = 1; i < n; i++)
    for (int j : st[i][0]) q.push(j), ans.push_back({i, 0, 0, 0});
  for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++)
      for (int k : st[i][j]) {
        if (!k)
          rc[j]++, ans.push_back({i, j, 0, j});
        else
          cc[i]++, ans.push_back({i, j, i, 0});
      }
  int a = 0, b = 0;
  queue<int> o, z;
  for (int i = 1; i < n; i++) {
    if (cn[i] > cc[i]) o.push(i), a += cn[i] - cc[i];
  }
  for (int i = 1; i < n; i++) {
    for (; cc[i] - cn[i] && a;)
      cc[i]--, a--, q.push(1), ans.push_back({i, 0, 0, 0});
  }
  for (int i = 1; i < m; i++) {
    if (rn[i] > rc[i]) z.push(i), b += rn[i] - rc[i];
  }
  for (int i = 1; i < m; i++) {
    for (; rc[i] - rn[i] && b;)
      rc[i]--, b--, q.push(0), ans.push_back({0, i, 0, 0});
  }
  while (!q.empty()) {
    int tv = q.front();
    q.pop();
    int now;
    if (tv == 0) {
      if (z.empty())
        now = 1;
      else
        now = z.front();
      rc[now]++;
      ans.push_back({0, 0, 0, now});
      if (rc[now] == rn[now]) z.pop();
    } else {
      if (o.empty())
        now = 1;
      else
        now = o.front();
      cc[now]++;
      ans.push_back({0, 0, now, 0});
      if (cc[now] == cn[now]) o.pop();
    }
  }
  for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++) {
      for (int k : ob[i][j]) {
        if (!k)
          ans.push_back({0, j, i, j});
        else
          ans.push_back({i, 0, i, j});
      }
    }
  while (!o.empty()) o.pop();
  while (!z.empty()) z.pop();
  for (int i = 1; i < m; i++)
    if (rc[i] - rn[i]) z.push(i);
  for (int i = 1; i < n; i++)
    if (cc[i] - cn[i]) o.push(i);
  for (int i = 1; i < m; i++) {
    for (int j : ob[0][i]) {
      if (!j) {
        int now = z.front();
        if (--rc[now] == rn[now]) z.pop();
        ans.push_back({0, now, 0, 0});
      } else {
        int now = o.front();
        if (--cc[now] == cn[now]) o.pop();
        ans.push_back({now, 0, 0, 0});
      }
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j : ob[i][0]) {
      if (!j) {
        int now = z.front();
        if (--rc[now] == rn[now]) z.pop();
        ans.push_back({0, now, 0, 0});
      } else {
        int now = o.front();
        if (--cc[now] == cn[now]) o.pop();
        ans.push_back({now, 0, 0, 0});
      }
    }
  }
  for (int i = 1; i < m; i++) {
    for (int j : ob[0][i]) {
      ans.push_back({0, 0, 0, i});
    }
  }
  for (int i = n - 1; i > 0; i--) {
    for (int j : ob[i][0]) {
      ans.push_back({0, 0, i, 0});
    }
  }
  printf("%d\n", (int)(ans).size());
  for (node &i : ans)
    printf("%d %d %d %d\n", i.a + 1, i.b + 1, i.c + 1, i.d + 1);
}
