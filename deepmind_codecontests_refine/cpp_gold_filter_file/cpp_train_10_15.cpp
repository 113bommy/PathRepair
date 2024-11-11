#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAXM = 1000005;
const double EPS = 1e-8;
const int INT_INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
int main() {
  int q;
  cin >> q;
  int l, r, num;
  while (q--) {
    cin >> l >> r >> num;
    if (num < l) {
      cout << num << endl;
    } else if (num > r) {
      cout << num << endl;
    } else {
      cout << (r / num + 1) * num << endl;
    }
  }
  return 0;
}
