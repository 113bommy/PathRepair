#include <bits/stdc++.h>
using namespace std;
const long long max_sz = 1e5 + 1;
const long long mod = 1e9 + 7;
const long long MAXN = 4e18 + 1;
char flip(char k) {
  if (k == '0') return '1';
  return '0';
}
long long sum_digit(long long n) {
  long long a = 0, i;
  for (i = n; i > 0; i = i / 10) {
    a += (i % 10);
  }
  return a;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  long long t;
  t = 1;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    long long f = 0;
    for (long long i = 0; i < n - 2; i++) {
      if (a[i] == a[i + 1] && a[i] == a[i + 2]) {
        f = 1;
        break;
      }
    }
    if (f == 1)
      cout << "NO"
           << "\n";
    else {
      cout << "YES"
           << "\n";
      vector<long long> inc, dec;
      for (long long i = 0; i < n;) {
        if (a[i] == a[i + 1]) {
          inc.push_back(a[i]);
          dec.push_back(a[i + 1]);
          i += 2;
        } else {
          inc.push_back(a[i]);
          i++;
        }
      }
      cout << inc.size() << endl;
      for (auto it : inc) cout << it << " ";
      cout << endl;
      cout << dec.size() << endl;
      sort(dec.begin(), dec.end(), greater<long long>());
      for (auto it : dec) cout << it << " ";
      cout << endl;
    }
  }
  cerr << endl
       << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC
       << "ms\n";
  return 0;
}
