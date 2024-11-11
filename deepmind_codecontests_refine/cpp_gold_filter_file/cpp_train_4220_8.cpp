#include <bits/stdc++.h>
const int kMaxN = 5, kMaxM = 100000, kMaxP = 1 << kMaxN;
long long h[kMaxM - 1][kMaxP], c[kMaxM - 1][kMaxP];
int h_valid[kMaxM - 1], c_valid[kMaxM - 1];
int join[kMaxP][kMaxP];
int n, m, pn, state;
void ReadIn() {
  static int first_bit[kMaxP];
  static int val[5];
  scanf("%d%d", &n, &m);
  pn = 1 << n;
  state = pn - 1;
  first_bit[0] = -1;
  for (int i = 1; i < pn; ++i)
    for (int j = 0; j < n; ++j)
      if ((i >> j) & 1) first_bit[i] = j;
  for (int i = 0; i < m - 1; ++i) {
    h_valid[i] = 0;
    for (int j = 0; j < n; ++j) {
      scanf("%d", &val[j]);
      if (val[j] > 0) h_valid[i] |= 1 << j;
    }
    h[i][0] = 0;
    for (int j = 1; j < pn; ++j)
      h[i][j] = h[i][j - (1 << first_bit[j])] + val[first_bit[j]];
  }
  for (int i = 0; i < n; ++i) scanf("%*d");
  for (int i = 0; i < m - 1; ++i) {
    c_valid[i] = 0;
    for (int j = 0; j < n; ++j) {
      scanf("%d", &val[j]);
      if (val[j] > 0) c_valid[i] |= 1 << j;
    }
    c[i][0] = 0;
    for (int j = 1; j < pn; ++j)
      c[i][j] = c[i][j - (1 << first_bit[j])] + val[first_bit[j]];
  }
  static bool used[5];
  static std::queue<int> q;
  for (int i = 0; i < pn; ++i)
    for (int j = 0; j < pn; ++j) {
      memset(used, false, sizeof(used));
      int next = 0;
      for (int k = 0; k < n; ++k)
        if ((i >> k) & 1) q.push(k);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        next |= 1 << u;
        if (((j >> u) & 1) && !used[(u + 1) % n]) {
          q.push((u + 1) % n);
          used[q.back()] = true;
        }
        if (((j >> ((u - 1 + n) % n)) & 1) && !used[(u - 1 + n) % n]) {
          q.push((u - 1 + n) % n);
          used[q.back()] = true;
        }
      }
      join[i][j] = next;
    }
}
long long mem[2][kMaxP];
void Solve() {
  long long *now = mem[0], *next = mem[1];
  int end;
  memset(now, -1, kMaxP * sizeof(long long));
  now[state] = 0;
  for (int i = 0; i < m - 1; ++i) {
    memset(next, -1, kMaxP * sizeof(long long));
    for (int j = 0; j < pn; ++j) {
      if (now[j] == -1) continue;
      for (int k = 0; k < pn; ++k) {
        end = j & h_valid[i] & k;
        if (next[end] == -1 || next[end] > now[j] + h[i][state ^ k])
          next[end] = now[j] + h[i][state ^ k];
      }
    }
    std::swap(now, next);
    memset(next, -1, kMaxP * sizeof(long long));
    for (int j = 0; j < pn; ++j) {
      if (now[j] == -1) continue;
      for (int k = 0; k < pn; ++k) {
        end = join[j][k & c_valid[i]];
        if (next[end] == -1 || next[end] > now[j] + c[i][state ^ k])
          next[end] = now[j] + c[i][state ^ k];
      }
    }
    std::swap(now, next);
  }
  printf("%I64d\n", now[0]);
}
int main() {
  ReadIn();
  Solve();
  return 0;
}
