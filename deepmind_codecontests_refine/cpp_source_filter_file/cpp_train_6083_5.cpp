#include <bits/stdc++.h>
using namespace std;
int main() {
  int test;
  cin >> test;
  for (int tst = 1; tst <= test; ++tst) {
    int n, p, cnt;
    cin >> n >> p;
    for (int i = 1; i <= n - 1; ++i)
      for (int j = i + 1; j <= n; ++j)
        if (cnt < n + n + p) {
          cout << i << " " << j << endl;
          ++cnt;
        }
  }
  return 0;
}
