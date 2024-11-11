#include <bits/stdc++.h>
using namespace std;
long dfs(int n, long x) {
  if (n == 0) return 1;
  long len = (1L << (n + 2)) - 3;
  if (x <= 1) return 0;
  if (x <= len / 2) return dfs(n - 1, x - 1);
  return dfs(n - 1, x - (len / 2 + 1)) + 1 + ((1L << n) - 1);
}
int main() {
  int N;
  long X;
  cin >> N >> X;
  cout << dfs(N, X) << "\n";
}
