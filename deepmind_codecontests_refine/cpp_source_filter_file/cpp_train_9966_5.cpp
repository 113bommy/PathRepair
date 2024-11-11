#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
set<long long> s;
int n;
long long a[MAXN] = {0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292};
int main() {
  while (cin >> n) {
    if (n > 11)
      cout << a[11] + (n - 11) * 49 << endl;
    else
      cout << a[n] << endl;
  }
  return 0;
}
