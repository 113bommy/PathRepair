#include <bits/stdc++.h>
using namespace std;
const int DIM = 1e5 + 5;
long long bit[DIM];
pair<long long, int> arr[DIM];
void upd(int p, int n, long long q) {
  for (int i = p; i <= n; i += (i & (-i))) bit[i] = max(bit[i], q);
  return;
}
long long qry(int p, int n) {
  long long q = 0;
  for (int i = p; i >= 1; i -= (i & (-i))) q = max(q, bit[i]);
  return q;
}
int main(void) {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    arr[i] = make_pair(x * x * y, i);
  }
  sort(arr + 1, arr + n + 1);
  for (int i = 1; i <= n; i++)
    upd(arr[i].second, n, qry(arr[i].second, n) + arr[i].first);
  cout << setprecision(12) << fixed << 4.0 * atan(1) * qry(n, n) << endl;
  return 0;
}
