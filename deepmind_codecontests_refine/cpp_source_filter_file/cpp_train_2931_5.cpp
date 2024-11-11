#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int n1, long long int n2) {
  if (n2 != 0)
    return gcd(n2, n1 % n2);
  else
    return n1;
}
long long int power(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long int x = power(a, b / 2);
  if (b & 1) {
    return a * x * x;
  }
  return x * x;
}
const long long int PINF = numeric_limits<long long int>::max();
const long long int NINF = numeric_limits<long long int>::min();
const int SIZE = 200005;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v[7];
    for (__typeof((n)) i = (1); i <= (n); i++) {
      int num = i, j = 0;
      while (j < 7) {
        if (num & (1 << (j))) v[j].push_back(i);
        j++;
      }
    }
    int ans = 0, xx;
    for (__typeof((6)) i = (0); i <= (6); i++) {
      if ((int)v[i].size() == 0 || (int)v[i].size() == n) continue;
      cout << (int)v[i].size() << " " << n - (int)v[i].size() << " ";
      flush(cout);
      for (__typeof(((int)v[i].size() - 1)) j = (0);
           j <= ((int)v[i].size() - 1); j++) {
        cout << v[i][j] << " ";
        flush(cout);
      }
      for (__typeof((n)) k = (1); k <= (n); k++) {
        if ((k & (1 << i)) == 0) {
          cout << k << " ";
          flush(cout);
        }
      }
      cout << "\n";
      flush(cout);
      cin >> xx;
      ans = max(ans, xx);
    }
    cout << ans << "\n";
    flush(cout);
  }
}
