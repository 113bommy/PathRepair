#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
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
int N;
pair<long long, int> dis[MAXN];
int dir[MAXN];
bool cmp(pair<long long, int> a, pair<long long, int> b) {
  return a.first == b.first ? a.second < b.second : a.first > b.first;
}
void solve() {
  int M, Y;
  int now;
  scanf("%d", &N);
  M = 2;
  for (int i = 3; i <= N; i++) {
    printf("2 1 %d %d\n", M, i);
    fflush(stdout);
    scanf("%d", &now);
    if (!~now) {
      M = i;
    }
  }
  for (int i = 2; i <= N; i++) {
    if (i == M) {
      continue;
    }
    printf("1 1 %d %d\n", M, i);
    fflush(stdout);
    scanf("%lld", &dis[i].first);
    dis[i].second = i;
  }
  sort(dis + 1, dis + 1 + N, cmp);
  Y = dis[1].second;
  for (int i = 2; i <= N; i++) {
    if (i == M || i == Y) {
      continue;
    }
    printf("2 1 %d %d\n", Y, i);
    fflush(stdout);
    scanf("%d", &dir[i]);
  }
  printf("0 1 %d", M);
  for (int i = 1; i <= N; i++) {
    if (!~dir[dis[i].second]) {
      printf(" %d", dis[i].second);
    }
  }
  printf(" %d", Y);
  for (int i = 1; i <= N; i++) {
    if (dir[dis[i].second] == 1) {
      printf(" %d", dis[i].second);
    }
  }
  printf("\n");
  fflush(stdout);
}
int main() {
  int T;
  T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
