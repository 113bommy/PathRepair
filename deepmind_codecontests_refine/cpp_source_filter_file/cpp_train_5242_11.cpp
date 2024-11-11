#include <bits/stdc++.h>
using namespace std;
const int oo = 0x7fffffff;
const long long OO = 1000000000000000000LL;
const int base = 1000000007;
const int dx[] = {1, 0, 0, -1};
const int dy[] = {0, 1, -1, 0};
int x;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> x;
  if (x == 2) {
    cout << 2 << endl;
    return 0;
  }
  if (x == 3) {
    cout << 5;
    return 0;
  }
  for (int n = 1;; n += 2) {
    int count = (n / 2 + 1) * (n / 2 + 1) + (n / 2) * (n / 2);
    if (count >= x) {
      cout << n;
      return 0;
    }
  }
  return 0;
}
