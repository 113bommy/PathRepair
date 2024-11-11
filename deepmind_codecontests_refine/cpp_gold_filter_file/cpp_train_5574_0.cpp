#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 1;
int n, m;
int t[MAX];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    int a = min(x, y), b = max(x, y);
    if (t[a] == 1 || t[b] == -1) {
      cout << 0 << '\n';
      return 0;
    }
    t[a] = -1;
    t[b] = 1;
  }
  int a1 = 0, a2 = n - 1;
  for (int i = 0; i < n; i++)
    if (t[i] == -1) a1 = i;
  for (int i = n - 1; i >= 0; i--)
    if (t[i] == 1) a2 = i;
  cout << max(0, a2 - a1) << '\n';
  return 0;
}
