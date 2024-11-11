#include <bits/stdc++.h>
using namespace std;
int N, R, C;
string arr[1000100];
int best[1000100];
int dp[1000100][22];
int main() {
  scanf("%d%d%d", &N, &R, &C);
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
  }
  int r = 1;
  int cur = (int)arr[1].size() + 1;
  for (int i = 1; i <= N; i++) {
    while (r <= N && cur <= C + 1) {
      r++;
      if (r != N + 1) cur += arr[r].size() + 1;
    }
    best[i] = r;
    cur -= (arr[i].size() + 1);
  }
  for (int i = 1; i <= N; i++) {
    dp[i][0] = best[i];
  }
  for (int i = 1; i <= log2(N); i++) {
    for (int j = 1; j <= N; j++) {
      dp[j][i] = dp[dp[j][i - 1]][i - 1];
    }
  }
  int beg = 1;
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    int node = i;
    for (int j = 0; j <= log2(R); j++) {
      if ((1 << j) & R) {
        node = dp[node][j];
      }
    }
    if (ans < node - i) {
      ans = node - i;
      beg = i;
    }
  }
  cur = beg;
  int nx = best[beg];
  for (int i = 1; i <= R; i++) {
    if (nx == cur) break;
    for (int j = cur; j < nx; j++) {
      cout << arr[j];
      if (j != nx - 1) printf(" ");
    }
    printf("\n");
    cur = best[cur];
    nx = best[nx];
  }
}
