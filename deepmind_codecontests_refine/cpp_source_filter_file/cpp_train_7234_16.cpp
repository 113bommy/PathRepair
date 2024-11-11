#include <bits/stdc++.h>
using namespace std;
int N;
const int SIZE = 100005;
int A[SIZE];
int res[SIZE];
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
    res[i] = A[i];
  }
  int now = 0;
  for (int i = 1; i <= N; i++) {
    int temp = now + 1;
    now = res[i] = min(A[i], temp);
  }
  now = 0;
  for (int i = N; i >= 1; i--) {
    int temp = now + 1;
    now = res[i] = min(A[i], temp);
  }
  int ans = 0;
  for (int i = 1; i <= N; i++)
    if (ans < res[i]) ans = res[i];
  printf("%d\n", ans);
  return 0;
}
