#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
const int Pt = 61;
const long long G = 1e18;
long long A[MAXN + 5][MAXN + 5];
long long Odd[MAXN + 5][MAXN + 5], Even[MAXN + 5][MAXN + 5];
long long f[11][MAXN + 5][MAXN + 5][MAXN + 5];
int s[MAXN + 5];
int vis[MAXN + 5];
void Solve(int ans) {
  int L = 1;
  long long x = ans, sum = 1;
  while (sum <= G) sum = sum * x, L++;
  for (int i = 0; i <= L; i++) {
    for (int t = i; t <= L; t++) {
      for (int a = i; a <= t; a++) {
        for (int b = 0; b <= ans - i; b++) {
          f[ans][i][ans - i][t] +=
              Odd[a][i] * Even[t - a][b] * A[ans - i][b + 1] * A[t][a + 1];
        }
      }
    }
  }
}
void D_solve() {
  A[1][1] = 1;
  A[1][2] = 1, A[0][1] = 1;
  for (int i = 2; i <= 61; i++) {
    for (int j = 1; j <= i + 1; j++) A[i][j] = A[i - 1][j] + A[i - 1][j - 1];
  }
  for (int i = 1; i <= Pt; i += 2) Odd[i][1] = 1;
  Odd[0][0] = 1;
  for (int i = 2; i <= 10; i++) {
    for (int L = 1; L <= Pt; L++) {
      for (int j = 1; j <= L; j += 2)
        Odd[L][i] += Odd[L - j][i - 1] * A[L][j + 1];
    }
  }
  for (int i = 2; i <= Pt; i += 2) Even[i][1] = 1;
  Even[0][0] = 1;
  for (int i = 2; i <= 10; i++) {
    for (int L = 1; L <= Pt; L++) {
      for (int j = 2; j <= L; j += 2)
        Even[L][i] += Even[L - j][i - 1] * A[L][j + 1];
    }
  }
  for (int i = 2; i <= 10; i++) Solve(i);
}
int N;
long long b, L, R;
long long dfs(int d, int cnt, bool check, bool flag) {
  long long sum = 0;
  if (d == 0) {
    if (cnt == 0 && check) return 1;
    return 0;
  }
  if (check) {
    for (int i = 0; i <= s[d] - 1; i++) {
      int ans = cnt;
      vis[i]++;
      if (vis[i] & 1)
        ans++;
      else
        ans--;
      sum += f[b][ans][b - ans][d - 1];
      vis[i]--;
    }
    vis[s[d]]++;
    if (vis[s[d]] & 1)
      cnt++;
    else
      cnt--;
    sum += dfs(d - 1, cnt, true, false);
  } else {
    if (flag) {
      for (int i = 1; i <= s[d] - 1; i++) {
        int a = 1;
        sum += f[b][a][b - a][d - 1];
      }
      vis[s[d]]++;
      if (vis[s[d]] & 1)
        cnt++;
      else
        cnt--;
      sum += dfs(d - 1, cnt, true, false);
      sum += dfs(d - 1, 0, false, false);
    } else {
      for (int i = 1; i <= b - 1; i++) {
        int a = 1;
        sum += f[b][a][b - a][d - 1];
      }
      sum += dfs(d - 1, 0, false, false);
    }
  }
  return sum;
}
long long solve(long long a, long long x) {
  memset(vis, 0, sizeof(vis));
  int L = 0;
  while (x > 0) s[++L] = x % a, x /= a;
  return dfs(L, 0, false, true);
}
int main() {
  D_solve();
  int cnt = 0;
  scanf("%d", &N);
  while (N--) {
    scanf("%I64d %I64d %I64d", &b, &L, &R);
    long long suma = solve(b, L - 1), sumb = solve(b, R);
    printf("%I64d\n", sumb - suma);
  }
}
