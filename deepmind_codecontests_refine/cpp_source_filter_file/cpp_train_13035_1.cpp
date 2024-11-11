#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    long long n, s, k;
    cin >> n >> s >> k;
    set<long long> lz;
    for (int j = 0; j < k; j++) {
      long long x;
      cin >> x;
      lz.insert(x);
    }
    for (long long j = 0; j <= n / 2; j++) {
      if ((s + j <= n) && (lz.find(s + j) == lz.end())) {
        cout << j << endl;
        break;
      }
      if ((s - j >= 1) && (lz.find(s - j) == lz.end())) {
        cout << j << endl;
        break;
      }
    }
  }
  return 0;
}
