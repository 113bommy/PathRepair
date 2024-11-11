#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000100;
const int INF = 1e9 + 10;
char s[10];
int cnt[10];
bool cmp(int a, int b) { return a > b; }
int solve() {
  int n = 0;
  while (n < 6 && cnt[n]) n++;
  if (n == 1) return 1;
  if (n == 6) return 30;
  if (n == 2) return cnt[0] == 5 ? 1 : 2;
  if (n == 3) {
    if (cnt[0] == 4) return 2;
    if (cnt[0] == 3) return 3;
    return 6;
  }
  if (n == 4) return cnt[0] == 3 ? 5 : 8;
  if (n == 5) return 15;
}
int main() {
  while (~scanf("%s", s)) {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < 6; i++) {
      if (s[i] == 'R') cnt[0]++;
      if (s[i] == 'O') cnt[1]++;
      if (s[i] == 'Y') cnt[2]++;
      if (s[i] == 'G') cnt[3]++;
      if (s[i] == 'B') cnt[4]++;
      if (s[i] == 'V') cnt[5]++;
    }
    sort(cnt, cnt + 6, cmp);
    printf("%d\n", solve());
  }
  return 0;
}
