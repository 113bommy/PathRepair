#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int curr = 0;
  int res = 0;
  int a, b;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &a, &b);
    curr -= a;
    curr += b;
    res = max(res, curr);
  }
  cout << res;
  return 0;
}
