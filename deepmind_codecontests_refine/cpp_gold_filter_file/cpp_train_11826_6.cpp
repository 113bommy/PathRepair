#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1, M = 1e8, OO = 2000000007;
int n, A[N], ans, mini = OO;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", A + i);
  }
  sort(A, A + n);
  for (int i = 0; i < n - 1; ++i) mini = min(mini, A[i + 1] - A[i]);
  for (int i = 0; i < n; ++i) {
    ans += binary_search(A + i + 1, A + n, A[i] + mini);
  }
  printf("%d %d\n", mini, ans);
  return 0;
}
