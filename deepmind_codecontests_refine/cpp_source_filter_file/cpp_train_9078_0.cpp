#include <bits/stdc++.h>
using namespace std;
const int N = 5000;
const int oo = 1e9 + 5;
int du[] = {-1, 0, 0, 1};
int dv[] = {0, -1, 1, 0};
const long long mod = 1e9 + 7;
long long sqr(long long x) { return x * x; }
int getbit(int state, int i) { return ((state >> i) & 1); }
int n, cnt[N + 5], Max[N + 5], num[N + 5], d[N + 5][N + 5];
long long res, cur;
void phantich() {
  for (int i = 2; i <= N; i++) {
    for (int j = 1; j <= N; j++) d[i][j] += d[i - 1][j];
    int tmp = i;
    for (int j = 2; j * j <= i; j++)
      if (tmp % j == 0) {
        while (tmp % j == 0) {
          d[i][j]++;
          tmp /= j;
        }
      }
    if (tmp > 1) d[i][tmp]++;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    cnt[k]++;
  }
  phantich();
  for (int i = 1; i <= N; i++) {
    if (!cnt[i]) {
      Max[i] = 1;
      continue;
    }
    for (int j = 1; j <= N; j++) {
      cur += 1ll * d[i][j] * cnt[i];
      if (d[i][j]) Max[i] = j;
    }
  }
  res = cur;
  while (*max_element(Max + 1, Max + 1 + N) > 1) {
    for (int i = 1; i <= N; i++) num[i] = 0;
    for (int i = 1; i <= N; i++) num[Max[i]] += cnt[i];
    int pos = max_element(Max + 1, Max + 1 + N) - Max;
    if (num[pos] * 2 <= n) break;
    if (pos <= 1) break;
    cur = cur + n - 2 * num[pos];
    res = min(res, cur);
    for (int i = 1; i <= N; i++) {
      if (Max[i] != pos) Max[i] = 1;
      if (Max[i] == 1) continue;
      d[i][pos]--;
      while (Max[i] > 1 && !d[i][Max[i]]) Max[i]--;
    }
  }
  cout << res;
  return 0;
}
