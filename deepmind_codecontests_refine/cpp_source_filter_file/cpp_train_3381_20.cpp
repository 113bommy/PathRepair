#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, m;
  cin >> n >> k >> m;
  n = abs(n);
  m = abs(m);
  long long p = (n + k);
  if (m < p) {
    cout << "No" << endl;
  } else {
    long long w = (m - p);
    if (w % 2 == 0) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}
