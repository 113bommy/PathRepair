#include <bits/stdc++.h>
using namespace std;
int A[1000010];
int main() {
  int n;
  while (cin >> n) {
    int ans = n - 1, l = 1, r = n;
    while (l < r) {
      A[l++] = A[r--] = ans;
      ans -= 2;
    }
    if (l == r) A[l] = n;
    l = n + 1;
    r = 2 * n - 1;
    ans = n - 2;
    while (l < r) {
      A[l++] = A[r--] = ans;
      ans -= 2;
    }
    if (l == r) A[l] = n;
    A[2 * n] = n;
    for (int i = (1); i <= (n + n); i++)
      printf("%d%c", A[i], i == n + n ? '\n' : ' ');
  }
  return 0;
}
