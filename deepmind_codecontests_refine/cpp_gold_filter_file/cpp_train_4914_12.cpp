#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;
const long long MOD = 998244353;
const int INF = 0x3f3f3f3f;
long long read() {
  long long x = 0, f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = -1;
  } while (ch < '0' || ch > '9');
  do {
    x = x * 10 + ch - 48;
    ch = getchar();
  } while (ch >= '0' && ch <= '9');
  return x * f;
}
int N, M;
pair<int, int> a[MAXN];
char ans[MAXN][MAXN];
void solve() {
  int maxi;
  scanf("%d", &N);
  maxi = 0;
  for (int i = 1; i <= N; i++) {
    scanf("%d", &a[i].first);
    maxi = max(maxi, a[i].first);
    a[i].second = i;
  }
  sort(a + 1, a + 1 + N);
  if (a[N - 1].first == 1) {
    maxi--;
  }
  for (int i = 0; i <= maxi; i++) {
    for (int j = 1; j <= N; j++) {
      ans[i][j] = '0';
    }
    ans[i][N + 1] = '\0';
  }
  for (int i = N; i >= 1; i--) {
    for (int j = 1, k = N - i; j <= a[i].first; j++, k++) {
      k %= maxi + 1;
      ans[k][a[i].second] = '1';
    }
  }
  printf("%d\n", maxi + 1);
  for (int i = 0; i <= maxi; i++) {
    printf("%s\n", ans[i] + 1);
  }
}
int main() {
  int T;
  T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
