#include <bits/stdc++.h>
using namespace std;
int peri(int a, int b) { cout << (a + b) * 2; }
int main() {
  int n, i, a = pow(10, 6), j, k, p, flag = 0;
  vector<int> v;
  cin >> n;
  if (n > 1) {
    for (i = n; i < n + 10; i++) {
      for (j = 1; j <= i; j++) {
        if (i % j == 0) {
          k = i / j;
          a = min(k + j, a);
        }
      }
      v.push_back(a);
    }
    sort(v.begin(), v.end());
    cout << 2 * v[0];
  }
  if (n == 0) cout << "0";
  if (n == 1) cout << "4";
  return 0;
}
