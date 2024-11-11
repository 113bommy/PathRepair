#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
long long a[N], b[N], c[N];
using namespace std;
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long l[m + 1], r[m + 1], d[m + 1];
  for (int i = 1; i < n + 1; i++) cin >> a[i];
  for (int i = 1; i < m + 1; i++) cin >> l[i] >> r[i] >> d[i];
  for (int i = 1; i < k + 1; i++) {
    int x, y;
    cin >> x >> y;
    ++c[x];
    --c[y + 1];
  }
  for (int i = 1; i < m + 1; i++) c[i] += c[i - 1];
  for (int i = 1; i < m + 1; i++) {
    b[l[i]] += c[i] * d[i];
    b[r[i] + 1] -= c[i] * d[i];
  }
  for (int i = 1; i < n + 1; i++) b[i] += b[i - 1];
  for (int i = 1; i < n + 1; i++) a[i] += b[i];
  for (int i = 1; i < n + 1; i++) cout << a[i] << " ";
  cout << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  solve();
}
