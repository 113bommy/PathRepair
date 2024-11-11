#include <bits/stdc++.h>
long long mod = 1e9 + 7;
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  int tot = (n * (n - 1)) / 2;
  if (tot <= k) return cout << "no solution", 0;
  for (int i = 0; i < n; i++) cout << 0 << ' ' << i << '\n';
  return 0;
}
