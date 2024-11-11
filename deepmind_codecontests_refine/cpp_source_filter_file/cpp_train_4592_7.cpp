#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200001;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long a;
    long long b;
    cin >> a >> b;
    if (a - b != 1) {
      cout << "NO" << endl;
      continue;
    }
    long long s = a + b;
    int g = 0;
    for (long long i = 2; i <= 1000000; i++) {
      if (s % i == 0 && i < s) {
        g = 1;
      }
    }
    if (g)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
