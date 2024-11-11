#include <bits/stdc++.h>
using namespace std;
int m, n, j, k, l, i, o, p, __t, mod;
long long step[700][700], In[700], Out[700], Repre[700], In_num, Out_num;
int L[700 * 700], op, ed, inque[700], deg[700];
long long Way[700];
char ch;
void read(int &a) {
  for (ch = getchar(); (ch < '0' || ch > '9') && (ch != '-'); ch = getchar())
    ;
  if (ch == '-')
    a = 0, __t = -1;
  else
    a = ch - '0', __t = 1;
  for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar())
    a = a * 10 + ch - '0';
  a *= __t;
}
struct matrix {
  long long M[700][700];
  void set(int x, int y, int a) { M[x][y] = a; }
  void swap_line(int a, int b) {
    for (int i = (1); i <= (In_num); i++) swap(M[a][i], M[b][i]);
  }
  void solve() {
    long long ans = 1;
    for (int i = (1); i <= (In_num); i++) {
      bool find = 0;
      for (int j = (i); j <= (In_num); j++)
        if (M[j][i] != 0) {
          find = 1;
          swap_line(i, j);
          if (i != j) ans *= -1;
          break;
        }
      for (int j = (i + 1); j <= (In_num); j++)
        if (M[j][i] != 0) {
          for (; M[j][i] != 0;) {
            if (abs(M[j][i]) < abs(M[i][i])) swap_line(i, j), ans *= -1;
            long long dec = M[j][i] / M[i][i];
            for (int k = (i); k <= (In_num); k++)
              M[j][k] = (M[j][k] - M[i][k] * dec) % mod;
          }
        }
      ans = (ans * M[i][i]) % mod;
    }
    cout << (ans + mod) % mod << endl;
  }
} mat;
int main() {
  read(m), read(n), read(mod);
  for (int i = (1); i <= (n); i++) {
    read(j), read(k);
    step[j][k]++;
    Out[j]++;
    In[k]++;
  }
  for (int i = (1); i <= (m); i++)
    if (Out[i] == 0) Repre[i] = ++In_num;
  for (int i = (1); i <= (m); i++)
    if (In[i] == 0) {
      memset(Way, 0, sizeof Way);
      memset(inque, 0, sizeof inque);
      Way[i] = 1;
      inque[L[op = ed = 1] = i] = 1;
      ++Out_num;
      n = 0;
      for (int now = L[ed]; ed <= op; ed++, now = L[ed])
        for (int def = (1); def <= (m); def++)
          if (step[now][def] > 0)
            if (!inque[def]) inque[L[++op] = def] = 1;
      for (int i = 1; i <= op; i++) {
        for (int j = (1); j <= (m); j++)
          if (inque[j] && j != i && step[L[i]][j]) deg[L[i]]++;
        if (deg[L[i]] == 0) L[++n] = L[i];
      }
      for (op = n, ed = 1; ed <= op; ed++) {
        int now = L[ed];
        for (int i = (1); i <= (m); i++)
          if (inque[i] && deg[i] > 0 && step[i][now] > 0) {
            deg[i]--;
            if (deg[i] == 0) L[++op] = i;
          }
      }
      for (int i = op; i; i--)
        for (int j = (1); j <= (m); j++)
          if (step[L[i]][j])
            Way[j] = (Way[j] + step[L[i]][j] * Way[L[i]]) % mod;
      for (int j = (1); j <= (m); j++)
        if (Repre[j] != 0) mat.set(Out_num, Repre[j], Way[j]);
    }
  mat.solve();
}
