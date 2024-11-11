#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const long long int P = 1000000007;
const double eps = 1e-6;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  if (n < 3) {
    if (k)
      cout << -1, cout << "\n";
    else {
      for (int i = 1; i <= n; i++) cout << i << " ";
      cout << "\n";
    }
    return 0;
  }
  vector<long long int> v(n, 0);
  v[0] = 1;
  v[1] = 2;
  int prev = 0;
  int i;
  for (i = 2; i < n; i++) {
    if (i % 2 == 0) prev++;
    if (k >= prev) {
      k -= prev;
      v[i] = i + 1;
    } else
      break;
  }
  if (i >= n && k) {
    cout << -1, cout << "\n";
    return 0;
  }
  if (k) {
    int pos = i - (2 * k);
    v[i] = v[pos] + v[i - 1];
    i++;
  }
  if (i < n) {
    int mx = v[i - 1] + 1;
    long long int now = 1e9;
    for (int j = n - 1; j >= i; j--) {
      v[j] = now - mx;
      now -= mx;
    }
  }
  for (int i = 0; i < n; i++) cout << v[i] << " ";
  cerr << "\nTime elapsed : " << 1000 * clock() / CLOCKS_PER_SEC << " ms\n";
  return 0;
}
