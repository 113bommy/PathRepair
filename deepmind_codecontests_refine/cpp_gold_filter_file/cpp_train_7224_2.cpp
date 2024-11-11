#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<int> A(n), B(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    A[a] = 1;
    B[b] = 1;
  }
  int res = 0;
  for (int i = 1; i < n - 1; i++)
    if (A[i] == 0) res++;
  for (int i = 1; i < n - 1; i++) {
    if (n % 2 == 1 && i == n - i - 1) {
      if (B[i] == 0 && A[i] == 1) res++;
    } else if (B[i] == 0)
      res++;
  }
  cout << res << '\n';
  return 0;
}
