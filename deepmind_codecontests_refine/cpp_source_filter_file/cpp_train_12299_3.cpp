#include <bits/stdc++.h>
using namespace std;
typedef deque<int> deq;
int n;
long long c, d;
long long A[1000003];
char C[1000003];
int main() {
  scanf("%d %lld %lld\n", &n, &c, &d);
  for (int i = 1; i <= n; i++) {
    char c;
    long long t;
    scanf("%lld %c\n", &A[i], &C[i]);
  }
  long long end;
  scanf("%lld", &end);
  long long totres = 0;
  long long res = 1e18;
  for (int i = n; i >= 1; i--) {
    if (C[i] != C[i - 1]) {
      totres += (end - A[i]) * c;
      end = A[i];
    } else
      totres += min((end - A[i]) * c, d);
    res = min(res, totres + (i - 1) * d);
  }
  printf("%lld\n", res);
}
