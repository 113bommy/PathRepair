#include <bits/stdc++.h>
using namespace std;
const int MAX_N = (int)1e6 * 2 + 10;
int a[MAX_N], n, ans, x;
void work() {
  ans = 0;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    a[x] = x;
  }
  for (int i = 0; i < MAX_N; ++i) {
    if (a[i] != i) {
      a[i] = a[i - 1];
    }
  }
  for (int i = 2; i < MAX_N; ++i) {
    if (a[i] == i) {
      for (int j = i + i - 1; j < MAX_N; j += i) {
        if (a[j] % i > ans && a[j] > i) {
          ans = a[j] % i;
        }
      }
    }
  }
  cout << ans << endl;
}
int main() {
  while (cin >> n) {
    work();
  }
  return 0;
}
