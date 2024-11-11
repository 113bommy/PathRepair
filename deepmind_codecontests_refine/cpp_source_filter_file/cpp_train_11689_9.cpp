#include <bits/stdc++.h>
using namespace std;
long long N;
long long A[3], B[3];
int op[6][2] = {{0, 0}, {0, 2}, {1, 1}, {1, 0}, {2, 2}, {2, 1}};
bool ud[6];
long long ans;
long long ansnow;
void DFS(int dp) {
  if (dp >= 6) {
    ansnow = 0;
    for (int i = 0; i < 3; i++) {
      ansnow += min(A[i], B[i + 1]);
    }
    ans = min(ans, ansnow);
    return;
  }
  int u;
  for (int i = 0; i < 6; i++) {
    if (ud[i]) continue;
    ud[i] = true;
    u = min(A[op[i][0]], B[op[i][1]]);
    A[op[i][0]] -= u;
    B[op[i][1]] -= u;
    DFS(dp + 1);
    A[op[i][0]] += u;
    B[op[i][1]] += u;
    ud[i] = false;
  }
}
int main() {
  scanf("%lld", &N);
  for (int i = 0; i < 3; i++) {
    scanf("%lld", &A[i]);
  }
  for (int i = 0; i < 3; i++) {
    scanf("%lld", &B[i]);
  }
  long long mn, mx;
  mn = mx = 0;
  for (int i = 0; i < 3; i++) {
    mx += min(A[i], B[(i + 1) % 3]);
  }
  ans = mx;
  DFS(0);
  mn = ans;
  printf("%lld %lld\n", mn, mx);
  return 0;
}
