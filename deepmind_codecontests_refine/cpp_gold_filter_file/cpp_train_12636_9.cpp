#include <bits/stdc++.h>
using namespace std;
long long int n, a[3000005];
long long int beg = 1;
long long int dfs(long long int i, long long int j) {
  if (i == n + beg - 1) {
    a[n + beg] = a[n + beg - 1];
    return n + beg - 1;
  }
  if (i > n + beg - 1) return n + beg;
  a[dfs(i + j, j)] = a[i];
  return i;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) a[i] = i;
  for (int i = 2; i <= n; i++) {
    dfs(beg, i);
    beg++;
  }
  for (int i = beg; i <= n + beg - 1; i++) cout << a[i] << " ";
  cout << '\n';
  return 0;
}
