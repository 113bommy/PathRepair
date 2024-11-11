#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  vector<long double> a;
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    long double j;
    cin >> j;
    a.push_back(j);
  }
  sort(a.begin(), a.end());
  long double s = 1001;
  for (long long i = 0; i < m - n + 1; i++) {
    long double b = abs(a[i] - a[i + n - 1]);
    if (b < s) {
      s = b;
    }
  }
  cout << s << endl;
  return 0;
}
