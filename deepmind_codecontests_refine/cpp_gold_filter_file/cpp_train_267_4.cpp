#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int c, v0, v1, l, a;
  cin >> c >> v0 >> v1 >> a >> l;
  int i;
  int sum = v0;
  for (i = 1;; ++i) {
    if (sum >= c) break;
    sum += min(v1 - l, v0 + i * a - l);
  }
  cout << i;
  return 0;
}
