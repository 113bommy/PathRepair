#include <bits/stdc++.h>
using namespace std;
const long double eps = 1E-2;
const int pinf = 1E+9;
const int minf = 1E-9;
template <typename T>
inline T sqr(T _k) {
  return _k * _k;
}
int main(int argc, char **argv) {
  ios_base::sync_with_stdio(false);
  long long n, min = 10000000000LL;
  cin >> n;
  vector<long long> v(n + 1);
  vector<long long> mins(n + 1);
  for (int i = 1; i <= n; ++i) cin >> v[i];
  for (int i = n; i > 0; --i) mins[i] = std::min(min, v[i]), min = mins[i];
  long long l, r, mid = (1 + n) / 2;
  for (int i = 1; i <= n; ++i) {
    l = i + 1;
    r = n;
    while (l < r) {
      mid = (l + r + 1) / 2;
      if (mins[mid] < v[i])
        l = mid;
      else
        r = mid - 1;
    }
    if (mins[mid] >= v[i])
      if (mins[mid - 1] < v[i] && i < mid - 1)
        cout << mid - i - 2;
      else
        cout << -1;
    else if (i < mid)
      cout << mid - i - 1;
    else
      cout << -1;
    cout << ' ';
  }
  return 0;
}
