#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, i;
  vector<long long> v;
  for (i = 1; i <= 10000; i++) {
    t = i;
    long long c = 0;
    vector<long long> s;
    while (t > 0) {
      long long r = t % 10;
      s.push_back(r);
      t /= 10;
      c++;
    }
    for (long long j = c - 1; j >= 0; j--) {
      v.push_back(s[j]);
    }
  }
  long long n;
  cin >> n;
  cout << v[n - 1] << endl;
  return 0;
}
