#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v;
    for (long long i = 0; i < n; i++) {
      long long x;
      cin >> x;
      v.push_back(x);
    }
    long long x = 0, a = 0, b = 0, i = 0, j = n - 1;
    long long tota = 0, totb = 0, c = 0, flag = 0, q = 0;
    if (i == j) {
      cout << 1 << " " << v[i] << " " << 0 << endl;
      q = 1;
    }
    while (i <= j && q != 1) {
      if (x == 0) {
        while (a <= b) {
          if (i > j) {
            flag = 1;
            break;
          }
          a += v[i];
          i++;
        }
        b = 0;
        tota += a;
        if (a > 0) c++;
        x = 1;
      }
      if (flag == 1) break;
      if (x == 1) {
        while (b <= a) {
          if (j < i) {
            flag = 1;
            break;
          }
          b += v[j];
          j--;
        }
        a = 0;
        totb += b;
        if (b > 0) c++;
        x = 0;
      }
      if (flag == 1) break;
    }
    if (q != 1) cout << c << " " << tota << " " << totb << endl;
  }
}
