#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const double PI = acos(-1);
const int N = 1e5 + 10;
int n, k, a[N], maxi[N], cnt = 0;
void fillup(int L, int R) {
  int curr = 1;
  for (int i = (L); i <= (R - 1); i++) a[i] = curr++;
}
void solve(int L, int R) {
  cnt++;
  if (cnt == k) {
    fillup(L, R);
    return;
  }
  if (R - L < 2) {
    a[L] = 1;
    return;
  }
  int mid = (L + R) / 2;
  cnt++;
  solve(L, mid);
  cnt--;
  solve(mid, R);
  int id1, id2, n1 = mid - L, n2 = R - mid;
  for (int i = (L); i <= (mid - 1); i++)
    if (a[i] == n1) id1 = i;
  for (int i = (mid); i <= (R - 1); i++) {
    if (a[i] == 1) id2 = i;
    a[i] += n1;
  }
  swap(a[id1], a[id2]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  maxi[1] = 1;
  for (int i = (2); i <= (n); i++)
    maxi[i] = 1 + maxi[i / 2] + maxi[(i + 1) / 2];
  if (k % 2 == 0 || k > 1 + 2 * (maxi[n] - n)) {
    cout << -1 << endl;
    return 0;
  }
  solve(0, n);
  for (int i = 0; i < (n); i++) cout << a[i] << " ";
  cout << endl;
  return 0;
}
