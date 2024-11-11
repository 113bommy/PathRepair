#include <bits/stdc++.h>
using namespace std;
long long n;
long long dfs(long long x) {
  if (x & 1) return x + 1 >> 1;
  return dfs(x + n - x / 2);
}
int main() {
  int q;
  cin >> n >> q;
  while (q--) {
    long long x;
    cin >> x;
    cout << dfs(x) << endl;
  }
  return 0;
}
