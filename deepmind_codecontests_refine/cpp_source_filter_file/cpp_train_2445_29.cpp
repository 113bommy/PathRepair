#include <bits/stdc++.h>
using namespace std;
long long int A, B, n;
bool can(long long int l, long long int r, long long int m, long long int t) {
  if (r - l + 1 <= m) return ((A + (r - 1) * B) <= t);
  if ((A + (r - 1) * B) > t) return false;
  long long int id = r - m;
  long long int term1 = A + (l - 1) * B;
  long long int term2 = A + (id - 1) * B;
  long long int term3 = A + (id - 1) * B;
  long long int fir = ((id - l + 1) * (term1 + term2)) / 2;
  long long int sec = ((r - l + 1) * (term1 + term3)) / 2;
  long long int thr = m * t;
  return ((thr - (sec - fir)) >= fir);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> A >> B >> n;
  while (n--) {
    long long int l, t, m;
    cin >> l >> t >> m;
    long long int low = l;
    long long int high = (t - A) / B + 2;
    long long int mid;
    long long int ans = -1;
    while (low <= high) {
      mid = (low + high) / 2;
      if (can(l, mid, m, t)) {
        ans = mid;
        low = mid + 1;
      } else
        high = mid - 1;
    }
    cout << ans << endl;
  }
  return 0;
}
