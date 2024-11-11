#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int t(0);
  for (int a = 0; a * a <= n && a <= m; a++) {
    int b = n * n - a;
    if (a + b * b == m) t++;
  }
  cout << t << endl;
  return (0);
}
