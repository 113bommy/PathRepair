#include <bits/stdc++.h>
using namespace std;
int A[2222];
int main() {
  int d, n, i;
  for (scanf("%d %d", &d, &n), i = 0; i < n; scanf("%d", &A[i++]))
    ;
  long long res = 0;
  for (i = 1; i < n; i++) res += d - (A[i] + 1) + 1;
  cout << res << endl;
  return 0;
}
