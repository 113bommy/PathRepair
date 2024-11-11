#include <bits/stdc++.h>
using namespace std;
int cnt[101];
int main() {
  int n, m;
  cin >> m >> n;
  if (n - 1 >= m - n) {
    cout << max(1, n - 1);
  } else {
    cout << min(n + 1, m);
  }
  return 0;
}
