#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 70;
const int INF = 0x3f3f3f3f;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double eps = 1e-7;
const double PI = acos(-1.0);
int n, m, k;
int a[maxn];
int main() {
  while (cin >> n >> k) {
    if (k == 1) {
      cout << "! 1" << endl;
      continue;
    }
    map<int, int> M;
    for (int i = 1; i <= k + 1; i++) {
      cout << "?";
      for (int j = 1; j <= k + 1; j++) {
        if (j == i) continue;
        cout << " " << j;
      }
      cout << endl;
      int p, x;
      cin >> p >> x;
      M[x]++;
    }
    cout << "! " << M.rbegin()->second << endl;
  }
  return 0;
}
