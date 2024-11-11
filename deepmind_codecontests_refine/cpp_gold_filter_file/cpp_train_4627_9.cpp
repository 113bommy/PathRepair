#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, b;
  cin >> n >> b;
  int a[2010];
  for (int i = 0; i < n; ++i) cin >> a[i];
  long long res = b;
  for (int i = 0; i <= n - 2; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (a[i] < a[j])
        res =
            res > b / a[i] * a[j] + b % a[i] ? res : b / a[i] * a[j] + b % a[i];
    }
  }
  cout << res;
  return 0;
}
