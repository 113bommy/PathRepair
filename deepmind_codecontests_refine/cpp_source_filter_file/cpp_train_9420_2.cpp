#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n;
int len[N];
int energy[N];
int dp[N];
int cnt[N];
int f[N];
vector<int> graf[N];
void load() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &len[i]), cnt[len[i]]++;
  for (int i = 0; i < n; i++) {
    scanf("%d", energy + i);
    dp[len[i]] += energy[i];
    graf[len[i]].push_back(energy[i]);
  }
}
void solve() {
  int sol = 2 * 1000 * 1000;
  for (int i = 1; i < N; i++) dp[i] += dp[i - 1];
  for (int i = 1; i < N; i++) {
    if (cnt[i] == 0) continue;
    int curr = dp[N - 1] - dp[i];
    int howmuch = cnt[i];
    int ima = 0;
    for (int j = 1; j <= 200; j++) ima += f[j];
    int ptr = 1;
    if (howmuch <= ima) {
      for (int j = 1; j <= 200 && howmuch <= ima; j++) {
        if (f[j] == 0) continue;
        if (howmuch > ima - f[j]) {
          curr += j * (ima - (howmuch - 1));
          break;
        } else {
          ima -= f[j];
          curr += f[j] * j;
        }
      }
    }
    sol = min(sol, curr);
    for (int j = 0; j < graf[i].size(); j++) {
      f[graf[i][j]]++;
    }
  }
  printf("%d\n", sol);
}
int main(void) {
  load();
  solve();
  return 0;
}
