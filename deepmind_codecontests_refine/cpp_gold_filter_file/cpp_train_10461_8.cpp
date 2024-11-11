#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n, w, i, ans, q = 0;
  cin >> k >> n >> w;
  for (i = 1; i <= w; i++) {
    q += i * k;
  }
  ans = q - n;
  cout << max(0, ans);
  return 0;
}
