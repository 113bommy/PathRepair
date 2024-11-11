#include <bits/stdc++.h>
using namespace std;
void cass() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int N = 1e5 + 6;
int n, m;
int a[N];
int main() {
  cass();
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int x, y, z;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y >> z;
    int numStrictLess = 0;
    for (int i = x; i <= y; i++)
      if (a[i] < a[z]) numStrictLess++;
    if (numStrictLess != z - x)
      cout << "NO" << '\n';
    else
      cout << "YES" << '\n';
  }
}
