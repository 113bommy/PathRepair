#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int A[2000];
  for (int i = 0; i < n; i++) cin >> A[i];
  sort(A, A + n);
  printf("%d", A[0] == 1 ? -1 : 1);
  return 0;
}
