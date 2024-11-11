#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k, m, l;
  cin >> n >> k >> m >> l;
  if (l == 0) {
    cout << 0;
    return 0;
  }
  if (k > n || (m + l) > n) {
    cout << -1;
    return 0;
  }
  long long v;
  if ((m + 1) % k == 0)
    v = (m + 1) / k;
  else
    v = (m + 1) / k + 1;
  if (k * v > n) {
    cout << -1;
    return 0;
  }
  cout << v;
  return 0;
}
