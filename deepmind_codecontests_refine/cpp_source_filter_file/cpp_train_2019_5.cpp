#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n;
  long long k;
  cin >> n >> k;
  vector<long long> a;
  a.push_back(0);
  for (int i = 1; i <= n; ++i) {
    long long j;
    cin >> j;
    a.push_back(j);
  }
  int m = n;
  long long e = 0;
  int j = 2;
  int l = 1;
  for (int i = 2; i <= n; ++i) {
    long long d = e + a[l] * ((long long)(j - 2)) -
                  ((long long)(j - 1)) * ((long long)(m - j)) * a[i];
    if (d < k) {
      cout << i << endl;
      --m;
    } else {
      e += a[i - 1] * ((long long)(j - 2));
      ++j;
      l = i;
    }
  }
  return 0;
}
