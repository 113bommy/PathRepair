#include <bits/stdc++.h>
#pragma warning(disable : 6031)
#pragma warning(disable : 4101)
using namespace std;
const int INF = 1e9;
const long long LINF = 1e18;
const double PI = acos(-1);
FILE* out = stdout;
FILE* in = stdin;
const int MAXN = 2005;
int n, A[MAXN];
int main() {
  scanf("%d", &n);
  n = n * 2;
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }
  sort(A, A + n);
  if (A[0] == A[n - 1]) {
    printf("-1\n");
  } else {
    for (int i = 0; i < n; i++) {
      printf("%d ", A[i]);
    }
    printf("\n");
  }
  return 0;
}
