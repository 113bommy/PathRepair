#include <bits/stdc++.h>
using namespace std;
const int N = 35;
int a[N];
long long dp[N];
long long C[2 * N][2 * N];
long long best;
char s[2 * N];
int suma[2 * N], sumb[2 * N];
int r, c;
map<long long, long long> mp;
void dfs(int n1, int n2, long long A, long long B) {
  long long val = abs(A - B);
  if (best <= 1 || best < val - C[n1][r] * C[n2][r]) return;
  if (n1 == r - 1 && n2 == r - 1) {
    best = min(best, val);
    return;
  }
  if (n1 >= r) dfs(n1 - 1, n2, A, B + (C[n1][r] - C[n1 - 1][r]) * C[n2][r]);
  if (n2 >= r) dfs(n1, n2 - 1, A + C[n1][r] * (C[n2][r] - C[n2 - 1][r]), B);
}
long long solve(int n1, int n2, long long A, long long B) {
  long long val = abs(A - B);
  int id = n1 + n2;
  long long hash = (A - B) * 3600 + n1 * 60 + n2;
  if (mp.find(hash) != mp.end()) return mp[hash];
  if (best < val - C[n1][r] * C[n2][r]) return mp[hash] = 0ll;
  if (n1 < r || n2 < r) {
    if (n1 >= suma[id] && n2 >= sumb[id])
      return mp[hash] = C[id - suma[id] - sumb[id]][n1 - suma[id]];
    else
      return mp[hash] = 0ll;
  }
  char c = s[id];
  if (c == 'A')
    return mp[hash] =
               solve(n1 - 1, n2, A, B + (C[n1][r] - C[n1 - 1][r]) * C[n2][r]);
  else if (c == 'B')
    return mp[hash] =
               solve(n1, n2 - 1, A + C[n1][r] * (C[n2][r] - C[n2 - 1][r]), B);
  else
    return mp[hash] =
               solve(n1 - 1, n2, A, B + (C[n1][r] - C[n1 - 1][r]) * C[n2][r]) +
               solve(n1, n2 - 1, A + C[n1][r] * (C[n2][r] - C[n2 - 1][r]), B);
}
int main() {
  scanf("%d%d", &r, &c);
  for (int i = 0; i <= 60; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  }
  long long A = 0, B = 0;
  int n1 = r + c, n2 = r + c;
  while (n1 >= r && n2 >= r) {
    if (A <= B) {
      A += C[n1][r] * (C[n2][r] - C[n2 - 1][r]);
      n2--;
    } else {
      B += (C[n1][r] - C[n1 - 1][r]) * C[n2][r];
      n1--;
    }
  }
  best = abs(A - B);
  dfs(r + c, r + c, 0ll, 0ll);
  scanf("%s", s + 1);
  for (int i = 1; i <= 2 * (r + c); i++) {
    if (s[i] == 'A')
      suma[i] = suma[i - 1] + 1;
    else
      suma[i] = suma[i - 1];
    if (s[i] == 'B')
      sumb[i] = sumb[i - 1] + 1;
    else
      sumb[i] = sumb[i - 1];
  }
  printf("%lld\n", solve(r + c, r + c, 0ll, 0ll));
  return 0;
}
