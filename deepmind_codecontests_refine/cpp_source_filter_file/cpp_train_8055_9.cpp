#include <bits/stdc++.h>
using namespace std;
int A[100111], B[100111];
int main() {
  int n, m;
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < m; i++) cin >> B[i];
    sort(A, A + n);
    sort(B, B + m);
    int i = 0, j = 0;
    while (i < n && j < m) {
      if (A[i] <= B[i])
        i++, j++;
      else
        j++;
    }
    if (i >= n)
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}
