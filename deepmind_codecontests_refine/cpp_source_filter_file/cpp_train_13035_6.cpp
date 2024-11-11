#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, s, k, x;
    cin >> n >> s >> k;
    map<int, int> make_pair;
    for (int i = 0; i < k; i++) {
      cin >> x;
      make_pair[x]++;
    }
    int f = -1;
    int res = max(s - 1, n - 3);
    for (int i = 0; i <= res; i++) {
      int p1 = s - i;
      int p2 = s + i;
      if (p1 > 0 && p1 <= n && !make_pair[p1]) {
        f = p1;
        break;
      }
      if (p2 > 0 && p2 <= n && !make_pair[p2]) {
        f = p2;
        break;
      }
    }
    cout << abs(f - s) << "\n";
  }
  return 0;
}
