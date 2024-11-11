#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    map<long long, long long> m;
    long long i;
    long long n;
    cin >> n;
    long long a[n];
    long long one = 0;
    long long two = 0;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      long long x = a[i] % 3;
      m[x]++;
    }
    long long an = 0;
    if (m[2] > m[1]) {
      an = m[1];
      an += m[0];
      an += (m[2] - m[1]) / 3;
    } else {
      an = m[2];
      an += m[0];
      an += (m[1] - m[2]) / 3;
    }
    cout << an << endl;
  }
}
