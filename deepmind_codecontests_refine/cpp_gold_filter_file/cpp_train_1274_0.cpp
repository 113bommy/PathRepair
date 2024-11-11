#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool diff(long long x, long long y) {
    if ((x > 0 && y > 0) || (x < 0 && y < 0))
      return false;
    else
      return true;
  }
  long long findmax(long long *a, long long i, long long j, long long m) {
    if (i == j) return a[i];
    for (long long k = i; k <= j; k++) {
      m = max(m, a[k]);
    }
    return m;
  }
  long long findmin(long long *a, long long i, long long j, long long m) {
    if (i == j) return a[j];
    for (long long k = i; k <= j; k++) {
      m = max(m, a[k]);
    }
    return m;
  }
  void SolutionFunc() {
    long long n, s = 0;
    cin >> n;
    long long a[n];
    std::vector<long long> v(1, 0);
    long long x;
    cin >> x;
    a[0] = x;
    for (long long i = 1; i < n; i++) {
      cin >> a[i];
      if (diff(a[i - 1], a[i])) {
        v.push_back(i - 1);
        v.push_back(i);
      }
    }
    v.push_back(n - 1);
    long long f = 1, m = 1000000007;
    if (a[0] < 0) f = 0;
    for (long long i = 0; i < (long long)v.size(); i += 2) {
      if (f = 1) {
        s += findmax(a, v[i], v[i + 1], m * -1);
        f = 0;
      } else {
        s += findmin(a, v[i], v[i + 1], m);
        f = 1;
      }
    }
    cout << s << '\n';
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  Solution obj;
  long long T = 1;
  cin >> T;
  for (long long i = 0; i < T; i++) {
    obj.SolutionFunc();
  }
  return (0);
}
