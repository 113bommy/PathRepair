#include <bits/stdc++.h>
using namespace std;
const int MAXM = 100005;
const double EPSILON = 0.001;
int n, m;
long long q[MAXM], w[MAXM];
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) cin >> q[i] >> w[i];
  sort(w, w + m, greater<int>());
  int even, odd;
  even = sqrt(2 * n) + EPSILON;
  odd = (sqrt(8 * n - 7) + 1) / 2 + EPSILON;
  if (even % 2) even--;
  if (!(odd % 2)) odd--;
  long long r = min(n, max(even, odd));
  long long ans = 0;
  for (int i = 0; i < r; i++) ans += w[i];
  cout << ans << endl;
}
