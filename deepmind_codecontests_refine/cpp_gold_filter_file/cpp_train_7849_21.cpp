#include <bits/stdc++.h>
using namespace std;
const int maxn = 25 * 18 * 12 * 10 * 8;
int p[5][30];
int prime[5] = {2, 3, 5, 7, 11};
int c[5] = {1, 25, 25 * 18, 25 * 18 * 12, 25 * 18 * 12 * 10};
int m[5] = {25, 18, 12, 10, 8};
int vis[1000000];
int total;
int k;
void init() {
  p[0][0] = p[1][0] = p[2][0] = p[3][0] = p[4][0] = 1;
  for (int i = 1; i < 30; i++) {
    p[0][i] = p[0][i - 1] * 2;
    p[1][i] = p[1][i - 1] * 3;
    p[2][i] = p[2][i - 1] * 5;
    p[3][i] = p[3][i - 1] * 7;
    p[4][i] = p[4][i - 1] * 11;
  }
}
long long getnum(int x) {
  long long ans = 1;
  for (int i = 0; i < 5; i++) {
    ans *= p[i][x % m[i]];
    x /= m[i];
  }
  return ans;
}
int bitcount(int x) { return x == 0 ? 0 : bitcount(x / 2) + (x & 1); }
void bfs(int s, int st, int lim) {
  queue<int> q;
  q.push(s);
  vis[s] = 1;
  int tmp = 0;
  while (!q.empty()) {
    int t = q.front();
    q.pop();
    long long u = getnum(t);
    if (u <= (long long)2 * k * k) {
      tmp++;
      if (tmp > lim) break;
      total++;
      if (total == k) {
        printf("%d\n", (int)u);
        break;
      } else
        printf("%d ", (int)u);
      for (int i = 0; i < 5; i++)
        if (st & (1 << i)) {
          int v = t + c[i], x = u, y = 0;
          while (x % prime[i]) {
            x /= prime[i];
            y++;
          }
          if (!vis[v] && y + 1 < m[i] && v < maxn) {
            vis[v] = 1;
            q.push(v);
          }
        }
    }
  }
}
int main() {
  init();
  scanf("%d", &k);
  memset(vis, 0, sizeof(vis));
  total = 0;
  if (k < 200) {
    bfs(c[0] + c[1] + c[2], 7, k);
    if (total < k) {
      int lim = (k - total) / 3;
      bfs(c[0] + c[1], 3, lim);
      bfs(c[0] + c[2], 5, lim);
      bfs(c[1] + c[2], 6, k - total);
      for (int i = 0; i < 3; i++)
        if (total < k) bfs(c[i], (1 << i), k - total);
    }
  } else if (k < 1750) {
    bfs(c[0] + c[1] + c[2] + c[3], 15, k);
    if (total < k) {
      int l1 = (k - total) / 4;
      for (int i = 0; i < 15; i++)
        if (bitcount(i) == 3) {
          int s = 0;
          for (int j = 0; j < 4; j++)
            if (i & (1 << j)) s += c[j];
          bfs(s, i, l1);
        }
      if (total < k) {
        int l2 = (k - total) / 6;
        for (int i = 0; i < 15; i++)
          if (bitcount(i) == 2) {
            int s = 0;
            for (int j = 0; j < 4; j++)
              if (i & (1 << j)) s += c[j];
            bfs(s, i, l2);
          }
        for (int i = 0; i < 4; i++)
          if (total < k) bfs(c[i], (1 << i), k - total);
      }
    }
  } else {
    bfs(c[0] + c[1] + c[2] + c[3] + c[4], 31, k);
    if (total < k) {
      int l1 = (k - total) / 5;
      for (int i = 0; i < 31; i++)
        if (bitcount(i) == 4) {
          int s = 0;
          for (int j = 0; j < 5; j++)
            if (i & (1 << j)) s += c[j];
          bfs(s, i, l1);
        }
      if (total < k) {
        int l2 = (k - total) / 10;
        for (int i = 0; i < 31; i++)
          if (bitcount(i) == 3) {
            int s = 0;
            for (int j = 0; j < 5; j++)
              if (i & (1 << j)) s += c[j];
            bfs(s, i, l2);
          }
        if (total < k) {
          int l3 = (k - total) / 10;
          for (int i = 0; i < 31; i++)
            if (bitcount(i) == 2) {
              int s = 0;
              for (int j = 0; j < 5; j++)
                if (i & (1 << j)) s += c[j];
              bfs(s, i, l3);
            }
          for (int i = 0; i < 5; i++)
            if (total < k) bfs(c[i], (1 << i), k - total);
        }
      }
    }
  }
  return 0;
}
