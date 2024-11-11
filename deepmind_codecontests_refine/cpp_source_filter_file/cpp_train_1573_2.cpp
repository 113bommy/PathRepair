#include <bits/stdc++.h>
using namespace std;
inline void init() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
int main() {
  init();
  long long n;
  cin >> n;
  if (n == 1 || n == 2) {
    cout << n;
    return 0;
  }
  long long prev = 1, cur = 2;
  for (int i = 3; i <= n; ++i) {
    prev *= 2;
    cur *= 2;
    if (cur >= n) {
      cout << (i - 1);
      return 0;
    }
  }
  return 0;
}
