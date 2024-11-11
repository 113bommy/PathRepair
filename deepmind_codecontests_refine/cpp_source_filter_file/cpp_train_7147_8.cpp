#include <bits/stdc++.h>
using namespace std;
int A[100001], B[100001], napadas[100001];
int main() {
  int n, m, x, k, i;
  cin >> n >> m;
  for (x = 1; x <= n; x++) cin >> napadas[x];
  for (x = 1; x <= n; x++) {
    cin >> k;
    A[x] = k;
    B[x] = B[x - 1];
    if (!k) B[x] += napadas[x];
  }
  k = -1, i = 0;
  for (x = 1; x <= n - m; x++) {
    int j = B[x + m - 1] - B[x - 1];
    if (j > k) {
      k = j;
      i = x;
    }
  }
  for (x = i; x < i + m; x++) A[x] = 1;
  int s = 0;
  for (x = 1; x <= n; x++) {
    if (A[x] == 1) s += napadas[x];
  }
  cout << s << endl;
  return 0;
}
