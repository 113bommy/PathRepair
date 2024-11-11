#include <bits/stdc++.h>
using namespace std;
int GCD(int a, int b) {
  while (b) b ^= a ^= b ^= a %= b;
  return a;
}
int dx[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dxKnightMove[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dyKnightMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
inline int src() {
  int ret;
  scanf("%d", &ret);
  return ret;
}
int N;
int t[5000 + 7];
int freq[5000 + 7];
int ans[5000 + 7];
int main() {
  int i, j, k;
  int TC, tc;
  double cl = clock();
  while (cin >> N) {
    for (int i = (int)0; i <= (int)N - 1; i++) scanf("%d", &t[i]);
    memset(ans, 0, sizeof ans);
    for (int i = (int)0; i <= (int)N - 1; i++) {
      memset(freq, 0, sizeof freq);
      int maxFreq = 0, lowT = -1;
      for (int j = (int)i; j <= (int)N - 1; j++) {
        int f = ++freq[t[j]];
        if (f > maxFreq || (f == maxFreq && t[j] < lowT)) {
          maxFreq = f;
          lowT = t[j];
        }
        ans[lowT]++;
      }
    }
    for (int i = (int)1; i <= (int)N; i++) printf("%d ", ans[i]);
    printf("\n");
  }
  cl = clock() - cl;
  fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);
  return 0;
}
