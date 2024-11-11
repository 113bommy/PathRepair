#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100, D = 26;
char s[N];
int pr[N][D], nt[N][D], pref[N][D], suf[N][D], sum[N];
bool used[D + 1];
int calc(int l, int r) {
  if (l > r) return 0;
  fill(used, used + D + 1, 0);
  for (int i = 0; i < 26; i++) {
    int x = nt[l][i], y = pr[r][i];
    if (x <= r) {
      used[sum[y] ^ sum[x] ^ suf[l][i] ^ pref[r][i]] = 1;
    }
  }
  int t = 0;
  while (used[t]) t++;
  return t;
}
int main() {
  scanf(" %s", s);
  int n = strlen(s);
  for (int i = n; i > 0; i--) s[i] = s[i - 1] - 'a';
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < D; j++) {
      pr[i][j] = pr[i - 1][j];
    }
    pr[i][s[i]] = i;
  }
  fill(nt[n + 1], nt[n + 1] + D, n + 1);
  for (int i = n; i > 0; i--) {
    for (int j = 0; j < D; j++) {
      nt[i][j] = nt[i + 1][j];
    }
    nt[i][s[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[pr[i - 1][s[i]]] ^ pref[i - 1][s[i]];
    for (int j = i - 1; j > pr[i - 1][s[i]]; j--) {
      suf[j][s[i]] = calc(j, i - 1);
    }
    vector<pair<int, int>> v;
    for (int j = 0; j < D; j++) {
      if (pr[i][j] != j) v.push_back({pr[i][j] + 1, j});
    }
    sort(v.rbegin(), v.rend());
    for (auto p : v) {
      pref[i][p.second] = calc(p.first, i);
    }
  }
  int m;
  scanf("%d", &m);
  while (m--) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%s\n", calc(l, r) ? "Alice" : "Bob");
  }
  return 0;
}
