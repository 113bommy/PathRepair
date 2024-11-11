#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
const int MAX = 3e5 + 10;
int A[MAX];
int C[MAX];
int n, m;
int red(int x) {
  if (x >= m) return x - m;
  return x;
}
int possible(int x) {
  if (x == m - 1) return 1;
  for (int i = 1; i <= n; i++) {
    int plus = red(A[i] + x);
    if (plus >= A[i]) {
      if (plus < C[i - 1])
        return 0;
      else
        C[i] = max(A[i], C[i - 1]);
    } else {
      if (plus >= C[i - 1]) {
        C[i] = C[i - 1];
      } else
        C[i] = max(A[i], C[i - 1]);
    }
  }
  return 1;
}
int main() {
  scanf("%d %d", &n, &m);
  int busted = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &A[i]);
    if (i > 1 && A[i] < A[i - 1]) busted = 1;
  }
  if (busted == 0) {
    printf("0\n");
    return 0;
  }
  int high = m - 1;
  int low = 0;
  while (possible(high - 1)) {
    int cen = (high + low) / 2;
    if (possible(cen))
      high = cen;
    else
      low = cen;
  }
  printf("%d\n", high);
}
