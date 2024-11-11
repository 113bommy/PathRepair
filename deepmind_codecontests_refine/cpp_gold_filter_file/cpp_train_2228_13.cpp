#include <bits/stdc++.h>
using namespace std;
int main() {
  int A[2000];
  int n, m;
  cin >> n >> m;
  int min = INT_MAX;
  for (int i = 1; i <= m; i++) {
    cin >> A[i];
  }
  sort(A + 1, A + m + 1);
  for (int i = 1; i <= m - n + 1; i++) {
    if (min > abs(A[i] - A[n + i - 1])) {
      min = abs(A[i] - A[n + i - 1]);
    }
  }
  printf("%d\n", min);
  return 0;
}
