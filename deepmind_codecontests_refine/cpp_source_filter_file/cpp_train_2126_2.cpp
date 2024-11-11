#include <bits/stdc++.h>
using namespace std;
int N, K;
int a[200010];
int low[200010], high[200010];
int ans[200010];
bool check(void) {
  int i, j;
  if (K <= 0) return false;
  for ((i) = 0; (i) < (int)(N); (i)++)
    if (a[i] >= K) return false;
  for ((i) = 0; (i) < (int)(K + 1); (i)++) low[i] = 0;
  for ((i) = 0; (i) < (int)(K + 1); (i)++) high[i] = N;
  high[0] = 0;
  low[K] = N;
  for ((i) = 0; (i) < (int)(N); (i)++)
    if (a[i] != -1) {
      high[a[i]] = min(high[a[i]], i);
      low[a[i] + 1] = max(low[a[i] + 1], i + 1);
    }
  for ((i) = 0; (i) < (int)(K); (i)++) low[i + 1] = max(low[i + 1], low[i] + 2);
  for (i = K; i >= 1; i--) low[i - 1] = max(low[i - 1], low[i] - 5);
  for ((i) = 0; (i) < (int)(K + 1); (i)++)
    if (low[i] > high[i]) return false;
  for ((i) = 0; (i) < (int)(K); (i)++)
    for (j = low[i]; j < low[i + 1]; j++) ans[j] = i + 1;
}
void print(void) {
  int i;
  cout << K << endl;
  for ((i) = 0; (i) < (int)(N); (i)++) {
    printf("%d", ans[i]);
    if (i == N - 1)
      printf("\n");
    else
      printf(" ");
  }
}
int main(void) {
  int i;
  cin >> N;
  for ((i) = 0; (i) < (int)(N); (i)++) scanf("%d", &a[i]);
  for ((i) = 0; (i) < (int)(N); (i)++) a[i]--;
  for (i = N - 1; i >= 0; i--)
    if (a[i] != -1) break;
  int used = ((i == -1) ? 0 : (a[i] + 1));
  int K2 = used + (N - i) / 5;
  for (i = -3; i <= 3; i++) {
    K = K2 + i;
    if (check()) {
      print();
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
