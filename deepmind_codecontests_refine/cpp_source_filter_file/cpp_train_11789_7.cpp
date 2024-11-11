#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool mmax(T &m, const T q) {
  if (m < q) {
    m = q;
    return true;
  } else
    return false;
}
template <typename T>
bool mmin(T &m, const T q) {
  if (m > q) {
    m = q;
    return true;
  } else
    return false;
}
template <typename T>
T add(T &a, T b) {
  return (a += b) %= 1000000007;
}
template <typename T>
T sub(T &a, T b) {
  (a -= b);
  if (a < 0) a += 1000000007;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    long long c = 0;
    vector<long long> vis(n + 1);
    long long d = -1;
    for (long long i = 0; i < n; i++) {
      long long k;
      cin >> k;
      long long f = 0;
      for (long long i = 0; i < k; i++) {
        long long first;
        cin >> first;
        if (f == 0 and !vis[first]) {
          vis[first] = 1;
          c++;
          f = 1;
        }
      }
      if (f == 0) d = i + 1;
    }
    if (c == n) {
      cout << "OPTIMAL"
           << "\n";
      continue;
    }
    cout << "IMPROVED"
         << "\n";
    cout << d << " ";
    for (int i = 1; i <= n; i++)
      if (!vis[i]) {
        cout << i << "\n";
        break;
      }
  }
  return 0;
}
